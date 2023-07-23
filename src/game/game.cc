#include "game.h"


Game::Game(): b(8, 8) {}

bool Game::isCheck(Player* p) {
    return inCheck;
}

bool Game::isCheckmate(Player* p) {
    return inCheckmate;
}

bool Game::isMoveValid(Piece* pc, int curX, int curY, int newX, int newY) {
    return false;
}

void Game::setup() {
    return;
}

void Game::move(Player* p, int curX, int curY, int newX, int newY) {
    Move m = p->turnMove(curX, curY, newX, newY, b); 
    if (!m.valid) {
        return; 
    }
    b.movePiece(m.oldX, m.oldY, m.newX, m.newY); 
    return;
}

void Game::play() {
    cout << "Game started" << endl;
    return;
}