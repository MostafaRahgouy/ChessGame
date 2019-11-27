#include "Bishop.h"
#include <iostream>
#include <string>
#include <math.h>
#include <movevalidator.h>
using namespace std ;
//**********************************************************************************************************************************************************
Bishop::Bishop( Posation p , PieceColor color )
:Piece( p , color )
{
    //ctor
}
//**********************************************************************************************************************************************************
Bishop::~Bishop()
{
    //dtor
}
//**********************************************************************************************************************************************************
PieceType Bishop::getPieceType( )
{
    return BISHOP ;
}
//**********************************************************************************************************************************************************
bool Bishop::canGoTo(int rowT, int colT, BoardCellType **p)
{
    return MoveValidator::canGoToBishop( getPosation().getRow() , getPosation().getCol() , rowT , colT , p ) ;
}
//**********************************************************************************************************************************************************
vector<Posation> Bishop::getPathTo(int rowT, int colT, BoardCellType **p)
{
    return MoveValidator::getPathBishop(getPosation().getRow(), getPosation().getCol(), rowT, colT, p);
}
//**********************************************************************************************************************************************************
