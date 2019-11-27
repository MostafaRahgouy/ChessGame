#ifndef KING_H
#define KING_H
#include <iostream>
#include <string>
#include "Piece.h"
using namespace std ;
//**********************************************************************************************************************************************************
class King:public Piece
{
    public:
        King( Posation , PieceColor );
        virtual ~King();
        virtual PieceType getPieceType( );
        virtual bool canGoTo(int, int, BoardCellType**);
    protected:
    private:
};
//**********************************************************************************************************************************************************
#endif // KING_H
