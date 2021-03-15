#pragma once
#include <iostream>
class GameState {
private:
	int m_pile1;
	int m_pile2;
	int m_pile3;
	std::string m_mode;
	int activePlayer = 1;
	bool p1IsHuman = true;
	bool p2IsHuman = false;

public:
	GameState(int pile1, int pile2, int pile3, std::string mode);

	void visualizeState();

	void setPiles(int pile1, int pile2, int pile3);
	void setMode(std::string mode);
	bool isGameOver();
	void endGame(std::string currentPlayer);
	void startGame();
	void takeTurn();
	void playerTurn();
	void AITurn();
	void takeCoinsFromPile(int coins, int pile);

};

