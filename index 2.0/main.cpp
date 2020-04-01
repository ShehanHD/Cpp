#include <iostream>
#include "IOFile.h"
#include <string.h>
#include <cstdlib>

using namespace std;

int main() {
    IOFile x;
    char str[50];
    int choise;

do{
    cout << "1 per file PDF\n2 per file TXT\n3 per Ins. Manuale\n0 per Uscire\nscegli > ";
    cin >> choise;

    switch (choise){
    case 1:
        cout << "Nome di File PDF(senza estenzione) > ";
        cin >> str;
        x.setPDF(str);
        break;
    case 2:
        cout << "Nome di File TXT(senza estenzione) > ";
        cin >> str;
        x.setTXT(str);
        break;
    case 3:
        x.setManual();
        break;
    }
}while(choise != 0);



    return 0;
}
