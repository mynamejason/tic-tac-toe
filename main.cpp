#include <iostream>
#include <string>
#include "Checker.hpp"
#include "player.hpp"

using namespace std;

int main() {
    string playerName1 = "";
    string playerName2 = "";
    string marker1= "O";
    string marker2 = "X";
    int age1 = 0;
    int age2 = 0;

    cout << "Enter Player 1: ";
    cin >> playerName1;
    cout << "Enter Player 2: ";
    cin >> playerName2;
    cout << "Enter Player 1's age: ";
    cin >> age1;
    cout << "Enter Player 2's age: ";
    cin >> age2;

    Player player1(playerName1, marker1, age1);
    Player player2(playerName2, marker2, age2);

    Checker myChecker(player1, player2);

    //First turn
    bool gameLoop = true;
    int userInput = 0;
    myChecker.displayBoard();
    cout << player1.getName() << "'s turn: ";
    cin >> userInput;
    myChecker.placeMark(userInput);

    while(gameLoop) {
        if(!myChecker.hasWinner()) {
            cin >> userInput;
            myChecker.placeMark(userInput);
            cout << myChecker.hasWinner() << endl;
            if(myChecker.hasWinner()) {
                cout << "Winner!" << endl;
                gameLoop = false;
            }
        }
    }
    return 0;
}