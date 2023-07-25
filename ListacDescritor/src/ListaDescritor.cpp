#include <iostream>
#include "No.h"
#include "ListaDescritor.h"
using namespace std;

ListaDescritor::ListaDescritor()
{
    n = 0;
    primeiro = NULL;
    ultimo = NULL;
}

ListaDescritor::~ListaDescritor()
{
    No *p = primeiro;
    while(p!=NULL){
      p = p->getProx();
      delete p;
    }
}

int ListaDescritor::get(int k)
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
void ListaDescritor::set(int k, int val)
{
    if(k < 0 || k >= n)
        cout << "ERRO: posicao invalida" << endl;
    int cont = 0;
    No *atual = primeiro;
    No *anterior = NULL;
    while(cont < k){
        anterior = atual;
        atual = atual->getProx();
        cont++;
    }
    No *p = new No();
    p->setInfo(val); // nao teria que apontar o elemento anterior e o posterior?
    p->setProx(atual);
    if(anterior != NULL)
        anterior->setProx(p);
    else{
        primeiro = p;
    }
}
int ListaDescritor::tamanho()
{
    return n;
}
void ListaDescritor::insereInicio(int val)
{
    No *p = new No();

    p->setInfo(val);
    p->setProx(primeiro);

    primeiro = p;
    if(primeiro == NULL)
        ultimo = p;
    n++;
}


void ListaDescritor::imprime(){
    No *p = primeiro;
    cout << "Lista: ";
    while(p != NULL)
    {
        cout << p->getInfo() << " ";
        p = p->getProx();
    }
    cout << endl;
}


void ListaDescritor::insereFinal(int val)
{
    No *p = new No();
    p->setInfo(val);
    p->setProx(NULL);
    if(primeiro == NULL)
        primeiro = p;
    else
        ultimo->setProx(p);
    ultimo = p;
    n++;
}

bool ListaDescritor::busca(int val)
{
    for(No *p=primeiro;p!=NULL;p=p->getProx()){
        if(p->getInfo() == val){
            return true;
        }
    }
    return false;
}

void ListaDescritor::insereK(int k,int val)
{
    if(k < 0 || k>=n){
        cout << "ERRO: Posicao invalida" << endl;
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
    n++;
   }
}

void ListaDescritor::removeK(int k)
{
    if(k < 0 || k>=n){
        cout << "Erro" << endl;
    }
    else{
    No *atual = primeiro;
    No *ant = NULL;
    int pos = 0;
    while(pos<k){
        ant = atual;
        atual = atual->getProx();
        pos++;
    }

    if(ant != NULL){
        ant->setProx(atual->getProx());
        if(atual==ultimo)
            ultimo = ant;
    }
    else{
        primeiro = primeiro->getProx();
        if(primeiro == NULL)
            ultimo = NULL;
    }
    n--;
    delete atual;
   }

}

void ListaDescritor::removeFinal()
{
    if(primeiro == NULL)
        cout << "Erro" << endl;
    else{
        if(primeiro == ultimo){
            delete primeiro;
            primeiro = ultimo = NULL;
            n--;
        }else{
        No *penultimo = primeiro;
        while(penultimo->getProx() != ultimo){
            penultimo = penultimo->getProx();
        }
        No *p = ultimo;
        penultimo->setProx(NULL);
        ultimo = penultimo;
        n--;
        delete p;
        }
    }

}

void ListaDescritor::removeInicio()
{
    if(primeiro == NULL){
        cout << "ERRO: lista vazia" << endl;
    }
    else{
        No *p = primeiro;
        primeiro = primeiro->getProx();
        if(primeiro == NULL)
            ultimo = NULL;
        n--;
        delete p;
    }
}

int* ListaDescritor::menorProximo()
{
    if(primeiro != NULL){
        No *atual = primeiro->getProx();
        No *ant = primeiro;
        int *vet = new int[n];
        vet[0]=0;
        int pos = 1;
        while(pos < n){
            if(ant->getInfo() < atual->getInfo()){
                vet[pos] = 1;
            }
            else{
                vet[pos] = 0;
            }
            cout << vet[pos] << " ";
            pos++;
            ant = atual;
            atual = atual->getProx();
        }
        vet[n-1] = 1;
        return vet;
    }
    return NULL;
}
bool ListaDescritor::inserePosicaoVal(int k,int val)
{
    if(k>=0 && k<n){
       No *atual = primeiro;
       No *ant = NULL;
       int pos = 0;
       int pos2;
       while(pos < k){
            ant = atual;
            atual = atual->getProx();
            pos++;
       }
       pos2 = atual->getInfo();
       if(pos2 < n){
            while(pos < pos2){
                ant = atual;
                atual = atual->getProx();
                pos++;
            }
            No *no = new No();
            no->setInfo(val);
            no->setProx(atual);
            ant->setProx(no);
            n++;
            return true;
       }else{
           cout << "ERRO: Posicao invalida" << endl;
           return false;
       }
    }else{
        cout << "ERRO: Posicao invalida" << endl;
    }
}
