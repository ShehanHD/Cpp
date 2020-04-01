#include <iostream>
#include <stdexcept>
#include <math.h>
//#include "prototipi.h"

using namespace std;

template <typename tipo>
class equazione{
private:
    tipo delta;
    void deltaControllo(tipo const&, tipo const&, tipo const&);
    void pura(tipo const&, tipo const&);

public:
    void operandi();
};

template <typename tipo>
void equazione<tipo> :: operandi(){
    tipo a, b, c;

    cout << "operando 1(a) > ";
    cin >> a;
    cout << sizeof(a);
    cout << "operando 2(b) > ";
    cin >> b;
    cout << "operando 3(c) > ";
    cin >> c;
    cout << endl << "\t\t" << a << "x^2 + (" << b << "x) + (" << c << ")" << endl<<endl;


    if(a <= 0){
        throw underflow_error("operando 'a' deve essere magiore da 0");
    }
    else if(b != 0 && c == 0){      //spuria    ax^2 + bx = 0
        cout << "x1 = 0" << endl;
        cout << "x2 = " << (b/a)*-1 << endl;
    }
    else if(b == 0 && c != 0){      //pura      ax^2 + c = 0
        pura(a, c);
    }
    else if(b == 0 && c == 0){
        cout << "x1 = x2 = 0";
    }
    else{
        deltaControllo(a, b, c);
        cout << "x1 = " << (-b + sqrt(delta)) / (2*a) << endl;
        cout << "x2 = " << (-b - sqrt(delta)) / (2*a) << endl;
    }
}

template <typename tipo>
void equazione<tipo> :: deltaControllo(tipo const& a, tipo const& b, tipo const& c){
    if((pow(b, 2)-(4 * a * c)) < 0){
        throw underflow_error("Non esiste i risultati reali ==> (delta e' negativo!)");
    }
    delta = pow(b, 2)-(4 * a * c);
}

template <typename tipo>
void equazione<tipo> :: pura(tipo const& a, tipo const& c){
    if(((-c)/a) < 0){
        throw underflow_error("Imposibile ==> radice di (-c)/a e' negativo ");
    }

    cout << "x1 = " << sqrt((-c)/a) << endl;
    cout << "x2 = " << (sqrt((-c)/a))*-1 << endl;
}

int main(){
    equazione<float> equ;
    int x;
do{
    try{
        equ.operandi();
    }
    catch(exception const& err){
        cerr << err.what() << endl;
    }

    cout << endl << "Premere un tasto qualsiasi per continuare\n0 per uscire" << endl << "scelta > ";
    cin >> x;
}while(x != 0);
    return 0;
}
