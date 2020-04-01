#include <iostream>
#include <fstream>
#include "indice.h"
#include "funC.h"

using namespace std;

string UPPER(string x){
    string upper;
    for(unsigned int i=0; i<x.length(); i++){
        upper += toupper(x[i]);
    }
    return upper;
}

int main(){
    string output;
    INDEX test;
    ifstream myReadFile;

    system("app.py Gabriele_Semeraro_Relazione_routing");
    myReadFile.open("MyFile.txt");


    if (myReadFile.is_open()) {
        while (!myReadFile.eof()){
            myReadFile >> output;
            if(h(toupper(output[0])) >= 0){
                //cout << output << endl;
                test.addNodo(h(toupper(output[0])) , UPPER(output));
            }
        }
    }
    else{
        cout << "file non esiste!";
    }

    test.stampa();
    return 0;
}
