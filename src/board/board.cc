#include "board.h"

Board::Board(int width, int height):  height{height}, width{width} {
    bool isWhite = true;
    vector<Square*> row;
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            if (isWhite) {
                row.push_back(new Square("white", j, i));
            } else {
                row.push_back(new Square("black", j, i));
            }
            isWhite = !isWhite;
        }
        board.push_back(row);
        row.clear();
        isWhite = !isWhite;
    }
}

// move a piece from current (x, y) to new (x, y)
void Board::movePiece(int curX, int curY, int newX, int newY) {
    // only move the piece if the current (x, y) contains a piece
    if (board[curY][curX]->checkOccupied()) {
        Piece *toSwapPiece = board[curY][curX]->getPieceOnSquare();
        // check if the new (x, y) contains a piece (capture)
        if (board[newY][newX]->checkOccupied() == true) {
            board[newY][newX]->capturePieceOnSquare();
        }
        // move the piece current (x, y) -> new (x, y)
        board[newY][newX]->setPieceOnSquare(toSwapPiece);
        board[curY][curX]->removePieceOnSquare();
    }
}

void Board::reset() {
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            if (getSquare(j, i)->checkOccupied() == true) {
                getSquare(j, i)->capturePieceOnSquare();
            }
        }
    }
}

bool Board::isMoveAllowed(int curX, int curY, int newX, int newY) {
    Piece *pieceToMove = getPiece(curX, curY);
    string color = pieceToMove->getColor();
    bool isCapturedSquare = false;
    Piece *tempPiece;
    // check if the place to move has a piece
    if (getSquare(newX, newY)->checkOccupied() == true) {
        // store it in a temporary variable
        tempPiece = getPiece(newX, newY);
        isCapturedSquare = true;
    }

    // cout << "Moving (" << curX << ", " << curY << ") to (" << newX << ", " << newY << ")" << endl; 
    // move the piece temporarily to the new (x, y)
    swapPiece(curX, curY, newX, newY);

    pair<int, int> kingPos = findKing(color);
    // printBoard();
    
    // check if the new board after moving the piece makes it so that the king is in check.
    bool isCheckedAfterMove = isCheck(color, kingPos.first, kingPos.second);


    // move the piece back
    swapPiece(newX, newY, curX, curY);
    
    // the piece previously in the new (x, y) needs to be restored
    if (isCapturedSquare == true) {
        setPiece(tempPiece, newX, newY);
    }
    
    return !isCheckedAfterMove;
}

pair<int, int> Board::findKing(string color) {
    pair<int, int> position;
    bool breaked = false;
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            if (board[i][j]->checkOccupied() == true && getPiece(j, i)->getColor() == color && tolower(getPiece(j, i)->getType()) == 'k') {
                position.first = j;
                position.second = i;
                breaked = true;
                break;
            }
        }
        if (breaked) {
            break;
        }
    }

    if (breaked == false) {
        return {-1, -1};
    }

    return position;
}


bool Board::checkAdjacentKings(int x, int y) {
    vector<int> dx = {1, 1, 1, -1, -1, -1, 0, 0};
    vector<int> dy = {1, -1, 0, 1, -1, 0, 1, -1};

    for (int i=0; i<8; i++) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (0 <= tx && tx < getWidth() && 0 <= ty && ty < getHeight()) {
            if (getSquare(tx, ty)->checkOccupied() == true && tolower(getPiece(tx, ty)->getType()) == 'k') {
                return true;
            }
        }
    }
    return false;
}


bool Board::checkBounds(int x, int y) {
    if ((0 <= x && x < width) && (0 <= y && y < height)) {
        return true;
    }
    return false;
}

bool Board::isCheck(string color, int x, int y) { // king's position
    // cout << "printing board for : " << x << ", " << y << endl;
    // printBoard();

    if (checkBounds(x+1, y)) {
        for (int i=x+1; i < width; i++) {
            if ((getSquare(i, y)->checkOccupied() == true && getSquare(i, y)->getPieceOnSquare()->getColor() == color) ||
                (getSquare(i, y)->checkOccupied() == true && getSquare(i, y)->getPieceOnSquare()->getColor() != color 
                && tolower(getPiece(i, y)->getType()) != 'q' && tolower(getPiece(i, y)->getType()) != 'r')) {
                break;
            } else if (getSquare(i, y)->checkOccupied() == true && getPiece(i, y)->getColor() != color && (tolower(getPiece(i, y)->getType()) == 'q' || tolower(getPiece(i, y)->getType()) == 'r')) {

                //cout << getPiece(i, y)->getType() << " (" << i << ", " << y << ") puts it in check" << endl;
                return true;
            }
        }
    }

    // going left
    if (checkBounds(x-1, y)) {
        for (int i=x-1; i >= 0; i--) {
            if ((getSquare(i, y)->checkOccupied() == true && getSquare(i, y)->getPieceOnSquare()->getColor() == color) ||
                (getSquare(i, y)->checkOccupied() == true && getSquare(i, y)->getPieceOnSquare()->getColor() != color 
                && tolower(getPiece(i, y)->getType()) != 'q' && tolower(getPiece(i, y)->getType()) != 'r')) {
                break;
            } else if (getSquare(i, y)->checkOccupied() == true && getPiece(i, y)->getColor() != color && (tolower(getPiece(i, y)->getType()) == 'q' || tolower(getPiece(i, y)->getType()) == 'r')) {

                //cout << getPiece(i, y)->getType() << " (" << i << ", " << y << ") puts it in check" << endl;

                return true;
            }
        }
    } 

    // going down
    if (checkBounds(x, y+1)) {
        for (int i=y+1; i < height; i++) {
            if ((getSquare(x, i)->checkOccupied() == true && getSquare(x, i)->getPieceOnSquare()->getColor() == color) || 
                (getSquare(x, i)->checkOccupied() == true && getSquare(x, i)->getPieceOnSquare()->getColor() != color 
                && tolower(getPiece(x, i)->getType()) != 'q' && tolower(getPiece(x, i)->getType()) != 'r')) {
                break;
            } else if (getSquare(x, i)->checkOccupied() == true && getPiece(x, i)->getColor() != color && (tolower(getPiece(x, i)->getType()) == 'q' || tolower(getPiece(x, i)->getType()) == 'r')) {

                //cout << getPiece(x, i)->getType() << " (" << x << ", " << i << ") puts it in check" << endl;

                return true;
            }
        }
    }

    // going up
    if (checkBounds(x, y-1)) {
        for (int i=y-1; i >= 0; i--) {
            if ((getSquare(x, i)->checkOccupied() == true && getSquare(x, i)->getPieceOnSquare()->getColor() == color) ||
                (getSquare(x, i)->checkOccupied() == true && getSquare(x, i)->getPieceOnSquare()->getColor() != color 
                && tolower(getPiece(x, i)->getType()) != 'q' && tolower(getPiece(x, i)->getType()) != 'r')) {
                break;
            } else if (getSquare(x, i)->checkOccupied() == true && getPiece(x, i)->getColor() != color && (tolower(getPiece(x, i)->getType()) == 'q' || tolower(getPiece(x, i)->getType()) == 'r')) {

                //cout << getPiece(x, i)->getType() << " (" << x << ", " << i << ") puts it in check" << endl;

                return true;
            }
        }
    }
    
    // queen and bishop

    // northwest
    int tx = x - 1;
    int ty = y - 1;
    while (checkBounds(tx, ty)) {
        if ((getSquare(tx, ty)->checkOccupied() == true && getSquare(tx, ty)->getPieceOnSquare()->getColor() == color) || 
            (getSquare(tx, ty)->checkOccupied() == true && getSquare(tx, ty)->getPieceOnSquare()->getColor() != color 
            && tolower(getPiece(tx, ty)->getType()) != 'q' && tolower(getPiece(tx, ty)->getType()) != 'b')) {
            break;
        } else if (getSquare(tx, ty)->checkOccupied() == true && getPiece(tx, ty)->getColor() != color && (tolower(getPiece(tx, ty)->getType()) == 'q' || tolower(getPiece(tx, ty)->getType()) == 'b')) {

            //cout << getPiece(tx, ty)->getType() << " (" << tx << ", " << ty << ") puts it in check" << endl;

            return true;
        }
        tx--;
        ty--;
    }

    tx = x + 1;
    ty = y + 1;
    while (checkBounds(tx, ty)) {
        if ((getSquare(tx, ty)->checkOccupied() == true && getSquare(tx, ty)->getPieceOnSquare()->getColor() == color) || 
            (getSquare(tx, ty)->checkOccupied() == true && getSquare(tx, ty)->getPieceOnSquare()->getColor() != color 
            && tolower(getPiece(tx, ty)->getType()) != 'q' && tolower(getPiece(tx, ty)->getType()) != 'b')) {
            break;
        } else if (getSquare(tx, ty)->checkOccupied() == true && getPiece(tx, ty)->getColor() != color && (tolower(getPiece(tx, ty)->getType()) == 'q' || tolower(getPiece(tx, ty)->getType()) == 'b')) {

            //cout << getPiece(tx, ty)->getType() << " (" << tx << ", " << ty << ") puts it in check" << endl;

            return true;
        }
        tx++;
        ty++;
    }
    tx = x - 1;
    ty = y + 1;
    while (checkBounds(tx, ty)) {
        if ((getSquare(tx, ty)->checkOccupied() == true && getSquare(tx, ty)->getPieceOnSquare()->getColor() == color) || 
            (getSquare(tx, ty)->checkOccupied() == true && getSquare(tx, ty)->getPieceOnSquare()->getColor() != color 
            && tolower(getPiece(tx, ty)->getType()) != 'q' && tolower(getPiece(tx, ty)->getType()) != 'b')) {
            break;
        } else if (getSquare(tx, ty)->checkOccupied() == true && getPiece(tx, ty)->getColor() != color && (tolower(getPiece(tx, ty)->getType()) == 'q' || tolower(getPiece(tx, ty)->getType()) == 'b')) {

            //cout << getPiece(tx, ty)->getType() << " (" << tx << ", " << ty << ") puts it in check" << endl;

            return true;
        }
        tx--;
        ty++;
    }
    tx = x + 1;
    ty = y - 1;
    while (checkBounds(tx, ty)) {
        if ((getSquare(tx, ty)->checkOccupied() == true && getSquare(tx, ty)->getPieceOnSquare()->getColor() == color) || 
            (getSquare(tx, ty)->checkOccupied() == true && getSquare(tx, ty)->getPieceOnSquare()->getColor() != color 
            && tolower(getPiece(tx, ty)->getType()) != 'q' && tolower(getPiece(tx, ty)->getType()) != 'b')) {
            break;
        } else if (getSquare(tx, ty)->checkOccupied() == true && getPiece(tx, ty)->getColor() != color && (tolower(getPiece(tx, ty)->getType()) == 'q' || tolower(getPiece(tx, ty)->getType()) == 'b')) {

            //cout << getPiece(tx, ty)->getType() << " (" << tx << ", " << ty << ") puts it in check" << endl;

            return true;
        }
        tx++;
        ty--;
    }

    // knight
    vector<int> dx = {-1, -2, -2, -1, 1, 2,  2,  1};
    vector<int> dy = {-2, -1,  1,  2, 2, 1, -1, -2};
    for (int i=0; i<8; i++) {
        int newX = dx[i] + x;
        int newY = dy[i] + y;
        if (checkBounds(newX, newY)) {
            if (getSquare(newX, newY)->checkOccupied() == true && getPiece(newX, newY)->getColor() != color && tolower(getPiece(newX, newY)->getType()) == 'n') {
                //cout << getPiece(newX, newY)->getType() << " (" << newX << ", " << newY << ") puts it in check" << endl;
                return true;
            }
        }
    }

    // pawn
    if (color == "white") {
        if ( (checkBounds(x - 1, y - 1) && getSquare(x - 1, y - 1)->checkOccupied() == true && getPiece(x - 1, y - 1)->getType() == 'p') ||
             (checkBounds(x + 1, y - 1) && getSquare(x + 1, y - 1)->checkOccupied() == true && getPiece(x + 1, y - 1)->getType() == 'p')) {

            //cout << "pawn puts in check" << endl;

            return true;
        }
    } else if (color == "black") {
        if ( (checkBounds(x + 1, y + 1) && getSquare(x + 1, y + 1)->checkOccupied() == true && getPiece(x + 1, y + 1)->getType() == 'P') ||
             (checkBounds(x - 1, y + 1) && getSquare(x - 1, y + 1)->checkOccupied() == true && getPiece(x - 1, y + 1)->getType() == 'P')) {

            //cout << "pawn puts in check" << endl;

            return true;
        }
    }

    return false;
}

bool Board::isMoveCheck(int curX, int curY, int newX, int newY) {
    Piece *pieceToMove = getPiece(curX, curY);
    string color = pieceToMove->getColor();
    bool isCapturedSquare = false;
    Piece *tempPiece;
    // check if the place to move has a piece
    if (getSquare(newX, newY)->checkOccupied() == true) {
        // store it in a temporary variable
        tempPiece = getPiece(newX, newY);
        isCapturedSquare = true;
    }

    // cout << "Moving (" << curX << ", " << curY << ") to (" << newX << ", " << newY << ")" << endl; 
    // move the piece temporarily to the new (x, y)
    swapPiece(curX, curY, newX, newY);

    if (color == "black") {
        color = "white"; 
    }
    else if (color == "white") {
        color = "black"; 
    }

    pair<int, int> kingPos = findKing(color);
    // printBoard();
    
    // check if the new board after moving the piece makes it so that the king is in check.
    bool isCheckedAfterMove = isCheck(color, kingPos.first, kingPos.second);


    // move the piece back
    swapPiece(newX, newY, curX, curY);
    
    // the piece previously in the new (x, y) needs to be restored
    if (isCapturedSquare == true) {
        setPiece(tempPiece, newX, newY);
    }
    
    return isCheckedAfterMove;

}

Piece* Board::getPiece(int x, int y) {
    if (board[y][x]->getPieceOnSquare() == nullptr) {
        return nullptr;
    }
    Piece* outPiece = board[y][x]->getPieceOnSquare();
    return outPiece;
}

void Board::setPiece(Piece *p, int x, int y) {
    if(board[y][x]->checkOccupied() == true) {
        board[y][x]->capturePieceOnSquare();
    }
    board[y][x]->setPieceOnSquare(p);
}

void Board::removePiece(int x, int y) {
    if (board[y][x]->checkOccupied() == true) {
        board[y][x]->removePieceOnSquare();
    }  
}


void Board::swapPiece(int curX, int curY, int newX, int newY) {
    if (board[curY][curX]->checkOccupied()) {
        Piece *toSwapPiece = board[curY][curX]->getPieceOnSquare();
        board[newY][newX]->setPieceOnSquare(toSwapPiece);
        board[curY][curX]->removePieceOnSquare();
    }
}

void Board::removePieceSetup(int x, int y) {
    if (board[y][x]->checkOccupied() == true) {
        board[y][x]->capturePieceOnSquare();
    }
}

void Board::printBoard() {
    for (int i=0; i<height; i++) {
        cout << 8-i << " ";
        for (int j=0; j<width; j++) {
            if (board[i][j]->checkOccupied() == false) {
                if (board[i][j]->getColor() == "white") {
                    cout << " ";
                } else {
                    cout << "_";
                }
            } else {
                cout << board[i][j]->getPieceOnSquare()->getType();
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << "  abcdefgh" << endl << endl;
}

int Board::getHeight() {
    return height;
}

int Board::getWidth() {
    return width;
}

Square* Board::getSquare(int x, int y) {
    return board[y][x];
}

Board::~Board() {
    for (int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            delete board[i][j];
        }
    }
}
