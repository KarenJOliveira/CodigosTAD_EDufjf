#ifndef FILAENCAD_H_INCLUDED
#define FILAENCAD_H_INCLUDED
#include "No.h"

class FilaEncad
{
public:
    FilaEncad();
    ~FilaEncad();
    int getInicio();
    void enfileira(int val);
    int desenfileira();
    bool vazia();
    void imprime();
private:
    No *inicio; // ponteiro para o primeiro
    No *fim;    // ponteiro para o ultimo
};
#endif // FILAENCAD_H_INCLUDED
