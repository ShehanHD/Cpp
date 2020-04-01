#include <iostream>
#include <fstream>
#include "prov.h"

using namespace std;

int main()
{
    prova carello;
    int scelta;

    carello.getDataBase();

    printf("\n\n1 for Add Product to cart\n2 for Eliminate a Product from cart\n3 for Finalize the Purches\n");
    scanf("%d",&scelta);

    switch (scelta){
        case 1:
            carello.setAddProdotti();
            break;
        case 2:
            printf("2");
            break;
        case 3:
            printf("3");
            break;
    }

    return 0;
}
