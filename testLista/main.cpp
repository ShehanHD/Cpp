#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class test{
    public:
    void f1(){
        int a, b;
        printf("Num1 : ");
        scanf("%d", &a);
        printf("Num2 : ");
        scanf("%d", &b);

        printf("somma%d\n\n", a + b);
    }
};

typedef struct self{
    struct self *prev;
    test value;
    struct self *next;
}nodo;


void createNew(nodo **testa, nodo **coda);

int main()
{
    nodo *listT = NULL;
    nodo *listC = NULL;

    for(int i = 0; i<3; i++)
        createNew(&listT, &listC);

    while(listT){
    listT->value.f1();
    listT = listT->next;
    }

    return 0;
}

void createNew(nodo **testa, nodo **coda){
    int val;
    nodo *nuovo;

    test t;

    nuovo = (nodo*)malloc(sizeof(nodo));

    if((*testa) == NULL){
        nuovo->prev = NULL;
        nuovo->value = t;
        nuovo->next = (*testa);

        (*testa) = nuovo;
        (*coda) = nuovo;
    }
    else{
        nuovo->prev = NULL;
        nuovo->value = t;
        nuovo->next = (*testa);

        (*testa) = nuovo;
        (*testa)->next->prev = nuovo;
    }

}
