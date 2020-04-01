#include <iostream>

using namespace std;
class prova{
private:
    int id;
    char prodotto[10];
    float prezzo;
    float quantita;

public:
    prova();
    void getDataBase();
    //void salvaDataBase();
    void setCart(int cId, char cProd, float cPrez, float cQuan);
    void setAddProdotti();
};
