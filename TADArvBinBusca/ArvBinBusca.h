#ifndef ARVBINBUSCA_H_INCLUDED
#define ARVBINBUSCA_H_INCLUDED
#include "NoArv.h"

class ArvBinBusca
{
  private:
    NoArv *raiz; // ponteiro para o nó raiz da árvore
    void libera(NoArv *p);
    NoArv* auxInsere(NoArv *p, int val);
    NoArv* auxRemove(NoArv *p, int val);
    void auxImprime(NoArv *p);
    bool auxBusca(NoArv *p, int val);
    int auxMenor(NoArv *p);
    NoArv* auxRemoveMin(NoArv *p);

  public:
    ArvBinBusca();
    ~ArvBinBusca();
    int getRaiz();
    void insere(int val);
    void remove(int val);
    bool vazia(); // verifica se a árvore está vazia
    void imprime();
    bool busca(int val);
    bool buscaIt(int val);
    int menor();
    int menorIt();
    void removeMin();
    void removeMinIt();
};

#endif // ARVBINBUSCA_H_INCLUDED
