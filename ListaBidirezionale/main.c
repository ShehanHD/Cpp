#include <stdio.h>
#include <stdlib.h>

typedef struct self{
    struct self *prev;
    int value;
    struct self *next;
}nodo;

class test{
    int f1(){
        int a, b;
        scanf("%d", &a);
        scanf("%d", &b);

        return a + b;
    }
};

void createNew(nodo **testa, nodo **coda);

int main()
{
    nodo *listT = NULL;
    nodo *listC = NULL;

    for(int i = 0; i<3; i++)
        createNew(&listT, &listC);

    printf("\nScorrendo al Prossimo\nNEXT\tPREV\n");
    while(listT){
    printf("%.6x %.6x %d(%.6x)\n", listT->next, listT->prev, listT->value, listT);
    listT = listT->next;
    }

    printf("\nScorrendo al Precidente\nNEXT\tPREV\n");
    while(listC){
    listC->value.f();
    listC = listC->prev;
    }

    return 0;
}

void createNew(nodo **testa, nodo **coda){
    int val;
    nodo *nuovo;

    printf("Inserisci il nuovvo valore > ");
    scanf("%d", &val);

    test = t;

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
