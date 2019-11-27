

#include "BoardCellType.h"
//*********************************************************************************************************************
char boardCellTypeToChar(BoardCellType t)
{
    switch (t)
    {
    case NONE:
        return ' ';
    case KING_WHITE:
        return 'K';
    case QUEEN_WHITE:
        return 'Q';
    case KNIGHT_WHITE:
        return 'C';
    case BISHOP_WHITE:
        return 'B';
    case ROCK_WHITE:
        return 'R';
    case PAWN_WHITE:
        return 'P';
    case KING_BLACK:
        return 'k';
    case QUEEN_BLACK:
        return 'q';
    case KNIGHT_BLACK:
        return 'c';
    case BISHOP_BLACK:
        return 'b';
    case ROCK_BLACK:
        return 'r';
    case PAWN_BLACK:
        return 'p';
    }
}
//*********************************************************************************************************************
