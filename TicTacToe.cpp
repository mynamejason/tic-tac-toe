
#include <iostream>
#include <vector>

class TicTacToe {
public:
    void printBoard(std::vector<int>& board) {
        std::vector<int> tempBoard = board;
        int gap = 9 - board.size();
        for(int i = 0; i < gap; i++) {
            tempBoard.push_back(0);
        }
        
        for(int col = 0; col < tempBoard.size(); col += 3) {
            int rowSum = 0;
            for(int row = col; row < col + 3; row++) {
                std::cout << "[" << tempBoard[row] << "]";
                rowSum += tempBoard[row];
            }
            std::cout << " = " << rowSum << std::endl;
        }

        std::cout << " = = = " << std::endl;
        std::cout << " " << tempBoard[0] + tempBoard[3] + tempBoard[6];
        std::cout << " " << tempBoard[1] + tempBoard[4] + tempBoard[7];
        std::cout << " " << tempBoard[2] + tempBoard[5] + tempBoard[8];
        std::cout << std::endl;
        std::cout << "----------------------------" << std::endl;
    }

    int sumOfRow1(std::vector<int>& board) {
        return board[0] + board[1] + board[2];
    }

    int sumOfRow2(std::vector<int>& board) {
        return board[3] + board[4] + board[5];
    }

    int sumOfRow3(std::vector<int>& board) {
        return board[6] + board[7] + board[8];
    }

    int sumOfCol1(std::vector<int>& board) {
        return board[0] + board[3] + board[6];
    }

    int sumOfCol2(std::vector<int>& board) {
        return board[1] + board[4] + board[7];
    }

    int sumOfCol3(std::vector<int>& board) {
        return board[2] + board[5] + board[8];
    }

    int sumOfCross1(std::vector<int>& board) {
        return board[0] + board[4] + board[8];
    }

    int sumOfCross2(std::vector<int>& board) {
        return board[2] + board[4] + board[6];
    }

    bool isAnswer(std::vector<int>& board) {
        std::vector<int> sums;
        sums.push_back(sumOfRow1(board));
        sums.push_back(sumOfRow2(board));
        sums.push_back(sumOfRow3(board));
        sums.push_back(sumOfCol1(board));
        sums.push_back(sumOfCol2(board));
        sums.push_back(sumOfCol3(board));
        sums.push_back(sumOfCross1(board));
        sums.push_back(sumOfCross2(board));

        int firstElement = sums[0];
        for(int i = 0; i < sums.size(); i++) {
            if(firstElement != sums[i]) {
                return false;
            }
        }
        return true;
    }

    bool isCorrect(int index, std::vector<int> board, std::vector<int> possibleNumbers) {
        for(int i = 0; i < possibleNumbers.size(); i++) {
            std::vector<int> myPossibleNumber = possibleNumbers; // copy 1 [2] ~ 9
            std::vector<int> myBoard = board;

            myBoard.push_back(myPossibleNumber[i]);
            myPossibleNumber.erase(myPossibleNumber.begin() + i); //1, 3 ~ 9

            printBoard(myBoard);

            if(myPossibleNumber.size() == 0) {
                if(isAnswer(myBoard)) {
                    std::cout << "Found" << std::endl;
                    return true;
                } else {
                    return false;
                }
            } else if(isCorrect(i, myBoard, myPossibleNumber)) {
                return true;
            }
        }
        return false;
    }

    void run() {
        for(int i = 0; i < 9; i++) {
            possibleNumbers_.push_back(i + 1);
        }
        isCorrect(0, board_, possibleNumbers_);
    }

private:
    std::vector<int> board_;
    std::vector<int> possibleNumbers_;
};