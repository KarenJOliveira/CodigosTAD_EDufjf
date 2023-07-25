#ifndef LISTACONTORD_H
#define LISTACONTORD_H
#include <iostream>

using namespace std;

class ListaContOrd
{
    public:
        ListaContOrd(int tam);
        ~ListaContOrd();
        int get(int k);
        void insere(int val);
        void remove(int val);
        void imprime();
        bool busca(int val);

    private:
        int max;
        int n;
        int *vet;
};

#endif // LISTACONTORD_H
