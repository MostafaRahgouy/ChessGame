#ifndef PAWN_H
#define PAWN_H
#include <iostream>
#include <string>
#include "Piece.h"
using namespace std ;
//**********************************************************************************************************************************************************
class Pawn:public Piece
{
    public:
        Pawn( Posation , PieceColor );
        virtual ~Pawn();
        virtual PieceType getPieceType( );
        virtual bool canGoTo(int, int, BoardCellType**);
        //virtual vector< Posation > getPathTo( int , int , string ** ) ;
    protected:
    private:
};
//**********************************************************************************************************************************************************
#endif // PAWN_H
