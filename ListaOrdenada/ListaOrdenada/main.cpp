#include <iostream>
#include "ListaContOrd.h"

using namespace std;

int main()
{
    ListaContOrd l(10);
    l.insere(5);
    l.imprime();
    l.insere(3);
    l.imprime();
    l.insere(1);
    l.imprime();
    l.insere(12);
    l.imprime();
    l.insere(14);
    l.imprime();
    l.insere(41);
    l.imprime();
    l.insere(-1);
    l.imprime();
    return 0;
}
