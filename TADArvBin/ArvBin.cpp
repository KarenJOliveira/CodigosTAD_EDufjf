#include <iostream>
#include "ArvBin.h"

using namespace std;

ArvBin::ArvBin()
{
    raiz = NULL;
}

ArvBin::~ArvBin()
{
    libera(raiz);
}

void ArvBin::libera(NoArv *p)
{
    if(p != NULL)
    {
        libera(p->getEsq());
        libera(p->getDir());
        delete p;
    }
}

void ArvBin::anulaRaiz()
{
    raiz = NULL;
}

int ArvBin::getRaiz()
{
    if(raiz != NULL) //ou if(!vazia())
        return raiz->getInfo();
    else
    {
        cout << "Árvora vazia!" << endl;
        exit(1);
    }
}

void ArvBin::cria(int val, ArvBin *sae, ArvBin *sad)
{
    NoArv *p = new NoArv();
    p->setInfo(val);
    if(sae == NULL) p->setEsq(NULL);
    else p->setEsq(sae->raiz);
    if(sad == NULL) p->setDir(NULL);
    else p->setDir(sad->raiz);
    raiz = p;
}

void ArvBin::montaArvore()
{
    if(raiz == NULL)
        raiz = auxMontaArvore();
    else
        cout << "Arvore ja montada" << endl;
}
NoArv* ArvBin::auxMontaArvore()
{
    int val;
    cout << "Digite um valor (-1 para NULL): ";
    cin >> val;
    if(val != -1)
    {
        NoArv *p = new NoArv();
        p->setInfo(val);
        cout << "Esquerda..." << endl;
        p->setEsq(auxMontaArvore());
        cout << "Volta no noh " << p->getInfo() << endl;
        cout << "Direita..." << endl;
        p->setDir(auxMontaArvore());
        cout << "Volta no noh " << p->getInfo() << endl;
        return p;
    }else
        return NULL;
}

void ArvBin::insere(int val)
{
    raiz = auxInsere(raiz, val);
}
NoArv* ArvBin::auxInsere(NoArv *p, int val)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(val);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else
    {
        char dir;
        cout << val << " a esquera (e) ou direita (d) do noh " << p->getInfo() << "? ";
        cin >> dir;
        if(dir == 'e' || dir == 'E')
            p->setEsq(auxInsere(p->getEsq(), val));
        else
            p->setDir(auxInsere(p->getDir(), val));
    }
    return p;
}

bool ArvBin::vazia()
{
    return raiz == NULL;
}

bool ArvBin::busca(int val)
{
    return false;
}

void ArvBin::imprime()
{
    cout << "Arvore: ";
    auxImprime(raiz);
    cout << endl;
}

void ArvBin::auxImprime(NoArv *p)
{
    if(p != NULL)
    {
        cout << p->getInfo() << " ";
        auxImprime(p->getEsq());
        auxImprime(p->getDir());
    }
}

int ArvBin::contaNos()
{
    return auxContaNos(raiz);
}
int ArvBin::auxContaNos(NoArv *p)
{
    if(p != NULL)
        return 1 + auxContaNos(p->getEsq()) + auxContaNos(p->getDir());
    else
        return 0;
}

int ArvBin::contaNos2()
{
    int cont = 0;
    auxContaNos2(raiz, &cont);
    return cont;
}
void ArvBin::auxContaNos2(NoArv *p, int *cont)
{
    if(p != NULL)
    {
        *cont += 1;
        auxContaNos2(p->getEsq(), cont);
        auxContaNos2(p->getDir(), cont);
    }
}


int ArvBin::somaNos()
{
    return auxSomaNos(raiz);
}

int ArvBin::auxSomaNos(NoArv *p)
{
    if(p != NULL)
        return p->getInfo() + auxSomaNos(p->getEsq()) + auxSomaNos(p->getDir());
    else
        return 0;
}

float ArvBin::mediaNos()
{
    int soma = 0;
    int cont = 0;
    auxMediaNos(raiz, &soma, &cont);
    return (float)soma/cont;
}

void ArvBin::auxMediaNos(NoArv *p, int *soma, int *cont)
{
    if(p != NULL)
    {
        *soma += p->getInfo();
        *cont += 1;
        auxMediaNos(p->getEsq(), soma, cont);
        auxMediaNos(p->getDir(), soma, cont);
    }
}

int ArvBin::maior(int v1, int v2)
{
    if(v1 > v2)
        return v1;
    return v2;
}

int ArvBin::altura()
{
    return auxAltura(raiz);
}

int ArvBin::auxAltura(NoArv *p)
{
    if(p != NULL)
        return 1 + maior(auxAltura(p->getEsq()), auxAltura(p->getDir()));
    return -1;
}

void ArvBin::impNivel(int k)
{
    cout << "Nivel " << k << ": ";
    auxImpNivel(raiz, 0, k);
    cout << endl;
}

void ArvBin::auxImpNivel(NoArv *p, int atual, int k)
{
    if(p != NULL)
    {
        if(k == atual)
            cout << p->getInfo() << " ";
        else
        {
            auxImpNivel(p->getEsq(), atual+1, k);
            auxImpNivel(p->getDir(), atual+1, k);
        }
    }
}

void ArvBin::percursoLargura()
{
    if(raiz != NULL)
    {
        cout << "Largura: ";
        FilaEncad f;
        f.enfileira(raiz);
        while(!f.vazia())
        {
            NoArv *p = f.desenfileira();
            cout << p->getInfo() << " ";
            if(p->getEsq() != NULL)
                f.enfileira(p->getEsq());
            if(p->getDir() != NULL)
                f.enfileira(p->getDir());
        }
    }
}
