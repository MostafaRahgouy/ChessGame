#ifndef POSATION_H
#define POSATION_H
#include <iostream>
#include <string>
using namespace std ;
//**********************************************************************************************************************************************************
class Posation
{
    public:
        Posation( int , int );
        virtual ~Posation();
        int getRow() ;
        int getCol() ;
        bool isEqual( Posation& ) ;
        bool isEqual( int , int ) ;
        void setRow( int ) ;
        void setCol( int ) ;
    protected:
    private:
        int row ;
        int col ;
};
//**********************************************************************************************************************************************************
#endif // POSATION_H
