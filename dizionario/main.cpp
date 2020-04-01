#include <iostream>
#include <exception>
#include "dictionary.h"

using namespace std;

int main()
{
    dictionary dic;
    string key;
    int anno, mese, data, x;

    do{
        cout << "\tAnno > ";
        cin >> anno;
        cout << "\tmese > ";
        cin >> mese;
        cout << "\tdata > ";
        cin >> data;

        dic.add("anno", anno);
        dic.add("mese",mese);
        dic.add("data",data);

        cout << "per continuare 1\nper uscire 0\n>>>>>>>>>";
        cin >> x;
    }while(x != 0);


    dic.stampa();

    do{
        cout << endl << "uscire 'end'\n\tchiave > ";
        cin >> key;
        try{
            dic.get(key);
        }
        catch(const char* msg){
            std::cerr<< msg << '\n';
        }
    }while(key != "end");

    dic.save();

    return 0;
}
