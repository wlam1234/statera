#include "event.h"

Event::Event() : Option(){
	name = "";
};

Event::Event(std::string nName, 
			 std::string nDescription, std::vector<std::pair<std::string, int>> nEffects)
			 :  Option(nDescription, nEffects){
	name = nName;
}

Event::~Event(){
};

std::string Event::getName(){
	return name;
};

std::string Event::getEventStr(){
	std::string eventStr= "";
	eventStr += "Name of the Event:" + getName() + "\n";
	eventStr += Option::getDescription() + "\n";
	return eventStr;
}
