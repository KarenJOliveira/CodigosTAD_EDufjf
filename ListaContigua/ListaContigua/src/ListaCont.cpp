#include "ListaCont.h"
#include <iostream>

using namespace std;

ListaCont::ListaCont(int tam){
    max = tam;
    n = 0;
    vet = new int[max];
}

ListaCont::~ListaCont(){
    delete [] vet;
}

int ListaCont::get(int k){
    if(k >= 0 && k < n){
        return vet[k];
    }
    cout << "Erro: indice invalido" << endl;
    exit(1);
}

void ListaCont::set(int k, int val){
    if(k >= 0 && k < n){
        vet[k] = val;
    }
    cout << "Erro: indice invalido" << endl;
}

void ListaCont::insereFinal(int val){
    if(n < max){
        vet[n++] = val;
    }
    else{
        cout << "Erro: vetor cheio" << endl;
        cout << "Aumentando a capacidade do vetor..." << endl;
        aumentaCapacidade();
        vet[n++] = val;
    }
}

void ListaCont::removeFinal(){
    if(n > 0){
        n--;
    }
    else{
        cout << "Erro: vetor vazio" << endl;
    }
}

void ListaCont::insereK(int k,int val){
    if(k >= 0 && k < n){
        if(n < max){
            for(int i = n; i > k; i--){
                vet[i] = vet[i-1];
            }
            vet[k] = val;
            n++;
        }
        else{
            cout << "Erro: vetor cheio" << endl;
            cout << "Aumentando a capacidade do vetor..." << endl;
            aumentaCapacidade();
            vet[n++] = val;
        }
    }
    else{
        cout << "Erro: indice invalido" << endl;
    }
}

void ListaCont::aumentaCapacidade(){
    max *= 2;
    int *temp = new int[max];
    for(int i = 0; i < n; i++){
        temp[i] = vet[i];
    }
    delete [] vet;
    vet = temp;
}

void ListaCont::removeK(int k){
    if(k >= 0 && k < n){
        for(int i = k; i < n-1; i++){
            vet[i] = vet[i+1];
        }
        n--;
    }
    else{
        cout << "Erro: indice invalido" << endl;
    }
}
void ListaCont::removeInicio(){
    if(n > 0){
        for(int i = 0; i < n-1; i++){
            vet[i] = vet[i+1];
        }
        n--;
    }
    else{
        cout << "Erro: vetor vazio" << endl;
    }
}

void ListaCont::insereInicio(int val){

    if(n<max){
        for(int i = n; i > 0; i--){
            vet[i] = vet[i-1];
        }
        vet[0] = val;
        n++;
    }
    else{
        cout << "Erro: vetor cheio" << endl;
        cout << "Aumentando a capacidade do vetor..." << endl;
        aumentaCapacidade();
        vet[0] = val;
        n++;
        //vet[n++] = val;
    }
}
void ListaCont::imprime(){
    cout << "Lista: ";
    for(int i = 0; i < n; i++){
        cout << vet[i] << " ";
    }
    cout << endl;
}

ListaCont* ListaCont::copiar(int valor)
{
    ListaCont *lista = new ListaCont(max);
    int i;
    for(i=0;i<n;i++){
        if(get(i) == valor)
            break;
    }
    if(i!=n){
        int k=0;
        while(k < n-i){
            lista->insereFinal(get(i+k));
            k++;
        }
        n -= lista->n;
        return lista;
    }
}
void ListaCont::inserirVet(int tam, int v[])
{
    max += tam;
    int *temp = new int[max];
    for(int i=0;i<tam;i++)
        temp[i] = v[i];
    for(int i=0;i<n;i++){
        temp[tam] = vet[i];
        tam++;
    }
    n = tam;
    delete [] vet;
    vet = temp;
}

void ListaCont::intercala(ListaCont *la,ListaCont *lb)
{
    int tamA = la->n;
    int tamB = lb->n;
    if(tamA + tamB > max){
        max = tamA+tamB;
        int *temp = new int[max];
        delete [] vet;
        vet = temp;
    }
    int menor = tamA;
    if(tamB < tamA)
        menor = tamB;
    int cont = 0;
    while(cont < menor){
        insereFinal(la->vet[i]);
        insereFinal(lb->vet[i]);
        cont++;
    }
    if(tamA < tamB){
        for(int i=tamA;i<tamB;i++)
            insereFinal(lb->vet[i]);
    }else{
        for(int i=tamB;i<tamA;i++)
            insereFinal(la->vet[i]);
    }
    la->n = lb->n = 0;
}


/*
ListaCont* ListaCont::pares(){
    ListaCont *pares = new ListaCont(max);
    for(int i = 0; i < n; i++){
        if(vet[i] % 2 == 0){
            pares->insereFinal(vet[i]);
        }
    }
    return pares;
}
int ListaCont::busca(int val){
    for(int i = 0; i < n; i++){
        if(vet[i] == val){
            return i;
        }
    }
    return -1;
}

ListaCont* ListaCont::concatena(ListaCont *l2){
    ListaCont *nova = new ListaCont(max + l2->max);
    //int j = 0;
    for(int i = 0; i < n; i++){
        nova->insereFinal(vet[i]); //nova->vet[j++] = vet[i];
    }
    for(int i = 0; i < l2->n; i++){
        nova->insereFinal(l2->vet[i]); //nova->vet[j++] = l2->vet[i];
    }

    nova->n = n + l2->n;
    n=0;
    l2->n=0;
    return nova;
}

void ListaCont::removeVal(int val){
    for(int i = 0; i < n; i++){
        if(get(i) == val){
            removeK(i);
            break;
        }
    }
}

void ListaCont::removeOcorencias(int val){
    for(int i=0; i<n; i++){
        if(get(i) == val){
            removeK(i);
        }
    }
}
*/
