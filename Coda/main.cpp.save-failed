#include <iostream>
#include <stdio.h>

using namespace std;

int con(int arr[],int dim);
void ins (int arr[],int dim,int &coda,int &testa);
void est(int arr[],int dim,int &coda,int &testa);

int main()
{
    int arr[5]={0,0,0,0,0};
    int coda = 0;
    int testa = 0;
    int i;

    for(i=0; i<2; i++){
    con(arr,5);
    ins(arr,5,coda,testa);
    }

    printf("%d %d\n",testa, coda);

    for(i=0; i<5; i++){
        printf("%d ",arr[i]);
    }

    return 0;
}

int con(int arr[],int dim){
int i;
int pieno=0;

for(i=0; i<dim; i++){
    if(arr[i]==1){
        pieno++;
    }
}

return pieno;
}

void ins (int arr[],int dim,int &coda,int &testa){
    int x =con(arr,dim);
    if(x<dim){
        arr[coda]=1;
        if (coda<dim){
            coda=x+1;
        }
        else {
            coda=0;
        }
    }
    else{
        printf("\nArray pieno\n");
    }
}

void est(int arr[],int dim,int &coda,int &testa){
    int x =con(arr,dim);
    if(x<5){
       arr[coda]=0;

       if (coda<dim){
            testa=x+1;
        }
        else {
            testa=0;
        }
    }
}
