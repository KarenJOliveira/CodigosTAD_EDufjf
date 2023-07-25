#ifndef SIMPLESENCAD_H
#define SIMPLESENCAD_H
#include "No.h"
#include <iostream>
using namespace std;

class SimplesEncad
{
    public:
        SimplesEncad();
        ~SimplesEncad();
       int get(int k);
       void set(int k, int val);
       void insereInicio(int val);
       //bool busca(int val);
       void imprime();
       //int getComprimento();
       void insereFinal(int val);
       //int contaMaiores(int val );
       //void insereOrdenado(int val);
       void insereK(int k,int val);
       void removeFinal();
       void removeK(int k);
       void removeInicio();
       //bool igual(SimplesEncad *l2);
       void imprimeElemsEmOrdem();
    private:
        No *primeiro;
};

#endif // SIMPLESENCAD_H
