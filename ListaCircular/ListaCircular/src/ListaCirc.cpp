#include "NoDuplo.h"
#include "ListaCirc.h"
#include <iostream>

using namespace std;

ListaCirc::ListaCirc()
{
    n=0;
    primeiro = NULL;
    ultimo = NULL;
}

ListaCirc::~ListaCirc()
{
    NoDuplo *p = primeiro;
    while(p!=ultimo){
        p = p->getProx();
        delete p;
    }
}

void ListaCirc::insereInicio(int val)
{
    NoDuplo *p = new NoDuplo();
    p->setInfo(val);
    if(n == 0) {
        p->setProx(p);
        p->setAnt(p);
        ultimo = p;
    }
    else
    {
        p->setProx(primeiro);
        p->setAnt(ultimo);
        primeiro->setAnt(p);
        ultimo->setProx(p);
    }
    primeiro = p;
    n = n + 1;
}
void ListaCirc::imprime(){
    NoDuplo *p = primeiro;
    cout << "Lista: ";
    int pos = 0;
    while(pos<n)
    {
        cout << p->getInfo() << " ";
        p = p->getProx();
        pos++;
    }
    cout << endl;
}

void ListaCirc::removeInicio()
{
    if(primeiro == NULL){
        cout << "ERRO: lista vazia" << endl;
    }else{
        NoDuplo *p = primeiro;
        primeiro = primeiro->getProx();
        primeiro->setAnt(ultimo);
        if(primeiro == NULL)
        {
            ultimo = NULL;
        }
        delete p;
        n--;
    }
}
void ListaCirc::insereFinal(int val )
{
    if(primeiro == NULL){
        insereInicio(val);
    }else{
        NoDuplo *p = new NoDuplo();
        p->setInfo(val);
        p->setProx(primeiro);
        p->setAnt(ultimo);
        if(ultimo == NULL) //if(primeiro == NULL)
            primeiro = p;
        else
            ultimo->setProx(p);

        ultimo = p;
        n++;
    }
}

void ListaCirc::removeFinal()
{
    if(ultimo == NULL){
        cout << "ERRO: lista vazia" << endl;
    }else{
        NoDuplo *p = ultimo;
        ultimo = ultimo->getAnt();
        if(ultimo==NULL)
            primeiro = NULL;
        else
            ultimo->setProx(primeiro);
        delete p;
        n--;
    }
}

NoDuplo* ListaCirc::insereNoAntes(NoDuplo *p, int val){

    NoDuplo *novo = new NoDuplo();
    NoDuplo *n = primeiro;
    while(n!=ultimo){
        if(n->getProx() == p){
            break;
        }
        n = n->getProx();
    }
    if(p == primeiro){
        insereInicio(val);
    }else{
        novo->setInfo(val);
        novo->setAnt(n);
        novo->setProx(n->getProx());
    }
    return novo;
}
