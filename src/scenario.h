#ifndef __SCENARIO_H__
#define __SCENARIO_H__

#include <string>
#include <vector>
#include "option.h"

class Scenario {
	std::string name;
	std::string description;
	std::vector<Option> opts;

public:
	Scenario();
	Scenario(std::string nName, std::string nDescription, std::vector<Option> nOpts);
	~Scenario();

	std::string getName();
	std::string getDescription();
	std::string getOptionsStr();
	std::vector<Option> getOptions();
	std::string getScenarioStr(); //Returns string containing name, desciption and options.

	int getOptionsNum();
};

#endif
