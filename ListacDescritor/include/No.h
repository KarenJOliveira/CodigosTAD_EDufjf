#ifndef NO_H
#define NO_H
#include <iostream>
using namespace std;

class No
{
    public:
        No();
        ~No();
        int getInfo();
        No* getProx();
        void setInfo(int val);
        void setProx(No *p);

    private:
        int info; //informacao armazenada
        No* prox; // nó seguinte
};

#endif // NO_H
