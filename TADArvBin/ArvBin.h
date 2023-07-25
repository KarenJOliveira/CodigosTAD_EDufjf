#ifndef ARVBIN_H_INCLUDED
#define ARVBIN_H_INCLUDED
#include "NoArv.h"
#include "FilaEncad.h"

class ArvBin
{
  private:
    NoArv *raiz; // ponteiro para o nó raiz da árvore
    void libera(NoArv *p);
    NoArv* auxMontaArvore();
    NoArv* auxInsere(NoArv *p, int val);
    void auxImprime(NoArv *p);
    int auxContaNos(NoArv *p);
    void auxContaNos2(NoArv *p, int *cont);
    int auxSomaNos(NoArv *p);
    void auxMediaNos(NoArv *p, int *soma, int *cont);
    int maior(int v1, int v2);
    int auxAltura(NoArv *p);
    void auxImpNivel(NoArv *p, int atual, int k);
  public:
    ArvBin();
    ~ArvBin();
    void anulaRaiz();
    int getRaiz();
    void cria(int val, ArvBin *sae, ArvBin *sad); // cria novo nó como raiz das sub-árvores à esquerda (sae) e à direita (sad)
    void montaArvore();
    void insere(int val);
    bool vazia(); // verifica se a árvore está vazia
    void imprime();
    bool busca(int val);
    int contaNos();
    int contaNos2();
    int somaNos();
    float mediaNos();
    int altura();
    void impNivel(int k);
    void percursoLargura();
};

#endif // ARVBIN_H_INCLUDED
