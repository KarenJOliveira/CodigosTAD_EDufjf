#include <iostream>
#include "No.h"
#include "SimplesEncad.h"
using namespace std;

int main()
{
    SimplesEncad l;
    l.insereInicio(3);
    l.insereFinal(2);
    l.insereFinal(5);
    l.insereFinal(7);
    l.insereFinal(9);
    l.imprime();

    l.imprimeElemsEmOrdem();
    /*
    cout << "Quantidade de elementos da lista: " << l.getComprimento() << endl;
    cout << "Procura valor 2: " << l.busca(2) << endl;
    cout << "Procura valor 5: " << l.busca(5) << endl;
    cout << "Quantidade maior que 1: " << l.contaMaiores(1) << endl;
    cout << "Quantidade maior que 3: " << l.contaMaiores(3) << endl;
    //l.insereK(2,10);
    //l.insereK(4,0);

    cout << "Quantidade de elementos da lista: " << l.getComprimento() << endl;

    SimplesEncad l2;

    l2.imprime();
    l.igual(&l2);
    */

    return 0;
}
