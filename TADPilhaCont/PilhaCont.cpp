#include <iostream>
#include "PilhaCont.h"

using namespace std;

PilhaCont::PilhaCont(int tam)
{
    topo = -1;
    max = tam;
    vet = new int[max];
}

PilhaCont::~PilhaCont()
{
    delete [] vet;
}

int PilhaCont::getTopo()
{
    if(topo >= 0)
        return vet[topo];
    cout << "ERRO GETTOPO: Pilha vazia!" << endl;
    exit(1);
}

void PilhaCont::empilha(int val)
{
    if(topo < max-1)
        vet[++topo] = val;
    else
        cout << "ERRO INSERE: Vetor cheio!" << endl;
}

int PilhaCont::desempilha()
{
    if(topo >= 0)
    {
        topo--;
        return vet[topo+1];
    }
    else
        cout << "ERRO REMOVE: Pilha vazia!" << endl;
}

bool PilhaCont::vazia()
{
    return topo == -1;
}

void PilhaCont::imprime()
{
    cout << "Pilha: ";
    for(int i = topo; i >= 0; i--)
        cout << vet[i] << " ";
    cout << endl;
}
