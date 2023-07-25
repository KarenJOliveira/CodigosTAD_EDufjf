#include <iostream>
#include "FilaEncad.h"

using namespace std;

FilaEncad::FilaEncad()
{
    inicio = fim = NULL;
}

FilaEncad::~FilaEncad()
{
    while(inicio != NULL)
    {
        No *p = inicio;
        inicio = inicio->getProx();
        delete p;
    }
}

NoArv* FilaEncad::getInicio()
{
    if(inicio != NULL)
        return inicio->getInfo();
    cout << "ERRO: Fila vazia!" << endl;
    exit(1);
}

void FilaEncad::enfileira(NoArv* val)
{
    No *p = new No();
    p->setInfo(val);
    p->setProx(NULL);
    if(inicio == NULL)
        inicio = p;
    else
        fim->setProx(p);
    fim = p;
}

NoArv* FilaEncad::desenfileira()
{
    if(inicio == NULL)
    {
        cout << "ERRO: Fila vazia" << endl;
        exit(1);
    }
    else
    {
        No *p = inicio;
        inicio = inicio->getProx();
        if(inicio == NULL)
            fim = NULL;
        NoArv* val = p->getInfo();
        delete p;
        return val;
    }
}

bool FilaEncad::vazia()
{
    return inicio == NULL;
}
