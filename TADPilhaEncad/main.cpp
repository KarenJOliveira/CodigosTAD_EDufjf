#include <iostream>
#include "PilhaEncad.h"

using namespace std;

void concatena(PilhaEncad *p1, PilhaEncad *p2)
{
    PilhaEncad aux;
    while(!p2->vazia())
        aux.empilha(p2->desempilha());
    while(!aux.vazia())
        p1->empilha(aux.desempilha());
}

bool palindromo(PilhaEncad *p)
{
    PilhaEncad p1, p2, p3;
    while(!p->vazia())
    {
        int aux = p->getTopo();
        p1.empilha(aux);
        p2.empilha(aux);
        p->desempilha();
    }
    while(!p2.vazia())
    {
        int aux = p2.getTopo();
        p->empilha(aux);
        p3.empilha(aux);
        p2.desempilha();
    }
    while(!p1.vazia())
        if(p1.desempilha() != p3.desempilha())
            return false;
    return true;
}

int main()
{
    /*
    PilhaEncad p;
    p.empilha(1);
    p.imprime();
    p.empilha(2);
    p.imprime();
    p.empilha(3);
    p.imprime();
    p.empilha(4);
    p.imprime();
    PilhaEncad p2;
    while(!p.vazia())
    {
        if(p.getTopo() != 2)
            p2.empilha(p.desempilha());
        else
        {
            p.desempilha();
            break;
        }
    }
    while(!p2.vazia())
        p.empilha(p2.desempilha());
    p.imprime();
    */
    ///
    /*
    PilhaEncad p3, p4;
    p3.empilha(1);
    p3.empilha(2);
    p3.empilha(3);
    p3.imprime();
    p4.empilha(7);
    p4.empilha(8);
    p4.empilha(9);
    p4.imprime();
    concatena(&p3, &p4);
    p3.imprime();
    p4.imprime();
    */
    ///
    PilhaEncad p;
    p.empilha(1);
    p.empilha(2);
    p.empilha(3);
    p.empilha(2);
    p.empilha(1);
    p.imprime();
    cout << palindromo(&p);
    return 0;
}
