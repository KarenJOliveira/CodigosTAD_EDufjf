#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

ArvBinBusca::ArvBinBusca()
{
    raiz = NULL;
}

ArvBinBusca::~ArvBinBusca()
{
    libera(raiz);
}

void ArvBinBusca::libera(NoArv *p)
{
    if(p != NULL)
    {
        libera(p->getEsq());
        libera(p->getDir());
        delete p;
    }
}

int ArvBinBusca::getRaiz()
{
    if(raiz != NULL) //ou if(!vazia())
        return raiz->getInfo();
    else
    {
        cout << "Árvora vazia!" << endl;
        exit(1);
    }
}

void ArvBinBusca::insere(int val)
{
    raiz = auxInsere(raiz, val);
}
NoArv* ArvBinBusca::auxInsere(NoArv *p, int val)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(val);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else if(val < p->getInfo())
        p->setEsq(auxInsere(p->getEsq(), val));
    else if(val > p->getInfo())
        p->setDir(auxInsere(p->getDir(), val));
    else
        cout << "Valor " << val << " ja existente na arvore" << endl;
    return p;
}

bool ArvBinBusca::vazia()
{
    return raiz == NULL;
}

bool ArvBinBusca::busca(int val)
{
    return auxBusca(raiz, val);
}

bool ArvBinBusca::auxBusca(NoArv *p, int val)
{
    if(p == NULL)
        return false;
    else if(p->getInfo() == val)
        return true;
    else if(val < p->getInfo())
        return auxBusca(p->getEsq(), val);
    else //if(val > p->getInfo())
        return auxBusca(p->getDir(), val);
}

bool ArvBinBusca::buscaIt(int val)
{
    NoArv *p = raiz;
    while(p != NULL)
    {
        if(p->getInfo() == val)
            return true;
        else if(val < p->getInfo())
            p = p->getEsq();
        else //if(val > p->getInfo())
            p = p->getDir();
    }
    return false;
}

void ArvBinBusca::imprime()
{
    cout << "Arvore: ";
    auxImprime(raiz);
    cout << endl;
}

void ArvBinBusca::auxImprime(NoArv *p)
{
    if(p != NULL)
    {
        cout << p->getInfo() << " ";
        auxImprime(p->getEsq());
        auxImprime(p->getDir());
    }
}

int ArvBinBusca::menor()
{
    if(raiz == NULL)
    {
        cout << "Arvore vazia" << endl;
        exit(1);
    }
    return auxMenor(raiz);
}
int ArvBinBusca::auxMenor(NoArv *p)
{
    if(p->getEsq() == NULL)
        return p->getInfo();
    return auxMenor(p->getEsq());
}

int ArvBinBusca::menorIt()
{
    if(raiz == NULL)
    {
        cout << "Arvore vazia" << endl;
        exit(1);
    }
    NoArv *p = raiz;
    while(p->getEsq() != NULL)
        p = p->getEsq();
    return p->getInfo();
}

void ArvBinBusca::removeMin()
{
    if(raiz == NULL)
        cout << "Arvore vazia" << endl;
    else
        raiz = setEsq(auxRemoveMin(raiz));
}

NoArv* ArvBinBusca::auxRemoveMin(NoArv *p)
{
    if(p->getEsq() == NULL)
    {
        NoArv *r = p->getDir();
        delete p;
        return r;
    }
    p->setEsq(auxRemoveMin(p->getEsq()));
    return p;
}

void ArvBinBusca::removeMinIt()
{
    if(raiz == NULL)
        cout << "Arvore vazia" << endl;
    else
    {
        NoArv *pai = NULL;
        NoArv *p = raiz;
        while(p->getEsq() != NULL)
        {
            pai = p;
            p = p->getEsq();
        }
        NoArv *r = p->getDir();
        delete p;
        if(pai == NULL)
            raiz = r;
        else
            pai->setEsq(r);
    }
}

void ArvBinBusca::remove(int val)
{
    raiz = auxRemove(raiz, val);
}

NoArv* ArvBinBusca::auxRemove(NoArv *p, int val)
{
    if(p == NULL)
    {
        cout << "Valor " << val << " nao existe na arvore." << endl;
        return NULL;
    }
    else if(val < p->getInfo())
        p->setEsq(auxRemove(p->getEsq(), val));
    else if(val > p->getInfo())
        p->setDir(auxRemove(p->getDir(), val));
    else //p->getInfo == val
    {
        if(p->getEsq() == NULL && p->getDir() == NULL)
        {
            delete p;
            return NULL;
        }
        else if(p->getEsq() != NULL && p->getDir() == NULL)
        {
            NoArv *aux = p->getEsq();
            delete p;
            return aux;
        }
        else if(p->getEsq() == NULL && p->getDir() != NULL)
        {
            NoArv *aux = p->getDir();
            delete p;
            return aux;
        }
        else
        {
            NoArv *aux = p->getDir();
            while(aux->getEsq() != NULL)
                aux = aux->getEsq();
            p->setInfo(aux->getInfo());
            aux->setInfo(val);
            p->setDir(auxRemove(p->getDir(), val));
        }
    }
    return p;
}
