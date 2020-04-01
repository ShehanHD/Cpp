#include <iostream>
#include "BST.h"

using namespace std;

#define clear system("cls");

void add(BST* bst) {
    int input;

    do {
        cout << "\n\n-1 per uscire\n>";
        cin >> input;

        if (input != -1) {
            bst->addLeaf(input);
        }
    } while (input != -1);
}

void legami(BST* bst) {
    int scelta, x;
    do {
        cout << "\n\n-1 per uscire\n>";
        cin >> x;
        if (x != -1) {
            bst->printChildren(x);
        } 
    } while (x != -1);
}

int main() {
    BST bst;
    int scelta, check;

    do {
        cout << "\n\n1 per aggiungere dati\n2 per visualizzare\n3 per visualizzare i legami del un nodo\n4 per contare i nodi\n5 per contare foglie\n6 per la somma\n7 per la media\n8 per cercare\n9 per eleminare un nodo\n10 per valore minimo\n11 per valore massimo\n0 per uscire\nscegli>";
        cin >> scelta;

        switch (scelta) {
        case 1:
            clear;
            add(&bst);
            break;
        case 2:
            clear;
            bst.printInOrder();
            break;
        case 3:
            clear;
            legami(&bst);
            break;
        case 4:
            clear;
            cout << bst.countNodes();
            break;
        case 5:
            clear;
            cout << bst.countLeaves();
            break;
        case 6:
            clear;
            cout << bst.sum();
            break;
        case 7:
            clear;
            cout << bst.medium();
            break;
        case 8:
            clear;
            cout << "add a number> ";
            cin >> check;
            cout << bst.search(check);
            break;
        case 9:
            clear;
            bst.printInOrder();
            cout << "add a number to eleminate> ";
            cin >> check;
            cout << bst.search(check);
            break;
        case 10:
            clear;
            cout << bst.findMin();
            break;
        case 11:
            clear;
            cout << bst.findMax();
            break;
        default:
            cout << "Ciao!!!!!!!";
            break;
        }
    } while (scelta != 0);

    return 0;
}
