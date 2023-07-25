#include <iostream>
#include "PilhaEncad.h"

using namespace std;

PilhaEncad::PilhaEncad()
{
    topo = NULL;
}

PilhaEncad::~PilhaEncad()
{
    while(topo != NULL)
    {
        No *p = topo;
        topo = topo->getProx();
        delete p;
    }
}

int PilhaEncad::getTopo()
{
    if(topo != NULL)
        return topo->getInfo();
    cout << "ERRO: Pilha vazia" << endl;
    exit(1);
}

void PilhaEncad::empilha(int val)
{
    No *p = new No();
    p->setInfo(val);
    p->setProx(topo);
    topo = p;
}

int PilhaEncad::desempilha()
{
    if(topo == NULL)
        cout << "ERRO: Pilha vazia" << endl;
    else
    {
        No *p = topo;
        topo = topo->getProx();
        int val = p->getInfo();
        delete p;
        return val;
    }
}

bool PilhaEncad::vazia()
{
    return topo == NULL;
}

void PilhaEncad::imprime()
{
    cout << "Pilha: ";
    for(No *p = topo; p != NULL; p = p->getProx())
        cout << p->getInfo() << " ";
    cout << endl;
}

