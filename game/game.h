#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include "Piece.h"
using namespace std ;
const int lenghBoard = 8 ;
const int lenghNuts = 16 ;
//**********************************************************************************************************************************************************
class Game
{
    public:
        Game( PieceType( *getPromotionPieceType )( PieceColor turn ) );
        virtual ~Game();
        Game();
        BoardCellType** getState();
        void init() ;
        bool makeMove( string , string & ) ;
        PieceColor getTurn() ;
        bool isChecked() ;
        bool isMate() ;
        bool isStaleMate() ;
    protected:
    private:
        const int KingPosition = 4;
        BoardCellType **arrayBoard ;
        Piece **blackNut;
        Piece **whiteNut;
        Piece *targetPosation ;
        Piece *findNut( int , int ) ;
        bool checkAndMoveNut( Piece * , Piece *  , int , int , bool ) ;
        bool isValid( Piece * , Piece * , int , int ) ;
        PieceColor turn ;
        bool checked = false ;
        bool gameFinished = false ;
        void setGameFinished() ;
        void setChecked() ;
        Piece * findChecker() ;
        PieceType( *getPromotionPieceType )( PieceColor turn );
        void promote( Piece *p );

};
//**********************************************************************************************************************************************************
#endif // GAME_H
