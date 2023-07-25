#ifndef PILHACONT_H_INCLUDED
#define PILHACONT_H_INCLUDED

class PilhaCont
{
  public:
    PilhaCont(int tam);
    ~PilhaCont();
    int getTopo();
    void empilha(int val);    // insere no final
    int desempilha();         // remove ultimo
    void imprime();
    bool vazia();
  private:
    int max;  // capacidade maxima de elementos
    int topo; // posicao do ultimo elemento
    int *vet; // vetor que armazena a pilha
};

#endif // PILHACONT_H_INCLUDED
