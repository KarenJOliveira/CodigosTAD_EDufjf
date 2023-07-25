#include "SimplesEncad.h"
#include "No.h"
#include <iostream>
using namespace std;
SimplesEncad::SimplesEncad()
{
    primeiro = NULL;
}

SimplesEncad::~SimplesEncad()
{
    No *p = primeiro;
    while(p!=NULL){
        No *t = p->getProx();
        delete p;

        p = t;
    }
}

int SimplesEncad::get(int k)
{
    if(k < 0)
        cout << "Erro" << endl;
    int cont = 0;
    No *p = primeiro;
    while(p!=NULL){
        if(cont==k)
            break;
        p = p->getProx();
        cont++;
    }
    if(p == NULL){
        cout << "Erro" << endl;
        exit(1);
    }
    else
        return p->getInfo();
}
void SimplesEncad::set(int k, int val)
{
    if(k < 0)
        cout << "Erro" << endl;
    int cont = 0;
    No *p = primeiro;
    while(p!=NULL){
        if(cont==k)
            break;
        p = p->getProx();
        cont++;
    }
    if(p == NULL){
        cout << "Erro" << endl;
        exit(1);
    }
    else
        p->setInfo(val);
}

void SimplesEncad::insereInicio(int val)
{
    No *p = new No();

    p->setInfo(val);
    p->setProx(primeiro);

    primeiro = p;
}
/*
bool SimplesEncad::busca(int val)
{
    No *p = primeiro;
    while(p != NULL){
        if(p->getInfo() == val){
            return true;
        }
        p = p->getProx();
    }
    return false;
}
*/
void SimplesEncad::imprime(){
    No *p = primeiro;
    cout << "Lista: ";
    while(p != NULL)
    {
        cout << p->getInfo() << " ";
        p = p->getProx();
    }
    cout << endl;
}
/*
int SimplesEncad::getComprimento()
{
    No *p = primeiro;
    int tam=0;
    while(p != NULL){
        tam++;
        p  = p->getProx();
    }
    return tam;
}
*/
void SimplesEncad::insereFinal(int val)
{
    if(primeiro == NULL)
        insereInicio(val);
    else{
        No *p = new No();
        p->setInfo(val);
        p->setProx(NULL);
        No *ultimo = primeiro;
        while(ultimo->getProx() != NULL){
            ultimo = ultimo->getProx();
        }
        ultimo->setProx(p);
    }
}
/*
int SimplesEncad::contaMaiores(int val)
{
    No *p;
    int nos = 0;
    for(p=primeiro;p!=NULL;p = p->getProx()){
        if(p->getInfo() > val){
            nos++;
        }
    }
    return nos;
}

void SimplesEncad::insereOrdenado(int val)
{
    No *p = primeiro;
    No *t = new No();
    No *aux;
    t->setInfo(val);
    if(p == NULL){
        p = t;
        p->setProx(NULL);
        primeiro = p;
    }else{
        while(p->getInfo() < val){
        aux = p;
        p = p->getProx();
        if(p == NULL)
            break;
      }
      aux->setProx(t);
      t->setProx(p);
    }
}
*/
void SimplesEncad::insereK(int k,int val)
{
    if(k < 0){
        cout << "Erro" << endl;
    }else{
    No *atual = primeiro;
    No *ant = NULL;
    int pos = 0;
    while(pos < k){
        ant = atual;
        atual = atual->getProx();
        pos++;
    }
    No *p = new No();
    p->setInfo(val);
    p->setProx(atual);
    if(ant != NULL){
        ant->setProx(p);
    }else{
        primeiro = p;
    }
  }
}

void SimplesEncad::removeFinal()
{
    if(primeiro == NULL){
        cout << "ERRO: Lista vazia" << endl;
    }
    else{
        No *penultimo = NULL;
        No *ultimo = primeiro;
        while(ultimo->getProx() != NULL){
            penultimo = ultimo;
            ultimo = ultimo->getProx();
        }
        delete ultimo;
        penultimo->setProx(NULL);
    }
}
void SimplesEncad::removeK(int k)
{
    if(k < 0){
        cout << "Erro: posicao invalida" << endl;
    }
    else{
    No *atual = primeiro;
    No *ant = NULL;
    int pos = 0;
    while(atual!=NULL){
        if(pos == k){
            break;
        }
        ant = atual;
        atual = atual->getProx();
        pos++;
    }
    if(atual == NULL){
        cout << "Erro: posicao invalida" << endl;
    }else{
        if(ant != NULL)
            ant->setProx(atual->getProx());
        else
            primeiro = primeiro->getProx();
        delete atual;
    }
   }
}
void SimplesEncad::removeInicio()
{
    if(primeiro == NULL){
        cout << "Erro: lista vazia" << endl;
    }
    else{
        No *p = primeiro;
        primeiro = primeiro->getProx();
        delete p;
    }
}
/*
bool SimplesEncad::igual(SimplesEncad *l2)
{
    No *p = primeiro;
    No*p2 = l2->primeiro;
    if(p == NULL || p2 == NULL){
        cout << "Lista vazia" << endl;
        exit(1);
    }
    if(getComprimento() != l2->getComprimento()){
        cout << "Listas nao possuem o mesmo tamanho" << endl;
        exit(1);
    }
    while(p!=NULL || p2!=NULL){
        if(p->getInfo() == p2->getInfo()){
            p = p->getProx();
            p2 = p2->getProx();
        }else{
            cout << "Nao sao iguais" << endl;
            return false;
        }
    }
    cout << "As listas sao iguais " << endl;
    return true;
}
*/
void SimplesEncad::imprimeElemsEmOrdem()
{
    No *atual = primeiro;
    No *ant = NULL;
    No *prox = atual->getProx();
    while(atual!= NULL){
        if(ant == NULL){
            if(prox->getProx()!=NULL && atual->getInfo() <= prox->getInfo()){
               cout << atual->getInfo() << " ";
            }

        }else if(prox == NULL){
            if(ant->getInfo() <= atual->getInfo()){
                cout << atual->getInfo() << " ";
            }

        }else{
            if(ant->getInfo() <= atual->getInfo() && atual->getInfo() <= prox->getInfo()){
                cout << atual->getInfo() << " ";
            }

        }
        ant = atual;
        atual = prox;
        if(prox != NULL){
            prox = prox->getProx();
        }
    }
    cout << endl;
}


