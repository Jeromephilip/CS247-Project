#include "game.h"


Game::Game(): b(8, 8) {}

bool Game::isCheck() {
    return inCheck;
}

bool Game::isCheckmate() {
    return inCheckmate;
}

bool Game::isMoveValid(int curX, int curY, int newX, int newY) {
    return false;
}

void Game::setup() {
    // initial setup code;
    defaultSetup();
}

void Game::defaultSetup() {
    // black side
    b.setPiece(new Rook("black"), 0, 0);
    b.setPiece(new Knight("black"), 1, 0);
    b.setPiece(new Bishop("black"), 2, 0);
    b.setPiece(new Queen("black"), 3, 0);
    b.setPiece(new King("black"), 4, 0);
    b.setPiece(new Bishop("black"), 5, 0);
    b.setPiece(new Knight("black"), 6, 0);
    b.setPiece(new Rook("black"), 7, 0);
    b.setPiece(new Pawn("black"), 0, 1);
    b.setPiece(new Pawn("black"), 1, 1);
    b.setPiece(new Pawn("black"), 2, 1);
    b.setPiece(new Pawn("black"), 3, 1);
    b.setPiece(new Pawn("black"), 4, 1);
    b.setPiece(new Pawn("black"), 5, 1);
    b.setPiece(new Pawn("black"), 6, 1);
    b.setPiece(new Pawn("black"), 7, 1);

    // white side
    b.setPiece(new Rook("white"), 0, 7);
    b.setPiece(new Knight("white"), 1, 7);
    b.setPiece(new Bishop("white"), 2, 7);
    b.setPiece(new Queen("white"), 3, 7);
    b.setPiece(new King("white"), 4, 7);
    b.setPiece(new Bishop("white"), 5, 7);
    b.setPiece(new Knight("white"), 6, 7);
    b.setPiece(new Rook("white"), 7, 7);
    b.setPiece(new Pawn("white"), 0, 6);
    b.setPiece(new Pawn("white"), 1, 6);
    b.setPiece(new Pawn("white"), 2, 6);
    b.setPiece(new Pawn("white"), 3, 6);
    b.setPiece(new Pawn("white"), 4, 6);
    b.setPiece(new Pawn("white"), 5, 6);
    b.setPiece(new Pawn("white"), 6, 6);
    b.setPiece(new Pawn("white"), 7, 6);
}

void Game::move(int curX, int curY, int newX, int newY) {
    Piece* p = b.getPiece(curX, curY);
    vector<pair<int, int>> possibleMoves = p->getPossibleMoves(p, b, curX, curY);
    for (int i=0; (int)i<possibleMoves.size(); i++) {
        if (possibleMoves[i].first== newX && possibleMoves[i].second == newY) {
            b.movePiece(curX, curY, newX, newY);
            break;
        }
    }
}

void Game::play() {
    setup();
    move(0, 1, 0, 2);
    b.printBoard();
    return;
}