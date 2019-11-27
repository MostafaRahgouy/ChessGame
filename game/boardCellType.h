#ifndef BOARDCELLTYPE_H
#define BOARDCELLTYPE_H
#include <PieceColor.h>
#include <string>
#include <iostream>
enum BoardCellType
{
    NONE ,
    KING_WHITE,
    QUEEN_WHITE,
    BISHOP_WHITE,
    ROCK_WHITE,
    KNIGHT_WHITE,
    PAWN_WHITE,
    KING_BLACK,
    QUEEN_BLACK,
    KNIGHT_BLACK,
    ROCK_BLACK,
    PAWN_BLACK,
    BISHOP_BLACK
};
char boardCellTypeToChar(BoardCellType t);
#endif // BOARDCELLTYPE_H
