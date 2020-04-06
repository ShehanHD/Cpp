#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>     /* atoi */ 
#include <vector>
#include <list>
#include <iterator>
#include <stack>

using namespace std;
/* Il Seguente Programma Svolge quanto segue
Data una stringa contenente una espressione algebrica s, estrarre i valori numerici presenti al proprio interno, trasformarli in interi e memorizzarli in un array
ESERCIZI

    * Documentare i prototipi delle Seguenti funzioni, fornendo:
            * una breve descrizione sul compito svolto dalle funzioni
            * sullo scopo dei parametri
            * sul motivo per cui saranno passati per valore o per riferimento
            * una breve descrizionee degli eventuali risultati prodotti dalle finzioni

 1 Progettare il prototipo di una funzione che svolga lo stesso compito
 2 Progettare il prototipo di una funzione e successivamento l'Algoritmo che svolga lo stesso compito del programma proposto salvando i dati numerici in un array dinamico
 3 Progettare il prototipo di una funzione e successivamento l'Algoritmo che svolga lo stesso compito del programma proposto salvando i dati numerici in una lista
 4 Progettare il prototipo di una funzione e successivamento l'Algoritmo che svolga lo stesso compito del programma proposto salvando i dati numerici in una lista utilizzando la classe list STL del C++
 5 Progettare il prototipo di una funzione e successivamento l'Algoritmo che svolga lo stesso compito del programma proposto salvando i dati numerici in uno Stack utilizzando la classe Stack STL del C++
 6 Progettare il prototipo di una funzione e successivamento l'Algoritmo che svolga lo stesso compito del programma proposto salvando i dati numerici in un Albero Binario di Ricerca
 7 Costruire un main che richiami la funzioni e ne produca lo stesso output del programma di riferimento
 Documentare i prototipi delle funzioni fornendo una breve descrizione sullo scopo dei parametri sul motivo per cui saranno passati per valore o per riferimento
 e degli eventuali risultati prodotti dalle finzioni

*/

typedef struct self {
    struct self* prev;
    int value;
    struct self* next;
}nodo;

void listMio(nodo** testa, int t);
void listMioPrint(nodo* list);

void vectorSTL(vector<int>* num, int x);
void vectorSTLPrint(vector<int> num);

void listSTL(list<int>* num, int x);
void listSTLPrint(list<int> num);

void stackSTL(stack<int>* num, int x);
void stackSTLPrint(stack<int> num);

int main()
{
    char s[255] = "(100+200)*3-(25+5)"; //Stringa di Partenza
    char s1[25] = ""; //Stringa d'appoggio per la costruzione del numero da estrarre
    int i = 0; // Indice utilizzato per la scansione della stringa s
    int j = 0; // Indice utilizzato per la scansione della stringa s

    vector<int> numVector;
    nodo* li = NULL;
    list<int> liSTL;
    stack<int> stSTL;

    printf("Espressione iniziale: %s\n\n", s);

    while (s[i] != '\0') {  // Ciclo per l'estrazione dei Valori Numerici
        j = 0;
        while (s[i] >= '0' && s[i] <= '9') {  //Ciclo per la preparazione delle eventuali stringhe numeriche composte da piu' simboli numerici
            s1[j] = s[i];
            i++;
            j++;
            if (!(s[i] >= '0' && s[i] <= '9'))
            {
                s1[j] = '\0';
                vectorSTL(&numVector, atoi(s1));
                listMio(&li, atoi(s1));
                listSTL(&liSTL, atoi(s1));
                stackSTL(&stSTL, atoi(s1));
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