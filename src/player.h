#ifndef __PLAYER_H__
#define __PLAYER_H__


#include "attribute.h"
#include <string>
#include <vector>

class Player {
	std::string name;
	

public:
	Attribute * attributes[5]; //an array of 5 attributes

	Player(std::string pName);
	~Player();
	std::string getName();
	int getAttribute(std::string aName); //requires name of the attribute

	//requires name of the attribute and the new value
	void setAttribute(std::string aName, int nVal); 
	std::string displayattributes();

	void setEffects(std::vector<std::pair<std::string, int>> effects);
	int getScore();
	float getAverage();
};

#endif
