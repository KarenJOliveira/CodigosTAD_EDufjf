#include <iostream>
#include "ListaCont.h"
using namespace std;

int main()
{

    ListaCont l(10);
    l.insereFinal(9);
    l.insereFinal(3);
    l.insereFinal(6);
    l.insereFinal(5);
    l.insereFinal(9);
    l.insereFinal(11);
    l.imprime();

    int vet[3] = {-5,6,7};
    l.inserirVet(3,vet);
    //ListaCont *l2 = l.copiar(5);
    l.imprime();
    //l2->imprime();

    return 0;
}
