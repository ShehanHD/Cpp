#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>     /* atoi */ 
#include <vector>
#include <list>
#include <iterator>
#include <stack>
#include "BST.h"

using namespace std;

typedef struct self {
    struct self* prev;
    int value;
    struct self* next;
}nodo;

void listMio(nodo** testa, int t);          //la funziona per inserire i dati alla mia lista ha due parametri uno per riferimento(la lista) altra per valore(intero)
void listMioPrint(nodo* list);              //la funziona per stampare i dati ha un parametro per valore(la mia lista)

void vectorSTL(vector<int>* num, int x);    //la funziona per inserire i dati alla vettore STL ha due parametri uno per riferimento(Il vettore) altra per valore(intero)
void vectorSTLPrint(vector<int> num);       //la funziona per stampare i dati ha un parametro per valore(Il vettore STL)

void listSTL(list<int>* num, int x);        //la funziona per inserire i dati alla lista STL ha due parametri uno per riferimento(La lista) altra per valore(intero)
void listSTLPrint(list<int> num);           //la funziona per stampare i dati ha un parametro per valore(la list STL)

void stackSTL(stack<int>* num, int x);      //la funziona per inserire i dati alla stack STL ha due parametri uno per riferimento(Il stack) altra per valore(intero)
void stackSTLPrint(stack<int> num);         //la funziona per stampare i dati ha un parametro per valore(la stack STL)

int main()
{
    char s[255] = "(100+200)*3-(25+5)"; //Stringa di Partenza
    char s1[25] = ""; //Stringa d'appoggio per la costruzione del numero da estrarre
    int i = 0; // Indice utilizzato per la scansione della stringa s
    int j = 0; // Indice utilizzato per la scansione della stringa s

    vector<int> numVector;  //dichierazion di un oggetto usando il classe template vector
    nodo* li = NULL;        //iniziare una lista
    list<int> liSTL;        //dichierazion di un oggetto usando il classe template lista
    stack<int> stSTL;       //dichierazion di un oggetto usando il classe template stack
    BST bst;                //dichierazion di un oggetto albero binario

    printf("Espressione iniziale: %s\n\n", s);

    // i per scrrere sui caratteri della stringa
    // j per indicare posizione del array s1(dove si trova i valori numerici)
    while (s[i] != '\0') {                      // loop si gira fino a carattere speciale
        j = 0;

        while (s[i] >= '0' && s[i] <= '9') {    //loop si girà finche trova un carattere tra 0 a 9
           
            s1[j] = s[i];                       //mette il valore numerci nel array s1
            i++;
            j++;
            if (!(s[i] >= '0' && s[i] <= '9' && s[i] == '('))
            {
                s1[j] = '\0';

                //inserire i valori ai contenitori
                vectorSTL(&numVector, atoi(s1));
                listMio(&li, atoi(s1));
                listSTL(&liSTL, atoi(s1));
                stackSTL(&stSTL, atoi(s1));
                bst.addLeaf(atoi(s1));
            }

        }
        i++;
    }

    cout << "\nVector STL \t=>\t ";
    vectorSTLPrint(numVector);
    cout << "\nList \t\t=>\t ";
    listMioPrint(li);
    cout << "\nList STL \t=>\t ";
    listSTLPrint(liSTL);
    cout << "\nstack STL \t=>\t ";
    stackSTLPrint(stSTL);
    cout << "\nAlbero binario \t=>\t ";
    bst.printInOrder();

    return 0;
}

void vectorSTL(vector<int>* num, int x) {
    num->push_back(x);
}

void vectorSTLPrint(vector<int> num) {
    for (auto i = num.begin(); i != num.end(); ++i) {
        cout << *i << " ";
    }
}

void listSTL(list<int>* num, int x) {
    num->push_back(x);
}

void listSTLPrint(list<int> num) {
    list <int> ::iterator i;
    for (i = num.begin(); i != num.end(); ++i)
        cout << *i << ' ';

}

void stackSTL(stack<int>* num, int x) {
    num->push(x);
}

void stackSTLPrint(stack<int> num) {
    while (!num.empty())
    {
        cout << num.top() << ' ';
        num.pop();
    }
}

void listMio(nodo** testa, int t) {
    unsigned int val;
    nodo* nuovo;

    nuovo = (nodo*)malloc(sizeof(nodo));

    if ((*testa) == NULL) {
        nuovo->value = t;
        nuovo->next = (*testa);

        (*testa) = nuovo;
    }
    else {
        nuovo->value = t;
        nuovo->next = (*testa);

        (*testa) = nuovo;
    }

}

void listMioPrint(nodo* list) {
    while (list) {
        printf("%d ", list->value);
        list = list->next;
    }
}