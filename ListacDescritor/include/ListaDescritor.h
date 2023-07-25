#ifndef LISTADESCRITOR_H
#define LISTADESCRITOR_H


class ListaDescritor
{
    public:
        ListaDescritor();
       ~ListaDescritor();
       int get(int k);
       void set(int k, int val);
       int tamanho();
       void insereInicio(int val);
       bool busca(int val);
       void imprime();
       void insereFinal(int val);
       void insereK(int k,int val);
       void removeFinal();
       void removeK(int k);
       void removeInicio();
       int* menorProximo();
       bool inserePosicaoVal(int k,int val);
    private:
        No *primeiro;
        No *ultimo;
        int n;
};

#endif // LISTADESCRITOR_H
