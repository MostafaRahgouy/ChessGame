#ifndef QUEEN_H
#define QUEEN_H
#include <iostream>
#include <string>
#include "Piece.h"
//**********************************************************************************************************************************************************
class Queen:public Piece
{
    public:
        Queen( Posation , PieceColor );
        virtual ~Queen();
        virtual PieceType getPieceType( );
        virtual bool canGoTo(int, int, BoardCellType **);
    protected:
    private:
};
//**********************************************************************************************************************************************************
#endif // QUEEN_H
