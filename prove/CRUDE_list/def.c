#include "prototipi.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

NODE* create(NODE* head){
    head = NULL;

    return head;
}

NODE* add(NODE* head, int val, int possition){

    if (possition == 0){
        return addToHead(head,val);
    }
    else if (possition == -1){
        return addToTail(head, val);
    }
    else
    {
        return addInMiddle(head, val, possition);
    }
}


NODE* del(NODE* head, int possition){
    if (possition == 0){
    return delFromHead(head);
    }
    else if (possition == -1){
        return delFromTail(head);
    }
    else
    {
        //addInMiddle();
    }
}

NODE* addToHead(NODE* head, int val){
    //! crea nuovo nodo e assegna il valore
    NODE* nuovo = (NODE*) malloc(sizeof(NODE));
    nuovo->x = val;

    //! il nuovo nodo punta al nodo che la testa ha puntata a successivamente
    nuovo->next = head;
    //! testa punta al nuovo nodo
    head = nuovo;

    //! ritorna la lista
    return head;
}

NODE* addToTail(NODE* head, int val){
    //!crea indice a trovare l'ultima elemento
    NODE* index = head;
    NODE* previous;             //* alla fine previous si resta sul'ultimo elemento mentre Index resta su NULL

    //! crea nuovo nodo e assegna il valore
    NODE* nuovo = (NODE*) malloc(sizeof(NODE));
    nuovo->x = val;

    if(head == NULL){
        nuovo->next = head;
        head = nuovo;
    }
    else{
        while(index != NULL){
            previous = index;
            index = index->next;

            if(index == NULL){
                previous->next = nuovo;         //* previous si punta al prossima nodo che il nuovo
                nuovo->next = index;            //* nuovo si punta al NULL
                free(index);
                //printf("%x %x\n", nuovo, index);
            }
            //free(previous);
        }
    }
    return head;

}

NODE* delFromHead(NODE* head){
    NODE* temp = head;

    if(temp==NULL){
        printf("LISTA E VUOTO!!!!!!\n\n");
        return 0;
    }
    else{
        head = temp->next;
        free(temp);

        return head;
    }
}

NODE* delFromTail(NODE* head){
    NODE* index = head;
    NODE* previous;
    NODE* temp;

    if(head==NULL){
        printf("LISTA E VUOTO!!!!!!\n\n");
        return 0;
    }
    else{
        while(index->next->next != NULL){
        previous = index;
        index = index->next;

            if(index->next->next == NULL){
                previous = index->next->next;
                temp = previous->next;
                printf("%x %x \n\n", previous, index->next->next);
            }

        //temp = previous;
    }
        free(temp);


        return head;
    }
}

void printList(NODE *head){
        //stampare LISTA
        while(head != NULL){
            printf("%x %2d\n",head, head->x);
            head = head->next;
        }
}

NODE *addInMiddle(NODE *head, int val, int where){
    NODE *index = head;

    for(int i=0; i<=where; i++){
        index = index->next;
        if(i==(where==i)){
            printf("%x", index);
        }
    }

    return 0;
}
