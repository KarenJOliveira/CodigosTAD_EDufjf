#include <iostream>
#include "PilhaEncad.h"
#include "FilaEncad.h"

using namespace std;

void inverteFila(FilaEncad *f)
{
    PilhaEncad p;
    while(!f->vazia())
        p.empilha(f->desenfileira());
    while(!p.vazia())
        f->enfileira(p.desempilha());
}

int main()
{
    FilaEncad f;
    f.enfileira(1);
    f.enfileira(2);
    f.enfileira(3);
    f.enfileira(4);
    f.enfileira(5);
    f.imprime();
    inverteFila(&f);
    f.imprime();
    return 0;
}
