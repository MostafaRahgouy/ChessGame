#include "movevalidator.h"
#include <iostream>
#include <string>
#include <cmath>
#include <Piece.h>
#include <PieceColor.h>
#include <vector>
using namespace std;
//*****************************************************************************************************************************************************
bool MoveValidator::canGoToKing( int rowS , int colS , int rowT , int colT , BoardCellType **p )
{
    return abs( rowS - rowT ) < 2 && abs( colS - colT ) < 2;
}
//*****************************************************************************************************************************************************
bool MoveValidator::canGoToKnight( int rowS , int colS , int rowT , int colT , BoardCellType **p )
{
    return ( abs( rowS - rowT ) == 2 && abs( colS - colT ) == 1 ) || ( abs( colS - colT ) == 2 && abs( rowS - rowT ) == 1 );
}
//*****************************************************************************************************************************************************
bool MoveValidator::canGoToPawn( int rowS , int colS , int rowT , int colT , BoardCellType **p , PieceColor color )
{
    int direction = color == WHITE ? -1 : 1;
    int firstRow = color == WHITE ? 1 : 6;
    return
        ( p[rowT][colT] == NONE && rowS == rowT + direction && colS == colT ) ||
        ( p[rowT][colT] != NONE && rowS == rowT + direction && abs( colS - colT ) == 1 ) ||
        ( p[rowT][colT] == NONE && rowS == rowT + 2 * direction && colS == colT && rowS == firstRow );
}
//*****************************************************************************************************************************************************
bool MoveValidator::canGoToRock( int rowS , int colS , int rowT , int colT , BoardCellType **p )
{
    vector< Posation > v = MoveValidator::getPathRock( rowS , colS , rowT , colT , p );
    if( v.size() == 0 )
        return false;
    Posation target = v.back();
    return target.isEqual( rowT , colT );
}
//*****************************************************************************************************************************************************
bool MoveValidator::canGoToBishop( int rowS , int colS , int rowT , int colT , BoardCellType **p )
{
    vector< Posation > v = MoveValidator::getPathBishop( rowS , colS , rowT , colT , p );
    if( v.size() == 0 )
        return false;
    Posation target = v.back();
    return target.isEqual( rowT , colT );
}
//*****************************************************************************************************************************************************
bool MoveValidator::canGoToQueen( int rowS , int colS , int rowT , int colT , BoardCellType **p )
{
    vector< Posation > v = MoveValidator::getPathRock( rowS , colS , rowT , colT , p );
    if( v.size() == 0 )
    {
        v = MoveValidator::getPathBishop( rowS , colS , rowT , colT , p );
    }
    if( v.size() == 0 )
    {
        return false;
    }
    Posation target = v.back();
    return target.isEqual( rowT , colT );
}
//*****************************************************************************************************************************************************
vector< Posation > MoveValidator::getPathRock( int rowS , int colS , int rowT , int colT , BoardCellType **p )
{
    vector< Posation > v;
    if( rowS != rowT && colS != colT )
    {
        return v;
    }
    int direction = 1;
    if( rowS > rowT || colS > colT )
    {
        direction = -1;
    }
    while( rowS != rowT )
    {
        rowS += direction;
        v.push_back( Posation( rowS , colS ) );
        if( p[rowS][colS] != NONE && rowS != rowT )
        {
            break;
        }
    }
    while( colS != colT )
    {
        colS += direction;
        v.push_back( Posation( rowS , colS ) );
        if( p[rowS][colS] != NONE && colS != colT )
        {
            break;
        }
    }
    return v;

}
//*****************************************************************************************************************************************************
vector< Posation > MoveValidator::getPathBishop( int rowS , int colS , int rowT , int colT , BoardCellType **p )
{
    vector< Posation > v;
    if( !( ( rowS - colS == rowT - colT ) || ( rowS + colS == rowT + colT ) ) )
    {
        return v;
    }
    int directionRow = 1 , directionCol = 1;
    if( rowS > rowT )
    {
        directionRow = -1;
    }
    if( colS > colT )
    {
        directionCol = -1;
    }
    rowS += directionRow;
    colS += directionCol;
    v.push_back( Posation( rowS , colS ) );
    while( rowS != rowT && colS != colT )
    {
        if( p[rowS][colS] != NONE )
        {
            break;
        }
        rowS += directionRow;
        colS += directionCol;
        v.push_back( Posation( rowS , colS ) );
    }
    return v;

}
//*****************************************************************************************************************************************************
