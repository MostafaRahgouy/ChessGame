#ifndef KNIGHT_H
#define KNIGHT_H
#include <iostream>
#include <string>
#include "Piece.h"
using namespace std ;
//**********************************************************************************************************************************************************
class Knight:public Piece
{
    public:
        Knight( Posation , PieceColor );
        virtual ~Knight();
        virtual PieceType getPieceType( );
        virtual bool canGoTo(int, int, BoardCellType**);
    protected:
    private:
};
//**********************************************************************************************************************************************************
#endif // KNIGHT_H
