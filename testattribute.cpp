#include "attribute.h"
#include <iostream>

bool testEmpty(){
	Attribute a("");
	return (a.getName().compare("") == 0) && (a.getValue() == 0);
};

//int main()
//{
//	std::cout << testEmpty() << "\n" ;
//	Attribute a1("Honey");
//	Attribute a2("Money");
	
//	Attribute a4("Chocolate1234");
//	Attribute a5("!d");




//}
