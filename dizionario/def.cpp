#include <iostream>
#include <malloc.h>
#include <exception>
#include "dictionary.h"
#include <fstream>

using namespace std;

//serve a leggere dal file � salvare index finale nella lista
dictionary::dictionary(){
    this->index = 0;
    this->testa = NULL;
    this->arr = (int*)malloc(sizeof(int)*100);
    ifstream myReadFile;

    myReadFile.open("example.txt");
    string output;
    int output2, output3;

    if (myReadFile.is_open()) {
        while (!myReadFile.eof()){
            myReadFile >> output;
            myReadFile >> output2;
            myReadFile >> output3;
            if(!myReadFile.eof()){
                nodo *nuovo = new nodo;

                nuovo->key = output;
                nuovo->index = output2;
                nuovo->next = this->testa;
                this->testa = nuovo;
                this->arr[this->index] = output3;
                this->index ++;
            }
        }
    }
    myReadFile.close();
}

void dictionary::add(string key, int value){
    nodo *nuovo = new nodo;

    this->arr[this->index] = value;

    nuovo->key = key;
    nuovo->index = this->index ++;
    nuovo->next = this->testa;
    this->testa = nuovo;
}

void dictionary::stampa(){
    nodo *read = this->testa;

    while(read != NULL){
        cout << read->key << " ==> " << arr[read->index] << "\n";
        read = read->next;
    }
}

void dictionary::get(string key){
    nodo *read = this->testa;
    int index = -1;

    while(read != NULL){
        if(read->key == key){
            index = read->index;
            cout << this->arr[index] << " " << endl;
        }
    read = read->next;
    }
    if(index == -1 && key != "end")
        throw "Key non e' valido!";
    else if( key == "end")
        throw "grazie!";

}

void dictionary::save(){
    int itr = 0;
    nodo *read = this->testa;
    ofstream fp;
    fp.open("example.txt");

    while(read != NULL){
        fp << read->key << " " << read->index << " " << arr[itr] <<endl;
        read = read->next;
        itr++;
    }

    fp.close();
}

