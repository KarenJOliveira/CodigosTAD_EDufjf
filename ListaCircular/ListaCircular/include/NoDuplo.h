#ifndef NODUPLO_H
#define NODUPLO_H
#include <iostream>

using namespace std;

class NoDuplo
{
public :
    NoDuplo () ;
    ~ NoDuplo () ;
    void setAnt ( NoDuplo * p) ;
    void setProx ( NoDuplo * p) ;
    void setInfo (int val);
    NoDuplo * getAnt();
    NoDuplo * getProx();
    int getInfo();
private :
    int info ; // informacao
    NoDuplo * ant ; // ponteiro para anterior
    NoDuplo * prox ; // ponteiro para proximo
};

#endif // NODUPLO_H
