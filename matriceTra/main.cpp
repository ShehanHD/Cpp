#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;


int main()
{
    srand(time(NULL));

    int arr1[2][3];
    int arr2[3][2];
    int arr3[2][2];
    int i,j,k;
    int ris,ris2;

    for(i=0; i<2; i++){
        for(j=0; j<3; j++){
            arr1[i][j]=(rand()%4)+1;
            arr2[j][i]=(rand()%4)+1;
        }
    }

    for(i=0; i<2; i++){
        for(k=0; k<2; k++){
            ris=0;
                for(j=0; j<3; j++){
                        ris+=arr1[i][j]*arr2[j][k];
                }
            arr3[i][k]=ris;
        }
    }

      for(i=0; i<2; i++){
        for(j=0; j<3; j++){
            printf("%d ",arr1[i][j]);
        }
        printf("\n");
    }
printf("\n");
    for(i=0; i<3; i++){
        for(j=0; j<2; j++){
            printf("%d ",arr2[i][j]);
        }
        printf("\n");
    }
 printf("\n");
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            printf("%d ",arr3[i][j]);
        }
        printf("\n");
    }

    return 0;
}
