#include "IOFile.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>

using namespace std;

// Private Functions
string IOFile::toUPPER(string word){
    string ret;

    for(unsigned int i=0; i<word.length(); i++){
        ret += toupper(word[i]);
    }

    return ret;
}

int IOFile::h(char x){
    return (x-65);
}


string IOFile::filterSTR(string line){
    char alphabetString[100];
    int j = 0;

    for(int i = 0; line[i] != '\0'; ++i)
    {
        if ((line[i] >= 'a' && line[i]<='z') || (line[i] >= 'A' && line[i]<='Z'))
        {
            alphabetString[j++] = line[i];
        }
    }
    alphabetString[j] = '\0';

    return alphabetString;
}

void IOFile::PDFtoTXT(char *file) {
    char createTXT[50]="";

    //create the path to python file(to convert PDF to TXT)
    strcat(createTXT,"python ");
    strcat(createTXT,"app.py ");
    strcat(createTXT,file);

    if (this->exists("app.py")) {
        //execute file python
        system(createTXT);
    }
    else{
        cout << "\nFile .py non esiste\n";
    }

}

bool IOFile::exists(const char *fileName)
{
    ifstream file(fileName);

    if(file){
        return true;
    }
    else{
        return false;
    }
}

//Public Functions
void IOFile::setPDF(char *file){
    ifstream ReadFile;
    char readTXT[50]="";
    string output, pagina;

    //convert file
    this->PDFtoTXT(file);

    //create path to read the TXT file to send data to class INDEX
    strcat(readTXT,file);
    strcat(readTXT,".txt");


        if (this->exists(readTXT)) {
             ReadFile.open(readTXT);

             while (!ReadFile.eof()){
                ReadFile >> output;
                ReadFile >> pagina;
                if(h(toupper(output[0])) >= 0){

                    cout << this->filterSTR(output) << "\t" << pagina << endl;

                    //funNODO(this->h(toupper(output[0])), UPPER(this->filterSTR(output)));
                }
            }
             ReadFile.close();
        }
        else{
            cout << "\nFile non esiste\n";
        }
}

void IOFile::setTXT(char *file){
    ifstream ReadFile;
    char readTXT[50]="";
    string output;
    int number;

    strcat(readTXT,file);
    strcat(readTXT,".txt");

    if (this->exists(readTXT)) {
        ReadFile.open(readTXT);

        while (!ReadFile.eof()){
            ReadFile >> output;
            ReadFile >> number;
            if(h(toupper(output[0])) >= 0){
                cout << this->filterSTR(output)  << " " << number << endl;
                //funNODO(this->h(this->toUPPER(output[0])) , UPPER(this->filterSTR(output)));
            }
        }

        ReadFile.close();
    }
    else{
        cout << "\nFile non esiste\n";
    }
}

void IOFile::setManual(){
    //dafare
}
