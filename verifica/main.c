#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void crea(int **array, int dim);
void carica( int **array, int dim);
void calcola(int *array, int dim);
void modifica(int *array, int dim);

int main(){
    printf("ciao");
    int *arr;
    int x;

    scanf("%d", &x);

    crea(&arr, x);
    carica(&arr, x);


    calcola(arr, x);
    modifica(arr, x);

    return 0;
}


void crea(int **array, int dim){

    *array=(int*)malloc(sizeof(int)*dim);

}

void carica( int **array, int dim){
    for(int i=0; i<dim; i++){
        *((*array) + i) = (rand()%50)+1;
    }

    for(int i=0; i<dim; i++){
        printf("%d ", *((*array) + i));
    }
}

void calcola(int *array, int dim){

}

void modifica(int *array, int dim){
}
