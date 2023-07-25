#include <iostream>
#include "ListaContOrd.h"

using namespace std;

ListaContOrd::ListaContOrd(int tam)
{
    max = tam;
    n = 0;
    vet = new int[max];
}

ListaContOrd::~ListaContOrd()
{
    delete [] vet;
}

int ListaContOrd::get(int k)
{
    if(k>=0 && k<n){
        return vet[k];
    }else{
        cout << "Indice invalido" << endl;
        exit(1);
    }
}

void ListaContOrd::imprime()
{
    cout << "Lista: ";
    for(int i=0;i<n;i++){
        cout << get(i) << " ";
    }
    cout << endl;
}

void ListaContOrd::insere(int val)
{
    if(n<max){
        int k;
        for(k=0;k<n;k++){
            if(vet[k]>val){
                break;
            }
        }
        for(int i=n;i>k;i--){
            vet[i] = vet[i-1];
        }
        vet[k] = val;
        n++;
    }else{
        cout << "Vetor cheio!" << endl;

    }
}

void ListaContOrd::remove(int val)
{
    if(n>0){
        n--;
    }else{
        cout << "Vetor vazio!" << endl;
    }
}
