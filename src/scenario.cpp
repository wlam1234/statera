#include "scenario.h"


Scenario::Scenario(){
	name = "";
	description = "";
};

Scenario::Scenario(std::string nName, std::string nDescription, std::vector<Option> nOpts){
	name = nName;
	description = nDescription;
	opts = nOpts;
};

Scenario::~Scenario(){
};

std::string Scenario::getName(){
	return name;
};

std::string Scenario::getDescription(){
	return description;
};


std::vector<Option> Scenario::getOptions(){
	return opts;
};

std::string Scenario::getOptionsStr(){
	std::string optsStr = "";
	int count = 1;
	for(std::vector<Option>::iterator it = opts.begin(); 
		it != opts.end(); ++it) {
		Option opt = *it;
		optsStr += "Option " + std::to_string(count)+ ": ";
		optsStr += opt.getOptStr() + "\n";
		count++;
	}
	return optsStr;
};

std::string Scenario::getScenarioStr(){
	std::string scenarioStr = "";
	scenarioStr += "Name of Scenario: " + getName() + "\n";
	scenarioStr += getDescription() + "\n\n";
	scenarioStr += getOptionsStr();
	return scenarioStr;
};

int Scenario::getOptionsNum(){
	return (int) opts.size();
};
