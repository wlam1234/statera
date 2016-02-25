
#include "utilities.h"
#include "event.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>





//Does the usual string split
std::vector<std::string> split(std::string str, char delim) {
  std::vector<std::string> temp;
  std::stringstream ss(str); // Turn the string into a stream.
  std::string tok;
  
  while(std::getline(ss, tok, delim)) {
    temp.push_back(tok);
  }
  
  return temp;
};

//Returns true if the string str is an integer.
bool isInt(std::string str){
	for(char& c : str) {
		if (!std::isdigit(c)){
			return false;
		}
	}
	return true;

};

std::string getUserInput(std::string request, std::vector<std::string> validRes){
	std::string input;
	std::cout << request << "\n";
	while (std::getline(std::cin, input)){
		for (int i = 0; i < validRes.size(); i++) {
			std::string validR = validRes.at(i);
			if (input.compare(validR) == 0){
				return input;
			}
		}
		std::cout << "You entered an invalid input.\n" << request << "\n";
	}

	return "";
};

std::vector<std::string> buildValidResInts(int min, int max){
	std::vector<std::string>  validResInts;
	for (int i = min; i < max + 1; i++){
		validResInts.push_back(std::to_string(i));
	}

	return validResInts;
};
