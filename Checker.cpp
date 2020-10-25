#include "Checker.hpp"
#include <string>

Checker::Checker() {
	for(int i = 0; i < 9; i++) {
		board_.push_back(" ");
		secretBoard_.push_back(i+2); 
	}
	isFirstPlayerTurn_ = true;
}

Checker::~Checker() {
	board_.clear();
	secretBoard_.clear();
	isFirstPlayerTurn_ = false;
}

Checker::Checker(Player& player1, Player& player2) {
	player1_ = player1;
	player2_ = player2;
	for(int i = 0; i < 9; i++) {
		board_.push_back(" ");
		secretBoard_.push_back(i+2);
	}
	isFirstPlayerTurn_ = true;
}

void Checker::placeMark(int spot) {
	std::string mark = "";
	if(board_[spot - 1] == " ") {
		if(isFirstPlayerTurn_) {
			mark = "O";
			std::cout << player2_.getName();
		} else {
			mark = "X";
			std::cout << player1_.getName();
		}
		std::cout << "'s turn" << std::endl;

		board_[spot - 1] = mark;
		generateBoard(spot, mark);
		isFirstPlayerTurn_ = !isFirstPlayerTurn_;
		displayBoard();
	} else {
		std::cout << "This space is occupied." << std::endl;
		displayBoard();
	}
}

bool Checker::hasWinner() {
	if(sameThree(0, 1, 2))
		return true;
	else if(sameThree(0, 3, 6)) 
		return true;
	else if(sameThree(0, 4, 8)) 
		return true;
	else if(sameThree(1, 4, 7)) 
		return true;
	else if(sameThree(2, 5, 8)) 
		return true;
	else if(sameThree(2, 4, 6)) 
		return true;
	else if(sameThree(3, 4, 5)) 
		return true;
	else if(sameThree(6, 7, 8)) 
		return true;
	else 
		return false;
}

void Checker::displayBoard() {
	for(int row = 0; row < 9; row += 3) {
		for(int col = row; col < row + 3; col++) {
			std::cout << "[" << board_[col] << "]";
		}
		std::cout << std::endl;
	}
}

void Checker::generateBoard(int spot, std::string mark) {
	if(mark == "O") {
		secretBoard_[spot - 1] = -1;
	} else if(mark == "X") {
		secretBoard_[spot - 1] = -2;
	}
}

bool Checker::sameThree(int first, int second, int third) {
	if((secretBoard_[first] == secretBoard_[second]) && secretBoard_[second] == secretBoard_[third]) {
		return true;
	}
	return false;
}