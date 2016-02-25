#ifndef __ATTRIBUTE_H__
#define __ATTRIBUTE_H__

#include <string>

class Attribute {
	std::string name;
	int value; 
	int min;
	int max;

public:
	Attribute(std::string nName);
	~Attribute();

	int getValue();
	std::string getName();

	void setValue(int nVal);
};

#endif
