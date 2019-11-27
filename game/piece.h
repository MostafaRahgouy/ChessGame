#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <string>
#include "Posation.h"
#include "PieceColor.h"
#include <vector>
#include <boardCellType.h>
#include <PieceType.h>
using namespace std ;
//**********************************************************************************************************************************************************
class Piece
{
    public:
        Piece( Posation , PieceColor );
        virtual ~Piece();
        virtual BoardCellType getBoardCellType();
      //  virtual char getBoardCellTypeChar() ;
        virtual bool canGoTo(int, int, BoardCellType**) = 0;
        virtual PieceType getPieceType( ) = 0;
        virtual vector< Posation > getPathTo( int , int , BoardCellType ** );
        Posation &getPosation() ;
        PieceColor getColor() ;
        bool isCaptured = false ;
    protected:
        Posation *posation ;
        PieceColor color ;
    private:
};
//**********************************************************************************************************************************************************
#endif // PIECE_H
