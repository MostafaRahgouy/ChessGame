#ifndef ROCK_H
#define ROCK_H
#include <iostream>
#include <string>
#include "Piece.h"
#include "Game.h"
//**********************************************************************************************************************************************************
class Rock:public Piece
{
    public:
        Rock( Posation , PieceColor );
        virtual ~Rock();
        virtual PieceType getPieceType();
        virtual bool canGoTo(int, int, BoardCellType**);
        virtual vector< Posation > getPathTo(int, int, BoardCellType **);
    protected:
    private:
};
//**********************************************************************************************************************************************************
#endif // ROCK_H
