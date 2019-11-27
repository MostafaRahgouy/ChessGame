#ifndef BISHOP_H
#define BISHOP_H
#include <iostream>
#include <string>
#include "Piece.h"
#include "Game.h"
using namespace std ;
//**********************************************************************************************************************************************************
class Bishop:public Piece
{
    public:
        Bishop( Posation , PieceColor );
        virtual ~Bishop();
        virtual PieceType getPieceType();
        virtual bool canGoTo(int, int, BoardCellType**);
        virtual vector< Posation > getPathTo(int, int, BoardCellType **);
    protected:
    private:
};
//**********************************************************************************************************************************************************
#endif // BISHOP_H
