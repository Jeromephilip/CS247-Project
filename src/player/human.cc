#include "human.h"

Human::Human(string colour, bool isComputer) : Player{colour, isComputer} {}

Move Human::turnMove(int curX, int curY, int newX, int newY, Board& board) {
    if (board.getPiece(curX, curY) == nullptr) {
        return Move{curX, curY, newX, newY, false, nullptr}; 
    } 
    return Move{curX, curY, newX, newY, board.getPiece(curX, curY)->isValidMove(board, curX, curY, newX, newY), board.getPiece(curX, curY)}; 
}

Human::~Human() {}