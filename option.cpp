#include <iostream>
#include "option.h"

Option::Option(){
	description = "";

};

Option::Option(std::string nDescription, std::vector<std::pair<std::string, int>> nEffects){
	description = nDescription;
	effects = nEffects;
};

Option::~Option(){
};

std::string Option::getDescription(){
	return description;
};

std::vector<std::pair<std::string, int>> Option::getEffects(){
	return effects;
};

std::string Option::getEffectsStr(){
	std::string effectsStr = "";
	for(std::vector<std::pair<std::string, int>>::iterator it = effects.begin(); 
		it != effects.end(); ++it) {
		std::pair<std::string, int> infoPair = *it;
		if (infoPair.second > 0){
			effectsStr += infoPair.first + ": +" + std::to_string(infoPair.second) + "\n";
		} else {
			effectsStr += infoPair.first + ": " + std::to_string(infoPair.second) + "\n";
		}

	}
	return effectsStr;
};

std::string Option::getOptStr(){
	std::string optStr = "";
	optStr += getDescription() + "\n";
	optStr += getEffectsStr();
	return optStr;
};


//Prints if no changes happens and prints player's stats and updates player's attributes
void Option::affectedBy(Player* p){
	
	if (effects.empty()) {
		std::cout << "No changes for "<< p->getName() << ".\n"; 
	}else{
		for(std::vector<std::pair<std::string, int>>::iterator it = effects.begin(); 
		it != effects.end(); ++it) {
			std::pair<std::string, int> infoPair = *it;
			std::string att = infoPair.first;
			int val = infoPair.second;
			p->setAttribute(att, val + p->getAttribute(att));

		}
	}

	//Prints current player's stats
	std::cout << p->displayattributes() + "\n";

};