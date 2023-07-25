#include <iostream>
#include "PilhaCont.h"

using namespace std;

int main()
{
    PilhaCont p(10);
    p.empilha(1);
    p.imprime();
    p.empilha(2);
    p.imprime();
    p.empilha(3);
    p.imprime();
    p.empilha(4);
    p.imprime();
    PilhaCont p2(10);
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
    return 0;
}
