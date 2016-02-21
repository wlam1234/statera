#ifndef __OPTION_H__
#define __OPTION_H__

#include "player.h"
#include <string>
#include <vector>
#include <utility>

class Option {
	//Desciption does not include the effects.
	std::string description;
	//A vector of pairs where the first element of the pair is the string of the attribute
	//and the second element of the pair is increase/decrease amount.
	std::vector<std::pair<std::string, int>> effects;

public:
	Option();
	Option(std::string nDescription, std::vector<std::pair<std::string, int>> nEffects);
	~Option();

	std::string getDescription(); //does not include effects
	std::vector<std::pair<std::string, int>> getEffects();
	std::string getEffectsStr(); //does not include description.
	std::string getOptStr(); //includes effects and description.

	void affectedBy(Player* p);
};

#endif