#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int num1;
    char str[10];
}fbinari;

int main()
{
    int i=0;
    fbinari x[3];

    for(; i<3; i++){
    scanf("%d",&x[i].num1);
    scanf("%s",x[i].str);}

    FILE * fp = fopen("file","wb");


    fwrite(&x,sizeof(fbinari),3,fp);

    fclose(fp);

     fp = fopen("file", "rb");

    while(!feof(fp)){
        fread(&x,sizeof(fbinari),3,fp);
    i++;
    }

    for(i=0; i<3; i++){
    printf("%d  %s\n",x[i].num1,x[i].str);
    }
    fclose(fp);
    return 0;
}
