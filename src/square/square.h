#include "../piece/piece.h"
#include <string>

using namespace std;

class Square {
    private:
        Piece p;
        int x, y;
        string color;
        bool isOccupied = false;
    public:
        Square();
        Piece getPieceOnSquare();
        bool checkOccupied();
        void setPieceOnSquare(Piece p, int, int);
        int getX();
        int getY();
        string getColor();
};