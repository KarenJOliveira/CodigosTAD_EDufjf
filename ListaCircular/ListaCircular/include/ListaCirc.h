#ifndef LISTACIRC_H
#define LISTACIRC_H
#include "NoDuplo.h"
#include <iostream>

using namespace std;

class ListaCirc
{
    public:
        ListaCirc();
        virtual ~ListaCirc();
        void insereInicio (int val) ;
        void removeInicio () ;
        void insereFinal (int val) ;
        void removeFinal();
        void imprime();
        NoDuplo* insereNoAntes(NoDuplo *p, int val);

    private :
        int n ;
        NoDuplo *primeiro ;
        NoDuplo *ultimo ;

};

#endif // LISTACIRC_H
