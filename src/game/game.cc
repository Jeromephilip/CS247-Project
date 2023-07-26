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

void Game::move(Player* p, string iPos, string fPos) {
    int curX = iPos[0] - 'a';
    int curY = iPos[1] - '0' - 1;
    int newX = fPos[0] - 'a';
    int newY = fPos[1] - '0' - 1;
    //Piece *pieceToMove = b.getPiece(curX, curY);
    Move m = p->turnMove(curX, curY, newX, newY, b); 
    if (m.piece == nullptr) {
        return; 
    }
    
    cout << "The move coordinates are: (" << m.oldX << "," << m.oldY << ") -> (" << m.newX << "," << m.newY << ")" << endl;
    if (m.valid) {
        cout << "valid move" << endl;
        cout << m.piece->getType() << endl;
    }
    // cout << pieceToMove->getHasMoved() << endl;
    if (m.valid) {
        b.getSquare(m.newX, m.newY)->setPieceOnSquare(m.piece);
        b.getSquare(m.oldX, m.oldY)->removePieceOnSquare();   
        if (m.piece->getHasMoved() == false) {
            m.piece->setHasMoved(true);
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
        if (cmd == "game") {
            string p1;
            string p2;
            ss >> p1;
            ss >> p2;
            if (p1 == "human" && p2 == "human") {
                pW = new Human("white", false);
                pB = new Human("blackk", false);
            } 
            else if (p1 == "human" && p2 != "human") {
                pW = new Human("white", false);
                if (p2[8] == '1') {
                    pB = new Level1("black", true);
                }
            }
            else if (p1 != "human" && p2 == "human") {
                pB = new Human("black", false);
                if (p1[8] == '1') {
                    pW = new Level1("white", true);
                }
            }
            else if (p1 != "human" && p2 != "human") {
                if (p2[8] == '1') {
                    pB = new Level1("black", true);
                }
                if (p2[8] == '1') {
                    pW = new Level1("white", true);
                }
            }

        }
        if (cmd == "move") {
            string iPos;
            string fPos;

            if (turn % 2 == 0) {
                if (!pW->getBool()) {
                    ss >> iPos;
                    ss >> fPos;
                    move(pW, iPos, fPos); 
                } 
                else {
                    move(pW, "a2", "a3");
                }
            } 
            else {
                if (!pB->getBool()) {
                    ss >> iPos;
                    ss >> fPos;
                    move(pB, iPos, fPos); 
                } 
                else {
                    move(pB, "a2", "a3");
                }
            }
            turn++; 
        }
        b.printBoard();
    }
    /*
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
            cout << "inside move" << endl;
            move(iPos, fPos);
        }
        b.printBoard();
    }*/
    // cout <<  b.getPiece(1, 7)->getType() << endl;
    // b.getPiece(1, 7)->getPossibleMoves(b, 1, 7);
    // cout << test.size() << endl;
    // for (const auto& pair : test) {
    //     cout << pair.first << ", " << pair.second << endl;
    // }
    

    return;
}