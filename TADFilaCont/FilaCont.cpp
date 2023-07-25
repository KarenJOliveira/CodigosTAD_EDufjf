#include <iostream>
#include "FilaCont.h"

using namespace std;

FilaCont::FilaCont(int tam)
{
    inicio = 0;
    fim = 0;
    max = tam;
    vet = new int[max];
}

FilaCont::~FilaCont()
{
    delete [] vet;
}

int FilaCont::getInicio()
{
    if(inicio != fim)
        return vet[inicio];
    cout << "ERRO GETINICIO: Fila vazia." << endl;
    exit(1);
}

void FilaCont::enfileira(int val)
{
    if(fim < max)
        vet[fim++] = val;
    else
    {
        if(inicio > 0)  //alternativa
        {
            for(int i = 0; i < fim-inicio; i++)
                vet[i] = vet[inicio+i];
            fim -= inicio;
            inicio = 0;
            vet[fim++] = val;
        }
        else
            cout << "ERRO ENFILEIRA: Vetor cheio!" << endl;
    }
}

int FilaCont::desenfileira()
{
    if(inicio != fim)
    {
        inicio++;
        return vet[inicio-1];
    }
    else
        cout << "ERRO DESENFILEIRA: Fila vazia!" << endl;
}

bool FilaCont::vazia()
{
    return inicio == fim;
}

void FilaCont::imprime()
{
    cout << "Fila: ";
    for(int i = inicio; i < fim; i++)
        cout << vet[i] << " ";
    cout << endl;
}
