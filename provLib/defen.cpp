#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prov.h"

using namespace std;

prova leggi[10];

prova::prova(){
printf("ciao!");
}
void prova::getDataBase(){
    int i=0;

    FILE * fp= fopen("DataBase.txt","r");

    while(!feof(fp)){
        fscanf(fp,"%d %s %f %f",&leggi[i].id,leggi[i].prodotto,&leggi[i].prezzo,&leggi[i].quantita);
    if(!feof(fp)){
        printf("%d  %s  %.2f  %.2f\n",leggi[i].id,leggi[i].prodotto,leggi[i].prezzo,leggi[i].quantita);
    }
    i++;
    }

    fclose(fp);
};

/*
void prova::salvaDataBase(){
FILE * fp= fopen("DataBase.txt","w");



fclose(fp);
};
*/

void setCart(int cId, char cProd, float cPrez, float cQuan){

};

void prova::setAddProdotti(){
int I;
float Q;

cout<<endl<<"Scegli la prodotto: ";
cin>>I;
cout<<endl<<"Aggiungi la quantita': ";
cin>>Q;

leggi[I].quantita-Q;
//setCart(&leggi[i].id,leggi[i].prodotto,&leggi[i].prezzo,Q);
printf("%d  %s  %.2f  %.2f\n",leggi[I].id,leggi[I].prodotto,leggi[I].prezzo,Q);
};
