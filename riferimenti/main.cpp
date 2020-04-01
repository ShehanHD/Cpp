#include <iostream>

using namespace std;

void somma(int num[], int dim);

int main()
{
    int a[5];
    int i;
    
    for(i=0; i<5; i++){
	cout<<"NUM"<<i+1<<": ";
    cin>>a[i];
	}	

    somma(a,5);
    
    cout<<"\n";
    cout<<"ORIGINALE: ";
    for(i=0; i<5; i++){
 	printf("%d ",a[i]);
	}

	
    return 0;
}


void somma(int num[], int dim){
int i;
int num2[5];


cout<<"MODIFICATO: ";
for(i=0; i<dim; i++){
	num2[i]=num[i];
	num2[i]+=1;
 	printf("%d ",num2[i]);
}
	
}
