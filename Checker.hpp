#ifndef Checker_hpp
#define Checker_hpp

#include "Player.hpp"
#include <vector>
#include <string>
#include <iostream>

class Checker {
public:
	Checker();
	~Checker();
	Checker(Player& player1, Player& player2);
	void placeMark(int spot);
	bool hasWinner();
	void displayBoard();

private:
	void generateBoard(int spot, std::string mark);
	bool sameThree(int one, int two, int three);

	Player player1_;
	Player player2_;
	std::vector<std::string> board_;
	std::vector<int> secretBoard_;
	bool isFirstPlayerTurn_;
};

#include "Checker.cpp"
#endif