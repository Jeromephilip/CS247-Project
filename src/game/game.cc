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
    // initial setup code;
    defaultSetup();
}

// void Game::move(Player* p, int curX, int curY, int newX, int newY) {
//     Move m = p->turnMove(curX, curY, newX, newY, b); 
//     if (!m.valid) {
//         return; 
//     }
//     b.movePiece(m.oldX, m.oldY, m.newX, m.newY); 
//     return;
// }

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

void Game::move(string iPos, string fPos) {
    int curX = iPos[0] - 'a';
    int curY = iPos[1] - '0' - 1;
    int newX = fPos[0] - 'a';
    int newY = fPos[1] - '0' - 1;
    Piece *pieceToMove = b.getPiece(curX, curY);
    // cout << pieceToMove->getHasMoved() << endl;
    if (pieceToMove->isValidMove(b, curX, curY, newX, newY)) {
        b.getSquare(newX, newY)->setPieceOnSquare(pieceToMove);
        b.getSquare(curX, curY)->removePieceOnSquare();   
        if (pieceToMove->getHasMoved() == false) {
            pieceToMove->setHasMoved(true);
        }
    }
    //  cout << pieceToMove->getHasMoved() << endl;
    return;
}

void Game::play() {
    setup();
    b.printBoard();
    while (true) {
        string input;
        if (!getline(cin, input)) {
            break;
        }

        stringstream ss {input};
        string cmd;
        ss >> cmd;
        if (cmd == "move") {
            string iPos;
            string fPos;
            ss >> iPos;
            ss >> fPos;
            move(iPos, fPos);
        }
        b.printBoard();
    }
    // cout <<  b.getPiece(1, 7)->getType() << endl;
    // b.getPiece(1, 7)->getPossibleMoves(b, 1, 7);
    // cout << test.size() << endl;
    // for (const auto& pair : test) {
    //     cout << pair.first << ", " << pair.second << endl;
    // }

    

    return;
}