#include "NoDuplo.h"
#include "ListaCirc.h"
#include <iostream>

using namespace std;

int main()
{
    ListaCirc l;
    l.insereFinal(5);
    l.insereFinal(3);
    l.insereFinal(8);
    l.insereFinal(2);
    l.insereFinal(11);
    l.insereFinal(1);
    l.insereFinal(4);
    l.imprime();

    //l.insereNoAntes(??,7);
    l.imprime();
    return 0;
}
