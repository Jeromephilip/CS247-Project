#include "human.h"

Human::Human(string colour) : Player{colour} {};

Move Human::turnMove(int curX, int curY, int newX, int newY, Board& board) {
    return Move{curX, curY, newX, newY, board.getPiece(curX, curY)->isValidMove(curX, curY, newX, newY), board.getPiece(curX, curY)}; 
}
