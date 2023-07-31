#include "game.h"


Game::Game(): b(8, 8) {}

bool Game::isCheck(Player* p) {
    return true;
} 

void Game::reset() {
    b.reset();
    isGameDone = false;
    isSetupDone = false;
    turn = 0;
    Player* tempPlayer1 = pW;
    Player* tempPlayer2 = pB;
    pW = nullptr;
    pB = nullptr;
    delete tempPlayer1;
    delete tempPlayer2;
}


bool Game::isStalemate(string color) {
    int numMoves = 0;
    for (int i=0; i<b.getHeight(); i++) {
        for (int j=0; j<b.getWidth(); j++) {
            if (b.getSquare(j, i)->checkOccupied() && b.getPiece(j, i)->getColor() == color) {
                numMoves += b.getPiece(j, i)->getPossibleMoves(b, j, i).size();
            }
        }
    }

    // cout << numMoves << endl;
    pair<int, int> kingPos = b.findKing(color);
    if (numMoves == 0 && !b.isCheck(color, kingPos.first, kingPos.second)) {
        return true;
    }

    return false;
}

bool Game::isCheckmate(string color) {
    // first check if the king is in check
    pair<int, int> kingPos = b.findKing(color);
    if (!b.isCheck(color, kingPos.first, kingPos.second)) {
        return false;
    }

    int numMoves = 0;
    for (int i=0; i<b.getHeight(); i++) {
        for (int j=0; j<b.getWidth(); j++) {
            if (b.getSquare(j, i)->checkOccupied() && b.getPiece(j, i)->getColor() == color) {
                // vector<pair<int, int>> pMove = b.getPiece(j, i)->getPossibleMoves(b, j, i);
                // cout << b.getPiece(j, i)->getType() << endl;
                // for (size_t k=0; k<pMove.size(); k++) {
                //     cout << " " << pMove[k].first << ", " << pMove[k].second << endl;
                // }
                numMoves += b.getPiece(j, i)->getPossibleMoves(b, j, i).size();
            }
        }
    }

    // cout << numMoves << endl;

    if (numMoves == 0) {
        return true;
    }

    return false;
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
    cout << "Entered Setup Mode" << endl;
    b.printBoard();
    // initial setup code;
    // bool hasSetup = false;
    // bool hasPickedWhiteKing = false;
    // bool hasPickedBlackKing = false;
    
    while (true) {
        string c;
        if (!(cin >> c)) {
            break;
        };
        if (c == "default") {
            defaultSetup();
            b.printBoard();
            notifyObservers(); 
            // hasSetup = true;
            // hasPickedBlackKing = true;
            // hasPickedWhiteKing = true;
            cout << "Default Mode Selected - Setup Mode Exited" << endl;
            break;
        } else if (c == "done") {

            pair <int, int> bKingPos = b.findKing("black");
            pair <int, int> wKingPos = b.findKing("white");

            if (bKingPos.first == -1 && bKingPos.second == -1) {
                cout << "The black king is not on the board" << endl;
            } else if (wKingPos.first == -1 && wKingPos.second == -1) {
                cout << "The white king is not on the board" << endl;
            } else if (b.isCheck("black", bKingPos.first, bKingPos.second) || b.isCheck("white", wKingPos.first, wKingPos.second)) {
                cout << "Your black/white king is in check!!" << endl;
            } else {
                cout << "Setup Mode Exited" << endl;
                break;
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
                    if (b.checkAdjacentKings(x, y)) {
                        cout << "Cannot place a king there as the kings are beside each other!" << endl;
                    } else if (b.isCheck("white", x, y)) {
                        cout << "King in check, cannot move there" << endl;
                    } else {
                        b.setPiece(new King("white"), x, y);
                    }
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
                    if (b.checkAdjacentKings(x, y)) {
                        cout << "Cannot place a king there as the kings are beside each other!" << endl;
                    } else if (b.isCheck("black", x, y)) {
                        cout << "King in check, cannot move there" << endl;
                    } else {
                        b.setPiece(new King("black"), x, y);
                    }
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
            } else if (c == "-") {
                // need to check if nothing is on board -> then hasSetup = false;
                cin >> arg2;
                if (arg2.size() == 2) {
                    int x = arg2[0] - 'a';
                    int y = abs(arg2[1] - '0' - 8);
                    if (b.getSquare(x, y)->checkOccupied() == true) {
                        b.removePieceSetup(x, y);
                    }
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
            notifyObservers(); 
        }
    }

}

void Game::displayScore() {
    cout << "Final Score:" << endl;
    cout << "White: " << whiteScore << endl;
    cout << "Black: " << blackScore  << endl;
}

void Game::move(Player* p, string iPos, string fPos, bool& isKingInCheck) {
    int curX = iPos[0] - 'a';
    int curY = abs(iPos[1] - '0' - 8);
    int newX = fPos[0] - 'a';
    int newY = abs(fPos[1] - '0' - 8);

    Move m = p->turnMove(curX, curY, newX, newY, b); 
    if (m.piece == nullptr) {
        return; 
    } else if (p->getColour() != m.piece->getColor()) {
        cout << "It is " << p->getColour() << " player's turn!"<< endl;
        return;
    }
    

    // cout << "The move coordinates are: (" << m.oldX << "," << m.oldY << ") -> (" << m.newX << "," << m.newY << ")" << endl;

    if (m.valid) {
        cout << "Valid Move." << endl;
 
        b.movePiece(m.oldX, m.oldY, m.newX, m.newY);
        if (m.piece->getHasMoved() == false) {
            m.piece->setHasMoved(true);
        }

        // valid moves returns moves that make sure the king will not be in check. So we safely turn this to false
        isKingInCheck = false;
        turn++;
    } else {
        cout << "Not a valid move." << endl;
    }
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
        if (p2[8] == '2') {
            pB = new Level2("black", true);
        }
    }
    else if (p1 != "human" && p2 == "human") {
        pB = new Human("black", false);
        if (p1[8] == '1') {
            pW = new Level1("white", true);
        }
        if (p1[8] == '2') {
            pW = new Level2("white", true);
        }
    }
    else if (p1 != "human" && p2 != "human") {
        if (p1[8] == '1') {
            pB = new Level1("black", true);
        }
        if (p2[8] == '1') {
            pW = new Level1("white", true);
        }
        if (p1[8] == '2') {
            pB = new Level2("black", true);
        }
        if (p2[8] == '2') {
            pW = new Level2("white", true);
        }
    }

}

void Game::helpMenu() {
    cout << "Here are the list of commands:" << endl;
    cout << "setup - You can setup your board. Use the 'default' command to get a basic chess board or make your custom chess positions!" << endl;
    cout << "game - You can initialize your players, i.e. who is black or white and if you want to face against a computer. The command takes in 3 arguments as follows: <game> <player1> <player2> where player1 and player2 are either human or computer1, computer2, computer3, computer4 " << endl;
    cout << "move - Once you used both of these commands, you can move a piece to start your game" << endl;
    cout << "Note that you cannot go back to setup and game once initialized" << endl;
}

void Game::play() {
    cout << "Welcome to our CS247 Project - Chess in C++ - Made by Jerome and Maahir" << endl;
    bool isWhiteinCheck = false;
    bool isBlackinCheck = false;
    while (true) {
        string input;
        // EOF break game loop
        if (!getline(cin, input)) {
            displayScore();
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
            // cout << turn << endl;
            string iPos;
            string fPos;
            if (turn % 2 == 0) {
                // white turn's move
                cout << "Player 1 (White) Move" << endl;
                if (!pW->getBool()) {
                    ss >> iPos;
                    ss >> fPos;
                    move(pW, iPos, fPos, isWhiteinCheck); 
                } 
                else {
                    move(pW, "a2", "a3", isWhiteinCheck);
                }
                // if white is not in check, next turn.
            } else {
                cout << "Player 2 (Black) Move" << endl;
                if (!pB->getBool()) {
                    ss >> iPos;
                    ss >> fPos;
                    move(pB, iPos, fPos, isBlackinCheck); 
                } else {
                    move(pB, "a2", "a3", isBlackinCheck);
                }
                // if black is not in check, next turn.
            }
            // winning conditions
            b.printBoard();
            notifyObservers();
            pair<int, int> whiteKingPos = b.findKing("white");
            pair<int, int> blackKingPos = b.findKing("black");

            if (isStalemate("white") || isStalemate("black")) {
                cout << "Stalemate!" << endl;
                whiteScore += 0.5;
                blackScore += 0.5;
                reset();
            } else if (isCheckmate("white")) {
                cout << "Checkmate! White wins!" << endl;
                blackScore++;
                reset();
            } else if (isCheckmate("black")) {
                cout << "Checkmate! Black wins!" << endl;
                whiteScore++;
                reset();
            } else if (b.isCheck("white", whiteKingPos.first, whiteKingPos.second)) {
                isWhiteinCheck = true;
                cout << "White is in check." << endl;
            } else if (b.isCheck("black", blackKingPos.first, blackKingPos.second)) {
                isBlackinCheck = true;
                cout << "Black is in check." << endl;
            } 
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

Board& Game::getBoard() {
    return b; 
}

Game::~Game() {
    delete pW;
    delete pB;
}
