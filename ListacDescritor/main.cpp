#include <iostream>
#include "No.h"
#include "ListaDescritor.h"
using namespace std;

int main()
{
    ListaDescritor lista;
    lista.insereFinal(3);
    lista.insereFinal(2);
    lista.insereFinal(5);
    lista.insereFinal(7);
    lista.insereFinal(9);
    lista.insereFinal(2);
    lista.insereFinal(4);
    lista.insereFinal(8);
    lista.imprime();
    //lista.inserePosicaoVal(3,0);
    //lista.imprime();
    //lista.inserePosicaoVal(10,6);
    //lista.imprime();
    //lista.inserePosicaoVal(4,11);
    //lista.imprime();

    int *vet= lista.menorProximo();
    //cout << lista.tamanho() << endl;
    //lista.set(2,23);
    lista.imprime();
    //cout << lista.get(2) << endl;
    return 0;
}
