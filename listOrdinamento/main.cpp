//====================  GESTIONE DI UNA LISTA =======================
#include <iostream>
#include <conio.h>                  // per la funzione getche()
#include "list.h"   // file header contenente gli attributi e i metodi
                     // per la gestione di una lista
using namespace std;
// ============================ MAIN =========================================
int main (int argc, char *argv[])
{
 int n,*pn;
   pn=&n;
 char tasto;
 classLista lista;
 do
  {
    system("cls");
    cout<<"===========================================================\n";
    cout<<"=====           MENU' GESTIONE LISTA (con OOP)        =====\n";
    cout<<"===========================================================\n";
    cout<<"\n  1 - Inserimento di un nodo in testa\n";
    cout<<"  2 - Inserimento di un nodo in coda\n";
    cout<<"  3 - Inserimento ordinato di un nodo\n";
    cout<<"  4 - Inserimento di un nodo in una posizione generica\n";
    cout<<"  5 - Estrazione di un nodo in testa \n";
    cout<<"  6 - Estrazione di un nodo in coda \n";
    cout<<"  7 - Estrazione di un determinato nodo\n";
    cout<<"  8 - Visualizzazione lista completa\n";
    cout<<"  9 - Ricerca di un nodo\n";
    cout<<" 10 - Eliminazione della lista\n";
    cout<<" 0 - FINE\n";

    cout<<"\n Inserire il numero dell'opzione scelta.....:  ";
    cin>>*pn;

    switch(*pn)
    {
      case 1:
            do
             {
               lista.InserimentoT();
               cout<<"\n\nPremere Invio per continuare, un tasto qualsiasi "
                      "per uscire ";
               tasto = getche();
             }while((int)tasto == 13);  // 13 è il codice ASCII del tasto Invio
            break;
      case 2:
          do
             {
               lista.InserimentoC();
               cout<<"\n\nPremere Invio per continuare, un tasto qualsiasi "
                      "per uscire ";
               tasto = getche();
             }while((int)tasto == 13);  // 13 è il codice ASCII del tasto Invio
          break;

       case 3:
          do
             {
               lista.Inserimento_Ordinato();
               cout<<"\n\nPremere Invio per continuare, un tasto qualsiasi "
                      "per uscire ";
               tasto = getche();
             }while((int)tasto == 13);  // 13 è il codice ASCII del tasto Invio
          break;

      case 4:
          do
             {
               lista.Inserimento_Nodo();
               cout<<"\n\nPremere Invio per continuare, un tasto qualsiasi "
                      "per uscire ";
               tasto = getche();
             }while((int)tasto == 13);   // 13 è il codice ASCII del tasto Invio
          break;

      case 5:
          do
             {
               lista.EstrazioneT();
               cout<<"\n\nPremere Invio per continuare, un tasto qualsiasi "
                      "per uscire ";
               tasto = getche();
             }while((int)tasto == 13);  // 13 è il codice ASCII del tasto Invio
          break;
       case 6:
          do
             {
               lista.EstrazioneC();
               cout<<"\n\nPremere Invio per continuare, un tasto qualsiasi "
                      "per uscire ";
               tasto = getche();
             }while((int)tasto == 13);  // 13 è il codice ASCII del tasto Invio
          break;

      case 7:
          do
             {
               lista.Estrazione_Nodo();
               cout<<"\n\nPremere Invio per continuare, un tasto qualsiasi "
                      "per uscire ";
               tasto = getche();
             }while((int)tasto == 13);  // 13 è il codice ASCII del tasto Invio
          break;
      case 8:
           lista.Visualizzazione();
           system("PAUSE");break;
      case 9:
           do
             {
               lista.Ricerca();
               cout<<"\n\nPremere Invio per continuare, un tasto qualsiasi "
                      "per uscire ";
               tasto = getche();
             }while((int)tasto == 13);   // 13 è il codice ASCII del tasto Invio
           break;
      case 10:  // eliminazione lista

           if (lista.ListaVuota() == true)
                {
                   lista.tdl = NULL;    // per eliminare la lista è sufficiente
                                       // che il puntatore iniziale diventi NULL

                   cout<<"\n Lista eliminata !!\n";
                }

            system("PAUSE");
            break;
      case 0:cout<<" FINE\n";default:break;
        }
        }while(*pn!=0);
 system("PAUSE");
}
/* =================================== NOTA ===============================
1) Il seguente ciclo,usando il puntatore di comodo p, consente di scorrere
 tutta la lista partendo dal primo nodo della stessa :

  p = tdl;           per partire dal primo nodo p diventa uguale al
                     puntatore di inizio lista
  while (p!= NULL)   si controlla se p è diventato NULL ovvero se
                     è stato elaborato anche l'ultimo nodo
    {
       istruzioni;
       p = p->psucc;   p assume il valore presente nella parte puntatore
                       del nodo attuale, ovvero il puntatore al nodo successivo
    }

 all'uscita del ciclo il puntatore p è uguale a NULL, quindi non punta a
 nessun nodo (attenzione !! non è il puntatore dell'ultimo nodo).

Se,invece,  si effettua il ciclo,  :
2)
    p = tdl;           per partire dal primo nodo p diventa uguale al
                       puntatore di inizio lista
    while (p->psucc != NULL)  // si controlla se la parte puntatore del nodo
                              // è NULL, ovvero se si tratta dell'ultimo nodo
    {
        istruzioni;
        p = p->psucc;   p assume il valore presente nella parte puntatore
                        del nodo attuale, ovvero il puntatore al nodo successivo
    }

all'uscita del ciclo siamo arrivati all'ultimo nodo in cui la parte puntatore
è NULL e quindi non esiste un nodo successivo. In questo caso l'ultimo nodo
deve essere ancora sottoposto all'elaborazione interessata (per esempio la
visualizzazione dell'intera lista), utilizzando la sua parte informativa
(p->inf).
In genere quando si devono effettuare elaborazioni sulla parte informativa del
nodo è necessario ricorrere al ciclo 1) mentre quando si effettuano operazioni
sulla lista (inserimento, eliminazione) è necessario utilizzare il ciclo 2).
*/






