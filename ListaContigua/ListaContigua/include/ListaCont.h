#ifndef LISTACONT_H
#define LISTACONT_H
#include <iostream>

using namespace std;

class ListaCont
{
    public:
       ListaCont(int tam);
       ~ListaCont();
       int get(int k);
       void set(int k, int val);
       void insereInicio(int val);
       void removeInicio();
       void insereFinal(int val);
       void removeFinal();
       void insereK(int k, int val);
       void removeK(int k);
       void aumentaCapacidade();
       void imprime();
       //ListaCont* pares();
       //int busca(int val);
       //ListaCont* concatena(ListaCont *l2);
       //void removeVal(int val);
       //void removeOcorencias(int val);
       ListaCont* copiar(int valor);
       void inserirVet(int tam, int v[]);
       void intercala(ListaCont *la,ListaCont *lb);

    private:
      int n; //quantidade de nós da lista
      int max; //capacidade máxima de elementos
      int *vet; //vetor que armazena os elementos da lista
};

#endif // LISTACONT_H
