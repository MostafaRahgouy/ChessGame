#include "Piece.h"
#include <iostream>
#include <string>
using namespace std ;
//**********************************************************************************************************************************************************
Piece::Piece(Posation P , PieceColor color )
{
    posation = new Posation(P.getRow() , P.getCol() ) ;
    this->color = color ;
}
//**********************************************************************************************************************************************************
Piece::~Piece()
{
    //dtor
}
//**********************************************************************************************************************************************************
Posation &Piece::getPosation()
{
    return *posation ;
}
//**********************************************************************************************************************************************************
PieceColor Piece::getColor()
{
    return color ;
}
//**********************************************************************************************************************************************************
vector<Posation> Piece::getPathTo(int rowT, int colT, BoardCellType **p)
{
    vector<Posation> v ;
    if( !canGoTo( rowT , colT , p) )
    {
        return v ;
    }
    v.push_back( Posation( rowT , colT ) ) ;
    return v ;
}
//**********************************************************************************************************************************************************
/*char Piece::getBoardCellTypeChar()
{
    return boardCellTypeToChar(getBoardCellType());
}*/
//**********************************************************************************************************************************************************
BoardCellType Piece::getBoardCellType( )
{
    switch( getPieceType() )
    {
        case PAWN:
            return color == WHITE ? PAWN_WHITE : PAWN_BLACK;
        case KING:
            return color == WHITE ? KING_WHITE : KING_BLACK;
        case QUEEN:
            return color == WHITE ? QUEEN_WHITE : QUEEN_BLACK;
        case KNIGHT:
            return color == WHITE ? KNIGHT_WHITE : KNIGHT_BLACK;
        case BISHOP:
            return color == WHITE ? BISHOP_WHITE : BISHOP_BLACK;
        case ROCK:
            return color == WHITE ? ROCK_WHITE : ROCK_BLACK;
    }
}
