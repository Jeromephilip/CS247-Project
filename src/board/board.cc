#include "board.h"

Board::Board(int width, int height): width{width}, height{height} {
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

Piece* Board::getPiece(int x, int y) {
    Piece* outPiece = board[y][x]->getPieceOnSquare();
    return outPiece;
}

void Board::movePiece(int curX, int curY, int newX, int newY) {
    Piece *pieceToMove = board[curY][curY]->getPieceOnSquare();
    board[newY][newX]->setPieceOnSquare(pieceToMove);
    board[curY][curX]->removePieceOnSquare();
} 

void Board::setPiece(Piece *p, int x, int y) {
    board[y][x]->setPieceOnSquare(p);
}

void Board::removePiece(int x, int y) {
    board[y][x]->removePieceOnSquare();
}

void Board::printBoard() {
    for (int i=0; i<height; i++) {
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
}