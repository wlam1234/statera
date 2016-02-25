#include "attribute.h"


Attribute::Attribute(std::string nName){
	name = nName;
	value = 0;
	min = 0;
	max = 5;
};

Attribute::~Attribute() {
};

int Attribute::getValue(){
	return value;
};

std::string Attribute::getName(){
	return name;
};

void Attribute::setValue(int nVal){
	if (nVal < min) {
		value = min;
	} else if (nVal > max) {
		value = max;
	}
	else {
		value = nVal;
	}
};
