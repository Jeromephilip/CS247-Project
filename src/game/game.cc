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

    // // white side
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

void Game::setup() {
    // initial setup code;
    bool hasSetup = false;
    bool hasPickedWhiteKing = false;
    bool hasPickedBlackKing = false;
    
    while (true) {
        string c;
        if (!(cin >> c)) {
            break;
        };
        if (c == "default") {
            defaultSetup();
            b.printBoard();
            hasSetup = true;
            hasPickedBlackKing = true;
            hasPickedWhiteKing = true;
            cout << "Default Mode Selected - Setup Mode Exited" << endl;
            break;
        } else if (c == "done") {
            if (hasSetup) {
                cout << "Setup Mode Exited" << endl;
                break;
            } else {
                cout << "Still need to setup your board! If you are having trouble, check if both kings are on the board!" << endl;
            }
        } else {
            string arg2;
            string arg3;
            if (c == "+") {
                bool inValid = false;
                cin >> arg2;
                cin >> arg3;
                int x, y;
                if (arg3.size() == 2) {
                    x = arg3[0] - 'a';
                    y = abs(arg3[1] - '0' - 8);
                } else {
                    inValid = true;
                }

                if (arg2 == "K") {
                    // check if in check or king is beside king
                    b.setPiece(new King("white"), x, y);
                    hasPickedWhiteKing = true;
                } else if (arg2 == "Q") {
                    b.setPiece(new Queen("white"), x, y);
                } else if (arg2 == "R") {
                    b.setPiece(new Rook("white"), x, y);
                } else if (arg2 == "N") {
                    b.setPiece(new Knight("white"), x, y);
                } else if (arg2 == "B") {
                    b.setPiece(new Bishop("white"), x, y);
                } else if (arg2 == "P") {
                    b.setPiece(new Pawn("white"), x, y);
                } else if (arg2 == "k") {
                    b.setPiece(new King("black"), x, y);
                    hasPickedBlackKing = true;
                } else if (arg2 == "q") {
                    b.setPiece(new Queen("black"), x, y);
                } else if (arg2 == "r") {
                    b.setPiece(new Rook("black"), x, y);
                } else if (arg2 == "n") {
                    b.setPiece(new Knight("black"), x, y);
                } else if (arg2 == "b") {
                    b.setPiece(new Bishop("black"), x, y);
                } else if (arg2 == "p") {
                    b.setPiece(new Pawn("black"), x, y);
                } else {
                    inValid = true;
                }

                if (inValid) {
                    cout << "Invalid Command" << endl;
                }

                if (hasPickedWhiteKing && hasPickedBlackKing) {
                    hasSetup = true;
                }
            } else if (c == "-") {
                // need to check if nothing is on board -> then hasSetup = false;
                cin >> arg2;
                if (arg2.size() == 2) {
                    int x = arg2[0] - 'a';
                    int y = abs(arg2[1] - '0' - 8);
                    b.removePiece(x, y);
                } else {
                    cout << "Invalid Position" << endl;
                }
            } else if (c == "=") {
                cin >> arg2;
                if (arg2 == "black") {
                    turn = 1;
                } else if (arg2 == "white") {
                    turn = 0;
                } else {
                    cout << "Invalid Colour" << endl;
                }
            } else {
                cout << "Invalid Command" << endl;
            }
            b.printBoard();
        }
    }

}


void Game::move(Player* p, string iPos, string fPos) {
    int curX = iPos[0] - 'a';
    int curY = abs(iPos[1] - '0' - 8);
    int newX = fPos[0] - 'a';
    int newY = abs(fPos[1] - '0' - 8);
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

    // check if the the move makes it a check with b.isCheck...
    return;
}

void Game::gameType(stringstream& ss) {
    string p1;
    string p2;
    ss >> p1;
    ss >> p2;
    if (p1 == "human" && p2 == "human") {
        pW = new Human("white", false);
        pB = new Human("black", false);
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

void Game::helpMenu() {
    cout << "Here are the list of commands:" << endl;
    cout << "setup - You can setup your board. Use the 'default' command to get a basic chess board or make your custom moves!" << endl;
    cout << "game - You can initialize your players, i.e. who is black or white and if you want to face against a computer. The command takes in 3 arguments as follows: <game> <player1> <player2> where player1 and player2 are either human or computer1, computer2, computer3, computer4 " << endl;
    cout << "move- Once you used both of these commands, you can move a piece to start your game" << endl;
    cout << "Note that you cannot go back to setup and game once initialized" << endl;
}

void Game::play() {
    // setup();
    // b.printBoard();
    // cout <<  b.getPiece(4, 7)->getType() << endl;
    // pW = new Human("white", false);
    // pB = new Human("black", false);
    // vector <pair<int, int>> test = b.getPiece(4, 7)->getPossibleMoves(b, 4, 7);
    // cout << test.size() << endl;
    // for (const auto& pair : test) {
    //     cout << pair.first << ", " << pair.second << endl;
    // }
    // move(pW, "e2", "e3");
    // b.printBoard();
    // test = b.getPiece(4, 7)->getPossibleMoves(b, 4, 7);
    // cout << test.size() << endl;
    // for (const auto& pair : test) {
    //     cout << pair.first << ", " << pair.second << endl;
    // }
    // move(pW, "e1", "e2");
    // b.printBoard();

    cout << "Welcome to our CS247 Project - Chess in C++ - Made by Jerome and Maahir" << endl;
    bool isSetupDone = false;
    bool isGameDone = false;
    while (true) {
        string input;
        if (!getline(cin, input)) {
            break;
        }        
        stringstream ss {input};
        string cmd;
        ss >> cmd;
        if (cmd == "help") {
            helpMenu();
        } else if (cmd == "setup" && !isSetupDone) {
            setup();
            isSetupDone = true;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (cmd == "game" && !isGameDone) {
            gameType(ss);
            isGameDone = true;
        } else if (cmd == "move" && isGameDone && isSetupDone) {
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
            } else {
                if (!pB->getBool()) {
                    ss >> iPos;
                    ss >> fPos;
                    move(pB, iPos, fPos); 
                } else {
                    move(pB, "a2", "a3");
                }
            }
            turn++;
            b.printBoard();
        } else if (cmd == "done") {
            break;
        } else {
            if (cmd == "setup" && isSetupDone) {
                cout << "You have already setup your board!" << endl;
            } else if (cmd == "game" && isGameDone) {
                cout << "You have already initialized your players!" << endl;
            } else {
                cout << "Invalid Command" << endl;
            }
            
        }
    }
    return;
}