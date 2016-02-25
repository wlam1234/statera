#include "player.h"
#include "attribute.h"

#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <string>
//#include <iostream>; //testing

Player::Player(std::string pName){
	name = pName;
	attributes[0] = new Attribute("Body");
	attributes[1] = new Attribute("Mind");
	attributes[2] = new Attribute("Social");
	attributes[3] = new Attribute("School");
	attributes[4] = new Attribute("Money");
};

Player::~Player(){
	delete [] attributes;
};

std::string Player::getName(){
	return name;
}

//Returns -1 if given unexpected string otherwise returns the value of the attribute.
int Player::getAttribute(std::string aName){
	int aValue = -1;
	for (int i = 0; i < 5; i++){
		if (aName.compare(attributes[i]->getName()) == 0) {
			aValue = attributes[i]->getValue();
		}
	}
	return aValue;
};

	//requires name of the attribute and the new value
void Player::setAttribute(std::string aName, int nVal){
	for (int i = 0; i < 5; i++){
		if (aName.compare(attributes[i]->getName()) == 0) {
			attributes[i]->setValue(nVal);
			break;
		}
	}
};

std::string Player::displayattributes(){
	std::string aText = "";
	for (int i = 0; i < 5; i++){
		aText += attributes[i]->getName() + ": ";
		aText += std::to_string(attributes[i]->getValue());
		aText += "\n";
	}

	return aText;
};


void Player::setEffects(std::vector<std::pair<std::string, int>> effects) {
	for(std::vector<std::pair<std::string, int>>::iterator it = effects.begin(); 
		it != effects.end(); ++it) {
		std::pair<std::string, int> infoPair = *it;
		setAttribute(infoPair.first, getAttribute(infoPair.first) + infoPair.second); 
	}

};

//Returns player's score 
int Player::getScore(){
	int aValues[5];
	int score = 0;
	for (int i = 0; i < 5; i++) {
		aValues[i] = attributes[i]->getValue();
	}
	//make a vector to sort elements in accending order.
	 std::vector<int> aVector (aValues, aValues + 5);  
	 std::sort (aVector.begin(), aVector.begin() + 5);
	 for (int i = 0; i < 4; i++) {
		score += aVector.at(i + 1) - aVector.at(i);
	}

	return score; //sum of the differences of the sorted adjacent attributes
};


float Player::getAverage(){
	float sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += attributes[i]->getValue();
	}
	return sum / 5;
};
