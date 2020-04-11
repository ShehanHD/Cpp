#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class ogg{
    private:
        double latoB;
        double latoH;
    public:
		ogg(){
			cout<<"ciao";
		};
        void getRettangolo(){
        cout<<"Inserisci Lato Base :";
        cin>>latoB;
        cout<<"Inserisci Lato Altezza :";
        cin>>latoH;
        }

        void setRettangolo(){
        	if(latoH<=0||latoB<=0){
        		throw "Il valore che hai inserito per il Rettangolo e' sbagliato!";
			}
            cout<<"Area      ="<<latoH*latoB<<endl;
            cout<<"Perimetro ="<<(latoH*2)+(latoB*2)<<endl;
            cout<<"Diogonale ="<<sqrt(pow(latoH,2)+pow(latoB,2))<<endl;
        }

        void getQuadro(){
            cout<<"Inserisci Lato:";
            cin>>latoB;

        }
         void setQuadro(){
         	if(latoB<=0){
        		throw "Il valore che hai per il Quadro inserito e' sbagliato!";
			}
            cout<<"Area      ="<<latoB*latoB<<endl;
            cout<<"Perimetro ="<<latoB*4<<endl;
            cout<<"Diogonale ="<<sqrt((pow(latoB,2))+(pow(latoB,2)))<<endl;
        }

        void getCerchio(){
            cout<<"inserisci Raggio:";
            cin>>latoB;
        }

        void setCerchio(){
        	if(latoB<=0){
        		throw "Il valore che hai inserito per il Cerchio e' sbagliato!";
			}
            cout<<"Perimetro ="<<2*(22/7)*latoB<<endl;
            cout<<"Area      ="<<(22/7)*pow(latoB,2)<<endl;
        }
};

int main()
{
    ogg prov;
    int scelta;
do{
    cout<<endl<<"Scegli il Ogetto"<<endl<<"\t1 per Rettangolo"<<endl<<"\t2 per Quadro"<<endl<<"\t3 per Cerchio"<<endl<<"\t0 per Uscire"<<endl;
    cin>>scelta;

    if(scelta==1){
    system("cls");
    cout<<"Rettangolo"<<endl<<endl;
	    try{
	    prov.getRettangolo();
	    prov.setRettangolo();
		}
		catch(const char* msg){
		cerr<<endl<<msg<<endl;	
		}
	}

    if(scelta==2){
    system("cls");
    cout<<"Quadro"<<endl<<endl;
	    try{
	    prov.getQuadro();
	    prov.setQuadro();
	    }
	    catch(const char* msg){
	    cerr<<endl<<msg<<endl;	
		}
	}

    if(scelta==3){
    system("cls");
    cout<<"Cerchio"<<endl<<endl;
	    try{
		prov.getCerchio();
	    prov.setCerchio();
		}
		catch(const char* msg){
		cerr<<endl<<msg<<endl;	
		}
	}
	
}while(scelta!=0);
    return 0;
}
