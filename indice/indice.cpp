#include "indice.h"
#include <iostream>

using namespace std;

INDEX::INDEX(){

    for(int i=0; i<26; i++){
        nodo *testa = NULL;
        this->arr[i] = testa;
    }
}

void INDEX::addNodo(int ind, string ins){
    nodo *nuovo = new nodo;
    nodo *temp = this->arr[ind];
    int control = 0;

    nuovo->word = ins;

    if(temp == NULL){
        nuovo->next=temp;
        temp = nuovo;
    }
    else{
        while(temp->next){
            control = (nuovo->word).compare(temp->word);
            if ( control < 0 && control != 0 ){
                nuovo->next = temp->next;
                temp->next = nuovo;
            }

            temp = temp->next;
        }
    }

    this->arr[ind] = temp;
}

void INDEX::stampa(){
    nodo *temp;
    for(int i=0; i<26; i++){
        temp = this->arr[i];
        while(temp != NULL){
        cout << temp->word << endl;
        temp = temp->next;
        }
    }

    //cout << this->arr[0]->next->word;
}
