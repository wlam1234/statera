#ifndef __UTILITIES_H__
#define __UTILITIES_H__

#include "scenario.h"
#include "event.h"


std::vector<std::string> split(std::string str, char delim);

//Check if a string is an int
bool isInt(std::string str);

//Given a string which is a request, and a vector of strings validRes, where each string is a valid 
//response to the request, keep repeating the request until users gives a valid reponse.
std::string getUserInput(std::string request, std::vector<std::string> validRes);

//Build a vector of strings given the range (min, and max). The first element is the string of min, 
//second is the string of min + 1 and so on until reaching the max.
std::vector<std::string> buildValidResInts(int min, int max);

#endif