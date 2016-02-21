#include "gameengine.h"
#include "player.h"
#include "utilities.h"
#include "event.h"

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>

GameEngine::GameEngine(){
	roundNum = 1;
	playersNum = 0;
	eventNum = 0;
	loadScenarios(12);
	loadEvents(24);
};


GameEngine::GameEngine(int pNum){
	roundNum = 1;
	playersNum = pNum;
	eventNum = 0;
	loadScenarios(12);
	loadEvents(12);
};

GameEngine::~GameEngine(){
	delete [] players;
};

void GameEngine::displayIntro(){
	std::string intro = "";
	intro += "Hello. Welcome to the Statera. \n" ;
	
	std::cout << intro;

};

void GameEngine::getPlayersNum(){
	std::string request = "Please enter the number of players (2 to 4).";
	std::string input = getUserInput(request, buildValidResInts(2, 4));
	playersNum = atoi(input.c_str());
	
	
};

//gets players names and beginning distibution of attirubtes and make the corresponding player objects
void GameEngine::getPlayersStats(){
	std::string attributesNames[5] = {"Body", "Mind", "Social", "School", "Money"} ;
	int count = 0;
	std::string input;
	std::cout << "Please enter the name of player 1. \n";
	while (std::getline(std::cin, input)){
		players[count] = new Player(input);
			
		std::cout << "You have 14 points to distribute between the five life attributes. \n";
		int points = 0;
			for (int i = 0; i < 5; i++){
				std::string request = "Enter an integer from 0 to 5 for the attribute " + players[count]->attributes[i]->getName() + ":";
				//Check
				input = getUserInput(request, buildValidResInts(0,5));
				int inputPoints = atoi(input.c_str());
				players[count]->attributes[i]->setValue(inputPoints);
				points += inputPoints;
				if (points > 14) { std::cout << "You have too many points. ERROR";
				} //TODO go back
				else {
				} //missing else
		//Check if at the end there are 14 points
		}
		count++;
		if (count >= playersNum){
			break;
		}
		std::cout << "Please enter the name of player " + std::to_string(count + 1) + ". \n" ;
		
	}
};

//displays the winner's name and their score. The player with the lowest score is the winner.
void GameEngine::getWinner(){
	int wScore = 400; //some big number
	std::string winner = "";
	for (int i = 0; i < playersNum; i++) {
		int pScore = players[i]->getScore();
		if (pScore < wScore){
			wScore = pScore;
			winner = players[i]->getName();
		} 	
	}

	//Check if another player has the lowest score as well. If so then take the average. The highest average is the winner.
	int lowest[4]  = {}; //an array of 0's
	for (int i = 0; i < playersNum; i++) {
		int pScore = players[i]->getScore();
		if ( wScore == pScore){
			lowest[i] = 1;
		} 	
	}

	int count = std::count (lowest, lowest+4, 1);
	if (count == 1) {
		std::cout << "The winner is " << winner << " with the score of " << wScore << "." << std::endl; 
	} else {
		float hAvg = 0;
		for (int i = 0; i < playersNum; i++) {
			float pAvg = players[i]->getAverage();
			if ( hAvg <= pAvg){
				hAvg = pAvg;
				winner = players[i]->getName();
			} 	
		}
		std::cout << "The winner is " << winner << " with the score of " << wScore << " and average of ";
		std::cout << hAvg << "." << "\n";
	}

};

//if round number n is even then load event cards for each player. 
//Then loads a scenario card and ask for players options. Updates eventNum and roundNum.
void GameEngine::playRound(int n){
	int sIndex = n - 1;
	std::cout << "********************************************************************************\n";
	std::cout << "Round: " << std::to_string(n) + "\n";
	std::cout << "********************************************************************************\n";
	//If n is even then load events cards for each player. 
	if (n % 2 == 0) {
		for (int i = 0; i < playersNum; i++) {
			//Display the event and which player is affected by.
			std::cout << players[i]->getName() << " draws the following event card. \n";
			std::cout << events[eventNum]->getEventStr() + "\n";
			events[eventNum]->affectedBy(players[i]); 
			eventNum++;
		//	std::cout << players[i]->displayattributes() << "\n";
			std::cout << "--------------------------------------------------------------------------------\n";
		}
	}

	//Load a scenario card...display it
	
	Scenario scen = *scenarios[sIndex];
	int optsNum = scen.getOptionsNum();
	std::cout << scen.getScenarioStr() << "\n";
	std::string input;
	//Ask each player which option that take and update effects on them.
	for (int i = 0; i < playersNum; i++) {
		std::cout << "--------------------------------------------------------------------------------\n";
		std::cout << players[i]->getName() << "'s turn. \n";
		input = getUserInput("Please enter option number.",buildValidResInts(1,optsNum));
		int optNum = atoi(input.c_str());
		scen.getOptions().at(optNum - 1).affectedBy(players[i]); //Option is affected by player
	}

	//update number
	roundNum++;
};

// Given a line that is separarted by commas from the attribute and the value that 
//effects the attribute (ie. 1, -1, 2, -2) return the effects structure
std::vector<std::pair<std::string, int>> parseEffects(std::string line){
	std::vector<std::pair<std::string, int>> effects;

	//If there is no effects then return an empty vector
	if (line == "" || line.compare("N") == 0){return std::vector<std::pair<std::string, int>>(); }

	int effectsNum = 0;
	//gets rid of spaces
	line.erase(remove_if(line.begin(), line.end(), isspace), line.end());
	std::vector<std::string> parsedLine = split(line, ',');
	std::pair<std::string, int> infoPair;
	infoPair.first = "";
	infoPair.second = 0;
	for(int i = 0; i < parsedLine.size(); i++) {
		if (i % 2) { //i is odd
			infoPair.second = atoi(parsedLine.at(i).c_str());
			effects.push_back(infoPair);
		}  else {  //i is even
			infoPair.first = parsedLine.at(i);
		}
	}
	return effects;
};

//Reads the file called "events.txt" in a specfic format and makes n Events objects.
void GameEngine::loadEvents(int n){
	int count = 0;
	std::string line;
	std::ifstream mFile ("events.txt");

	std::string eName;
	std::string eDescription;
	std::vector<std::pair<std::string, int>> eEffects;

	if (mFile.is_open()){
		while (getline (mFile, line) ){
			if (count >= n){ break; }
			if (line.find("Name:") == 0) {
				std::vector<std::string> parsedLine = split(line, ':'); 
				eName = parsedLine.at(1);
			}
			else if (line.find("Description:") == 0){
				std::vector<std::string> parsedLine = split(line, ':'); 
				eDescription = parsedLine.at(1);
			}
			else if (line.find("Effects:") == 0) {
				std::vector<std::string> parsedLine = split(line, ':'); 
				eEffects = parseEffects(parsedLine.at(1));
				events[count]  = new Event(eName, eDescription, eEffects);
				eEffects.clear();
				count++;
			}
			else{
				continue;
			}
		}
   			
		mFile.close();
	}
	else { 
		std::cout << "Unable to open file.";
	}

};

//Reads the file called "scenarios.txt" in a specfic format and makes n Scenario objects.
void GameEngine::loadScenarios(int n){
	int count = 0;
	std::string line;
	std::ifstream mFile ("scenarios.txt");
	std::string sName;
	std::string sDescription;
	std::vector<Option> sOpts;
	std::vector<std::pair<std::string, int>> eEffects;

	if (mFile.is_open()){
		while (getline (mFile, line) ){
      		//std::cout << line << '\n';
   			if (count >= n){ break; }
			if (line.find("Name:") == 0) {
				std::vector<std::string> parsedLine = split(line, ':'); 
				sName = parsedLine.at(1);
			}
			else if (line.find("Description:") == 0){
				std::vector<std::string> parsedLine = split(line, ':'); 
				sDescription = parsedLine.at(1);
			}
			else if (line.find("Option:") == 0) {
				std::vector<std::string> parsedLine = split(line, ':'); 
				eEffects = parseEffects(parsedLine.at(2)); 
				Option opt(parsedLine.at(1), eEffects);
				sOpts.push_back(opt);
				eEffects.clear();
			}
			else if (line.find("END;;") == 0) {
				scenarios[count]  = new Scenario(sName, sDescription, sOpts);
				sOpts.clear();
				count++;
			}
			else{
				continue;
			}

   		}
		mFile.close();
	}
	else { 
		std::cout << "Unable to open file.";
	}

};
