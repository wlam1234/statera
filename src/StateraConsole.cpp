// main project file.

#include <iostream>
#include <string>

#include "player.h"
#include "gameengine.h"

int main()
{
	std::string input;
	GameEngine ge;
   
	ge.displayIntro();
	ge.getPlayersNum();
	ge.getPlayersStats();
	for (int i = 1; i < 13; i++){
		ge.playRound(i);
	}
	ge.getWinner();

	//Player p("Apple");
	//std::cout << p.getName() << std::endl;
	//std::cout << p.displayattributes() << std::endl;
	//while (std::getline(std::cin, input)){
	//	std::cout << input <<std::endl;
	//}
	
    return 0;
}
