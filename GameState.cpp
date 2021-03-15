#pragma once
#include <cstdlib>
#include <algorithm>
#include "GameState.h"

GameState::GameState(int pile1, int pile2, int pile3, std::string mode) {
	setPiles(pile1, pile2, pile3);
	setMode(mode);
	}

void GameState::setPiles(int pile1, int pile2, int pile3) {
	m_pile1 = pile1;
	m_pile2 = pile2;
	m_pile3 = pile3;
}

void GameState::setMode(std::string mode) {
	m_mode = mode;
}

void GameState::startGame() {
	std::cout << "Welcome to the game of Nim!" << std::endl;
	takeTurn();
}

void GameState::visualizeState() {
		int arr[] = { m_pile1, m_pile2, m_pile3 };
		//std::cout << "event 1" << " " << sizeof(arr) << std::endl;  //why does this log 12?
		//std::cout << "event 2" << " " << sizeof(arr[0]) << std::endl;  // why does this log 4?
		//std::cout << "event 3" << " " << arr[0] << " " << arr[1] << " " << arr[2] << std::endl;
		int n = sizeof(arr) / sizeof(arr[0]);
		std::sort(arr, arr + n);
		//std::cout << " Here are the piles" << std::endl;
		std::cout << "" << std::endl; //is there a better way to do empty line?
		int max = arr[2];
		int min = arr[0];
		bool belowMin = false;
		std::string coin = "O";
		std::string noCoin = " ";
		while (!belowMin) { 
			using namespace std;
			cout << " " << (m_pile1 >= max ? coin : noCoin) <<
				" " << (m_pile2 >= max ? coin : noCoin) <<
				" " << (m_pile3 >= max ? coin : noCoin) << endl;
			max--;
			if (max == min) {
				belowMin = true;
			}
		}
		while (min > 0) {
			using namespace std;
			cout << " O O O" << endl;
			min--;
		}
		std::cout << "*******" << std::endl;
		std::cout << " " << m_pile1 << " " << m_pile2 << " " << m_pile3 << std::endl;
}

void GameState::takeTurn() {
	if (activePlayer == 1) {
		playerTurn();
	}
	else {
		AITurn();
	}
}

void GameState::playerTurn() {
	visualizeState();
	std::cout << "What pile would you like to take coins from?" << std::endl;
	std::cout << "Please type '1', '2', or '3' and press [Enter]." << std::endl;
	int inputPile;
	std::cin >> inputPile;
	std::cout << "How many coins would you like to take from pile " << inputPile << "." << std::endl;
	int inputCoins;
	std::cin >> inputCoins;
	std::cout << "Taking " << inputCoins << " from pile " << inputPile << "." << std::endl;
	takeCoinsFromPile(inputCoins, inputPile);
	if (isGameOver()) {
		endGame("Player 1");
	}
	else {
		activePlayer = 2;
		takeTurn();
	}

}

void GameState::AITurn() {
	std::cout << "AI player's turn" << std::endl;
	if (m_pile1 > 0) {
		std::cout << "AI takes 1 coin from pile 1" << std::endl;
		takeCoinsFromPile(1, 1);
	}
	else if (m_pile2 > 0){
		std::cout << "AI takes 1 coin from pile 2" << std::endl;
		takeCoinsFromPile(1, 2);
	}
	else if (m_pile3 > 0) {
		std::cout << "AI takes 1 coin from pile 3" << std::endl;
		takeCoinsFromPile(1, 3);
	}
	if (isGameOver()) {
		endGame("AI Player");
	}
	else {
		activePlayer = 1;
		takeTurn();
	}
}

void GameState::takeCoinsFromPile(int coins, int pile) {
	switch (pile) {
	case 1:
		m_pile1 -= coins;
		break;
	case 2:
		m_pile2 -= coins;
		break;
	case 3:
		m_pile3 -= coins;
		break;
	}
	return;
}

bool GameState::isGameOver() {
	return (m_pile1 == 0 && m_pile2 == 0 && m_pile3 == 0);
}

void GameState::endGame(std::string currentPlayer) {
	std::cout << currentPlayer << " wins!" << std::endl;
}

std::string welcomeMessage = " Welcome to the game of Nim!"; //why can't I reference this?
