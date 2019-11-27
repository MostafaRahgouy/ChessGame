#ifndef MOVEVALIDATOR_H
#define MOVEVALIDATOR_H
#include "PieceColor.h"
#include <iostream>
#include <string>
#include <math.h>
#include "Piece.h"
using namespace std;

class MoveValidator
{
    public:
        static bool canGoToKing(int, int, int, int, BoardCellType **);
        static bool canGoToBishop(int, int, int, int, BoardCellType **);
        static bool canGoToRock(int, int, int, int, BoardCellType **);
        static bool canGoToQueen(int, int, int, int, BoardCellType **);
        static bool canGoToKnight(int, int, int, int, BoardCellType **);
        static bool canGoToPawn(int, int, int, int, BoardCellType **, PieceColor);
        static vector< Posation > getPathRock(int, int, int, int, BoardCellType **);
        static vector< Posation > getPathBishop(int, int, int, int, BoardCellType **);
    protected:
    private:
};

#endif // MOVEVALIDATOR_H
