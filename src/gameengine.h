#ifndef __GAMEENGINE_H__
#define __GAMEENGINE_H__
#include <string>
#include "player.h"
#include "scenario.h"
#include "event.h"

//Lets assume we have all human players
class GameEngine {
	
public:
	int roundNum;
	int playersNum;
	int eventNum;
	Player * players [4]; //max is 4 players for now
	Scenario * scenarios [12]; //12 scenarios 
	Event * events [4*6]; // number of max players times 6 

	GameEngine();
	GameEngine(int pNum);
	~GameEngine();

	void loadEvents(int n); //n is the number of events
	void loadScenarios(int n); //n is the number of Scenarios
	void displayIntro();
	void getPlayersNum(); //asks users for number of players
	void getPlayersStats(); //gets players names and  beginning distribution of attributes 
	void playRound(int n); // n is the round number
	void getWinner();
};

#endif
