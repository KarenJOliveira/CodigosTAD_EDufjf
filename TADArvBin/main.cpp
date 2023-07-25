#include <iostream>
#include "ArvBin.h"

using namespace std;

int main()
{
    ArvBin a1, a2, a3, a4, a5, a6, a7, vazia;
    a6.cria(6, &vazia, &vazia);
    a7.cria(7, &vazia, &vazia);
    a4.cria(4, &vazia, &vazia);
    a5.cria(5, &a6, &a7);
    a3.cria(3, NULL, NULL);
    a2.cria(2, &a4, &a5);
    a1.cria(1, &a2, &a3);
    a2.anulaRaiz();
    a3.anulaRaiz();
    a4.anulaRaiz();
    a5.anulaRaiz();
    a6.anulaRaiz();
    a7.anulaRaiz();
    a1.imprime();
    cout << "Nos:     " << a1.contaNos() << endl;
    cout << "Soma:    " << a1.somaNos() << endl;
    cout << "Media:   " << (float)a1.somaNos()/a1.contaNos() << endl;
    cout << "Media:   " << a1.mediaNos() << endl;
    cout << "Altura:  " << a1.altura() << endl;
    a1.impNivel(3);

    a1.percursoLargura();

    /*
    ArvBin arv;
    //arv.montaArvore();
    //arv.imprime();
    arv.insere(15);
    arv.imprime();
    arv.insere(11);
    arv.imprime();
    arv.insere(12);
    arv.imprime();
    arv.insere(10);
    arv.imprime();
    arv.insere(7);
    arv.imprime();
    arv.insere(8);
    arv.imprime();
    arv.insere(1);
    arv.imprime();
    */
    return 0;
}
