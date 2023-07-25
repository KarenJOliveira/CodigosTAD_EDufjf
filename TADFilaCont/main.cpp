#include <iostream>
#include "FilaCont.h"

using namespace std;

int main()
{
    FilaCont f(10);
    f.enfileira(1);
    f.imprime();
    f.enfileira(2);
    f.imprime();
    f.enfileira(3);
    f.imprime();
    f.enfileira(4);
    f.imprime();
    f.enfileira(5);
    f.imprime();
    f.desenfileira();
    f.imprime();
    f.desenfileira();
    f.imprime();
    f.desenfileira();
    f.imprime();
    f.desenfileira();
    f.imprime();
    f.desenfileira();
    f.imprime();
    ///
    f.enfileira(1);
    f.imprime();
    f.enfileira(2);
    f.imprime();
    f.enfileira(3);
    f.imprime();
    f.enfileira(4);
    f.imprime();
    f.enfileira(5);
    f.imprime();
    f.desenfileira();
    f.imprime();
    f.desenfileira();
    f.imprime();
    f.desenfileira();
    f.imprime();
    f.desenfileira();
    f.imprime();
    f.desenfileira();
    f.imprime();
    ///
    f.enfileira(1);
    f.imprime();

    return 0;
}
