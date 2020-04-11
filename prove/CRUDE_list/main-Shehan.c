#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "prototipi.h"

int main()
{
    NODE *test;
    int request;
    // creare LISTA
    test = create(test);

    do{
    printf("1 per Aggiungere NODO alla testa\n2 per Aggiungere NODO alla coda\n3 per Eleminare NODO dalla testa\n4 per Eleminare NODO dalla coda\n0 per Uscire\n\nscegli : ");
    scanf("%d",&request);

    switch (request)
    {
    case 1:
        system("cls");
        //aggiungere NODO alla testa 0-4
        for(int i=0; i<1; i++){
            test = add(test, i, 0);
        }
        //test = add(test, 10, 2);
        printList(test);
        break;

    case 2:
        system("cls");
        //aggiungere NODO alla coda 0-4
        for(int i=0; i<1; i++){
            test = add(test, i, -1);
        }
        printList(test);
        break;

    case 3:
        system("cls");
        //eleminare NODO dalla testa
        test = del(test, 0);
        printList(test);
        break;

    case 4:
        system("cls");
        //eleminare NODO dalla coda
        test = del(test, -1);
        printList(test);
        break;
    }
    }while(request != 0);



    return 0;
}

