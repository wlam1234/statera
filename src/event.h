#ifndef __EVENT_H__
#define __EVENT_H__

#include <string>
#include "option.h"

//Events will always have at least one effect so effects should be a non-empty vector.
class Event : public Option {
	std::string name;

public:
	Event();
	Event(std::string nName, std::string nDescription, 
		std::vector<std::pair<std::string, int>> nEffects);
	~Event();

	std::string getName();
	//Returns a string containing the name and the effects of the event.
	std::string getEventStr();
	
};

#endif
