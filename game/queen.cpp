#include "Queen.h"
#include <iostream>
#include <string>
#include <Piece.h>
#include <math.h>
#include <Rock.h>
#include <Bishop.h>
#include <movevalidator.h>
//**********************************************************************************************************************************************************
Queen::Queen( Posation p , PieceColor color )
:Piece( p , color )
{
    //ctor
}
//**********************************************************************************************************************************************************
Queen::~Queen()
{
    //dtor
}
//**********************************************************************************************************************************************************
PieceType Queen::getPieceType( )
{
    return QUEEN ;
}
//**********************************************************************************************************************************************************
bool Queen::canGoTo(int rowT, int colT, BoardCellType **p)
{
    return MoveValidator::canGoToQueen( getPosation().getRow() , getPosation().getCol() , rowT , colT , p ) ;
}
//**********************************************************************************************************************************************************
