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


void Board::movePiece(int curX, int curY, int newX, int newY) {
    if (board[curY][curX]->checkOccupied()) {
        Piece *toSwapPiece = board[curY][curX]->getPieceOnSquare();
        if (board[newY][newX]->checkOccupied() == true) {
            board[newY][newX]->capturePieceOnSquare();
        }
        board[newY][newX]->setPieceOnSquare(toSwapPiece);
        board[curY][curX]->removePieceOnSquare();
    }
}

bool Board::isMoveAllowed(int curX, int curY, int newX, int newY) {
    Piece *pieceToMove = getPiece(curX, curY);
    string color = pieceToMove->getColor();
    pair<int, int> kingPos = findKing(color);
    bool isCapturedSquare = false;
    Piece *tempPiece;

    // cout << "before swap" << endl;
    if (getSquare(newX, newY)->checkOccupied() == true) {
        tempPiece = getPiece(newX, newY);
        isCapturedSquare = true;
    }
    swapPiece(curX, curY, newX, newY);
    // cout << kingPos.first << ", " << kingPos.second << endl;
    // cout << "printing Board before isCheck" << endl;
    // printBoard();
    // printBoard();
    bool isCheckedAfterMove = isCheck(color, kingPos.first, kingPos.second);
    

    swapPiece(newX, newY, curX, curY);
    if (isCapturedSquare == true) {
        setPiece(tempPiece, newX, newY);
    }
    // cout << "after swap" << endl;
    // printBoard();
    // move the piece, check if it is in check.
    return !isCheckedAfterMove;
}


Board::Board(const Board& other): height(other.height), width(other.width), board(other.height, vector<Square*>(other.width, nullptr)) {
    for (int i=0; i < height; i++) {
        for (int j=0; j < width; j++) {
                board[i][j] = new Square(*other.board[i][j]);
        }
    }
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
    // queen and rook
    // going right
    // cout << "printing board in ischeck" << endl;
    // printBoard();
    for (int i=x; i < width; i++) {
        if (x != i && getSquare(i, y)->checkOccupied() == true && getSquare(i, y)->getPieceOnSquare()->getColor() == color ) {
            break;
        } else if (x != i && getSquare(i, y)->checkOccupied() == true && (tolower(getPiece(i, y)->getType()) == 'q' || tolower(getPiece(i, y)->getType()) == 'r')) {
            return true;
        }
    }

    // going left
    for (int i=x; i >= 0; i--) {
        if (x != i && getSquare(i, y)->checkOccupied() == true && getSquare(i, y)->getPieceOnSquare()->getColor() == color){
            break;
        } else if (x != i && getSquare(i, y)->checkOccupied() == true && (tolower(getPiece(i, y)->getType()) == 'q' || tolower(getPiece(i, y)->getType()) == 'r')) {
            return true;
        }
    }
    // going down
    for (int i=y; i < height; i++) {
        if (y != i && getSquare(x, i)->checkOccupied() == true && getSquare(x, i)->getPieceOnSquare()->getColor() == color) {
            break;
        } else if (y != i && getSquare(x, i)->checkOccupied() == true && (tolower(getPiece(x, i)->getType()) == 'q' || tolower(getPiece(x, i)->getType()) == 'r')) {
            return true;
        }
    }

    // going up
    for (int i=y; i >= 0; i--) {
        if (y != i && getSquare(x, i)->checkOccupied() == true && getSquare(x, i)->getPieceOnSquare()->getColor() == color) {
            break;
        } else if (y != i && getSquare(x, i)->checkOccupied() == true && (tolower(getPiece(x, i)->getType()) == 'q' || tolower(getPiece(x, i)->getType()) == 'r')) {
            return true;
        }
    }
    
    // queen and bishop

    // northwest
    int tx = x - 1;
    int ty = y - 1;
    while (checkBounds(tx, ty)) {
        if (getSquare(tx, ty)->checkOccupied() == true && getSquare(tx, ty)->getPieceOnSquare()->getColor() == color) {
            break;
        } else if (getSquare(tx, ty)->checkOccupied() == true && (tolower(getPiece(tx, ty)->getType()) == 'q' || tolower(getPiece(tx, ty)->getType()) == 'b')) {
            return true;
        }
        tx--;
        ty--;
    }

    tx = x + 1;
    ty = y + 1;
    while (checkBounds(tx, ty)) {
        if (getSquare(tx, ty)->checkOccupied() == true && getSquare(tx, ty)->getPieceOnSquare()->getColor() == color) {
            break;
        } else if (getSquare(tx, ty)->checkOccupied() == true && (tolower(getPiece(tx, ty)->getType()) == 'q' || tolower(getPiece(tx, ty)->getType()) == 'b')) {
            return true;
        }
        tx++;
        ty++;
    }
    tx = x - 1;
    ty = y + 1;
    while (checkBounds(tx, ty)) {
        if (getSquare(tx, ty)->checkOccupied() == true && getSquare(tx, ty)->getPieceOnSquare()->getColor() == color) {
            break;
        } else if (getSquare(tx, ty)->checkOccupied() == true && (tolower(getPiece(tx, ty)->getType()) == 'q' || tolower(getPiece(tx, ty)->getType()) == 'b')) {
            return true;
        }
        tx--;
        ty++;
    }
    tx = x + 1;
    ty = y - 1;
    while (checkBounds(tx, ty)) {
        if (getSquare(tx, ty)->checkOccupied() == true && getSquare(tx, ty)->getPieceOnSquare()->getColor() == color) {
            break;
        } else if (getSquare(tx, ty)->checkOccupied() == true && (tolower(getPiece(tx, ty)->getType()) == 'q' || tolower(getPiece(tx, ty)->getType()) == 'b')) {
            return true;
        }
        tx++;
        ty--;
    }

    // knight
    vector<int> dx = {-1, -2, -2, -1, 1, 2, 2, 1};
    vector<int> dy = {-2, -1, 1, 2, 2, 1, -1, -2};
    for (int i=0; i<8; i++) {
        int newX = dx[i] + x;
        int newY = dy[i] + y;
        if (checkBounds(newX, newY)) {
            if (getSquare(newX, newY)->checkOccupied() == true && getPiece(newX, newY)->getColor() != color && tolower(getPiece(newX, newY)->getType()) == 'n') {
                return true;
            }
        }
    }

    // pawn
    if (color == "white") {
        if ( (checkBounds(x + 1, y + 1) && getSquare(x + 1, y + 1)->checkOccupied() == true && getPiece(x + 1, y + 1)->getType() == 'p') ||
             (checkBounds(x - 1, y + 1) && getSquare(x - 1, y + 1)->checkOccupied() == true && getPiece(x - 1, y + 1)->getType() == 'p')) {
            return true;
        }
    } else if (color == "black") {
        if ( (checkBounds(x + 1, y - 1) && getSquare(x + 1, y - 1)->checkOccupied() == true && getPiece(x + 1, y - 1)->getType() == 'P') ||
             (checkBounds(x - 1, y - 1) && getSquare(x - 1, y - 1)->checkOccupied() == true && getPiece(x - 1, y - 1)->getType() == 'P')) {
            return true;
        }
    }

    return false;
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