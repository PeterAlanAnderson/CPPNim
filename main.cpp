#include <cstdlib>
#include <iostream>
#include "GameState.h"

int main() {
	std::cout << "Nim game against AI" << std::endl;
	GameState game { 6, 4, 5, "pvai" };
	game.startGame();
	
}

std::string getInput() {
	std::string input;
	std::cin >> input;
	return input;
}
