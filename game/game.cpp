#include "Game.h"
#include <iostream>
#include <string>
#include <Piece.h>
#include <King.h>
#include <Rock.h>
#include <Bishop.h>
#include <Knight.h>
#include <Queen.h>
#include <Pawn.h>
#include <PieceColor.h>
#include <vector>
#include <movevalidator.h>
#include <QString>
using namespace std ;

//**********************************************************************************************************************************************************
Game::Game( PieceType( *getPromotionPieceType )( PieceColor ) )
{
    this->getPromotionPieceType = getPromotionPieceType;
    init() ;
}
//**********************************************************************************************************************************************************
Game::~Game()
{
    //dtor
}
Game::Game()
{
    init();
}

//**********************************************************************************************************************************************************
void Game::init()
{
    int i , j , m = 0 ;
    turn = WHITE ;
    whiteNut = new Piece*[lenghNuts];
    whiteNut[0] = new Rock( Posation( 0 , 0 ) , WHITE ) ;
    whiteNut[1] = new Knight( Posation( 0 , 1 ) , WHITE ) ;
    whiteNut[2] = new Bishop(Posation( 0 , 2 ) , WHITE ) ;
    whiteNut[3] = new Queen( Posation( 0 , 3 ) , WHITE ) ;
    whiteNut[KingPosition] = new King( Posation( 0 , KingPosition ) , WHITE ) ;
    whiteNut[5] = new Bishop( Posation( 0 , 5 ), WHITE ) ;
    whiteNut[6] = new Knight( Posation ( 0 , 6 ) , WHITE ) ;
    whiteNut[7] = new Rock( Posation( 0 , 7 ) , WHITE ) ;
    for( i = 8 ; i < 16 ; i ++ )
    {
        whiteNut[i] = new Pawn( Posation( 1 , i - 8 ) , WHITE ) ;
    }
    blackNut = new Piece*[lenghNuts];
    blackNut[0] = new Rock( Posation( 7 , 0 ) , BLACK ) ;
    blackNut[1] = new Knight( Posation( 7 , 1 ) , BLACK ) ;
    blackNut[2] = new Bishop( Posation( 7 , 2 ) , BLACK ) ;
    blackNut[3] = new Queen( Posation( 7 , 3 ) , BLACK ) ;
    blackNut[KingPosition] = new King( Posation( 7 , KingPosition ) , BLACK ) ;
    blackNut[5] = new Bishop( Posation( 7 , 5 ) , BLACK ) ;
    blackNut[6] = new Knight( Posation ( 7 , 6 ) , BLACK ) ;
    blackNut[7] = new Rock( Posation( 7 , 7 ) , BLACK ) ;

    for( i = 8 ; i < 16 ; i ++ )
    {
        blackNut[i] = new Pawn( Posation( 6 , i - 8 ) , BLACK ) ;
    }

    arrayBoard = new BoardCellType*[8];
    for( i = 0 ; i < 8 ; i ++ )
    {
        arrayBoard[i] = new BoardCellType[8];
        for( j = 0 ; j < 8 ; j ++ )
        {
            arrayBoard[i][j] = NONE;
        }
    }
    for( i = 0 ; i < 16 ; i ++ )
    {
        arrayBoard[whiteNut[i]->getPosation().getRow()][whiteNut[i]->getPosation().getCol()] = whiteNut[i]->getBoardCellType() ;
        arrayBoard[blackNut[i]->getPosation().getRow()][blackNut[i]->getPosation().getCol()] = blackNut[i]->getBoardCellType() ;
    }
}
//**********************************************************************************************************************************************************
BoardCellType** Game::getState()
{
    return arrayBoard ;
}
//**********************************************************************************************************************************************************
bool Game::makeMove( string m , string &msg )
{
    int rowS , colS , rowT , colT ;
    if( m.length() != 4 )
    {
        msg = "invalid move !!!" ;
        return false ;
    }
    colS = ( toupper( m[0] ) - 65 ) ;
    rowS = m[1] - 49 ;
    colT = ( toupper( m[2] ) - 65 )  ;
    rowT = m[3] - 49 ;
    Piece *p = findNut( rowS , colS ) ;
    Piece *q = findNut( rowT , colT ) ;
    if( checkAndMoveNut( p , q , rowT , colT , false ) )
    {
        turn = turn == WHITE ? BLACK : WHITE ;
        setGameFinished();
        setChecked();
        return true ;
    }
    msg = "invalid move !!!" ;
    return false ;
}
//**********************************************************************************************************************************************************
Piece*Game::findNut( int row , int col )
{
    int i ;
    for( i = 0 ; i < lenghNuts ; i ++ )
    {
        if( whiteNut[i]->getPosation().isEqual( row , col ) )
        {
            if( whiteNut[i]->isCaptured == false )
            {
                return whiteNut[i] ;
            }
        }
        if( blackNut[i]->getPosation().isEqual( row , col ) )
        {
            if( blackNut[i]->isCaptured == false )
            {
                return blackNut[i] ;
            }
        }
    }
    return NULL ;
}
//**********************************************************************************************************************************************************
bool Game::isValid( Piece *p , Piece *q , int rowT , int colT )
{
    int rowS, colS;
    if( p == NULL )
    {
        return false ;
    }
    rowS = p->getPosation().getRow();
    colS = p->getPosation().getCol();

    if( turn != p->getColor())
    {
        return false ;
    }
    if( rowS < 0 || rowS > 7 )
    {
        return false ;
    }
    if( colS < 0 || colS > 7 )
    {
        return false ;
    }
    if( rowT < 0 || rowT > 7 )
    {
        return false ;
    }
    if( colT < 0 || colT > 7 )
    {
        return false ;
    }
    if( p->isCaptured == true )
    {
        return false ;
    }
    if( checked == true )
    {

    }
    if( q != NULL )
    {
        if( q->getColor() == p->getColor() )
        {
            return false ;
        }
        if( q->getPieceType() == KING )
        {
            return false ;
        }
    }
    return p->canGoTo( rowT , colT , this->getState() ) ;
}
//**********************************************************************************************************************************************************
PieceColor Game::getTurn()
{
    return turn;
}
//**********************************************************************************************************************************************************
void Game::setChecked()
{
    Piece * checker = findChecker();
    checked = checker != NULL;
}
//**********************************************************************************************************************************************************
Piece * Game::findChecker()
{
    int i ;
    Piece * p ;
    Piece * king = turn == BLACK ? blackNut[KingPosition] : whiteNut[KingPosition] ;
    for( i = 0 ; i < lenghNuts ; i ++ )
    {
        p = turn == BLACK ? whiteNut[i]: blackNut[i];
        if( !p->isCaptured && p->canGoTo( king->getPosation().getRow() , king->getPosation().getCol() , this->getState() ) )
        {
            return p;
        }
    }
    return NULL;
}
//**********************************************************************************************************************************************************
bool Game::checkAndMoveNut( Piece *p , Piece *q , int rowT , int colT , bool forceRevert )
{
    BoardCellType start , target ;
    int rowS , colS;
    if( isValid( p , q , rowT , colT ) )
    {
        rowS = p->getPosation().getRow();
        colS = p->getPosation().getCol();
        start = arrayBoard[rowS][colS] ;
        target = arrayBoard[rowT][colT] ;
        arrayBoard[rowT][colT] = p->getBoardCellType() ;
        arrayBoard[rowS][colS] = NONE ;
        if( q != NULL && q->getPieceType() != KING )
        {
            q->isCaptured = true ;
        }
        p->getPosation().setRow( rowT ) ;
        p->getPosation().setCol( colT ) ;
        //agar in harekat baes kishe jadiid ya adame rafe kish ghadim mishavad bayad bargasht daade shavad
        bool oldChecked = checked;
        setChecked() ;
        if( forceRevert || checked )
        {
            arrayBoard[rowS][colS] = start ;
            arrayBoard[rowT][colT] = target ;
            if( q!= NULL )
            {
                q->isCaptured = false ;
            }
            p->getPosation().setRow( rowS ) ;
            p->getPosation().setCol( colS ) ;
            bool temp = checked;
            checked = oldChecked ;
           // msg = "your king is checked !!!" ;
            return !temp ;
        }
        promote( p );
        return true ;
    }
    return false ;
}
//**********************************************************************************************************************************************************
void Game::promote( Piece *p )
{
    if( p->getPieceType( ) == PAWN )
    {
        int lastRow = p->getColor( ) == WHITE ? 7 : 0;
        int pawnRow = p->getPosation( ).getRow( );
        if( pawnRow == lastRow )
        {
            Piece **r = p->getColor( ) == WHITE ? whiteNut : blackNut;
            for( int i = 0; i < lenghNuts; i++ )
            {
                if( r[i]->getPosation( ).isEqual( p->getPosation( ) ) && !r[i]->isCaptured )
                {
                    PieceType type = getPromotionPieceType(getTurn());
                    switch( type )
                    {
                        case QUEEN :
                            r[i] = new Queen( p->getPosation( ) , p->getColor( ) );
                            break;
                        case BISHOP:
                            r[i] = new Bishop( p->getPosation( ) , p->getColor( ) );
                            break;
                        case KNIGHT:
                            r[i] = new Knight( p->getPosation( ) , p->getColor( ) );
                            break;
                        case ROCK:
                            r[i] = new Rock( p->getPosation( ) , p->getColor( ) );
                            break;
                        /*default:
                            throw exception( "invalid promotion" );*/
                    }
                    arrayBoard[pawnRow][p->getPosation( ).getCol( )] = r[i]->getBoardCellType( );
                    break;
                }
            }
        }
    }

}
//**********************************************************************************************************************************************************
void Game::setGameFinished()
{
    int kingRow , kingCol , i , j ;
    Piece *king, *checker ;
    king = turn == BLACK ? blackNut[KingPosition] : whiteNut[KingPosition] ;
    kingRow = king->getPosation().getRow() ;
    kingCol = king->getPosation().getCol() ;
    for( i = -1 ; i < 2 ; i ++ )
    {
        for( j = -1 ; j < 2 ; j ++ )
        {
            Piece *q = findNut( kingRow + i  , kingCol + j ) ;
            if( checkAndMoveNut( king , q , kingRow + i , kingCol + j , true ) )
            {
                gameFinished = false;
                return;
            }
        }
    }
    checker = findChecker();
    if (checker != NULL)
    {
        vector<Posation> v = checker->getPathTo(kingRow, kingCol, arrayBoard);
        v.push_back(checker->getPosation());
        for(i = 0; i < v.size(); i++)
        {
            for( j = 0; j < lenghNuts; j++)
            {
                Piece * p = turn == WHITE ? whiteNut[j] : blackNut[j];
                Piece * q = checker->getPosation().isEqual(v[i]) ? checker : NULL;
                if (!p->isCaptured && j != KingPosition &&
                    checkAndMoveNut(p, q, v[i].getRow(), v[i].getCol(), true))
                {
                    gameFinished = false;
                    return;
                }
            }
        }
    }
    gameFinished = true ;
}
//**********************************************************************************************************************************************************
bool Game::isChecked()
{
    return checked ;
}
//**********************************************************************************************************************************************************
bool Game::isMate()
{
    return gameFinished && checked ;
}
//**********************************************************************************************************************************************************
bool Game::isStaleMate()
{
    return gameFinished && !checked ;
}
//**********************************************************************************************************************************************************
