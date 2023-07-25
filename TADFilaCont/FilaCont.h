#ifndef FILACONT_H_INCLUDED
#define FILACONT_H_INCLUDED

class FilaCont
{
  public:
    FilaCont(int tam);
    ~FilaCont();
    int getInicio();
    int desenfileira();        // remove primeiro
    void enfileira(int val);    // insere no final
    bool vazia();
    void imprime();
  private:
    int max;    // capacidade maxima de elementos
    int inicio; // posicao do primeiro no
    int fim;    // posicao apos o ultimo no
    int *vet;   // vetor que armazena a lista
};

#endif // FILCONT_H_INCLUDED
