#include <iostream>
#include <conio.h>
#include <cstdlib>


using namespace std;
// lista.h : libreria contenente vari metodi per la gestione di una lista
class classLista
{
    public:
    struct nodo
     {
       int inf;               // parte informazione del nodo (un solo dato)z
       struct nodo *psucc;    // dato di tipo puntatore alla struttura stessa
                              // contiene l'indirizzo (puntatore) all'elemento
                              // successivo della struttura
      // nodo *psucc;           // dichiarazione semplificata alternativa
     };


    nodo *tdl;       // puntatore al primo elemento della lista
    nodo *pnuovo;    // puntatore del nuovo nodo creato
    nodo *p;         // puntatore di comodo per scorrere la lista
    nodo *pprec;     // puntatore del nodo precedente a quello attuale
                     // (per inserimenti ed estrazioni intermedie)
//----------------------------------------------------
// costruttore  : si inizializzano i puntatori
classLista()
{
    tdl = NULL;
    pnuovo = NULL;
    p = NULL;
    pprec = NULL;
}
//----------------------------------------------------
// Creazione del nodo
void CreaNodo()
{
    int numero;
    cout<<"\nDigita il valore da inserire nel nodo...:  ";
    cin>>numero;
    pnuovo = new nodo;       // dall'area heap viene prelevato un indirizzo
                             // ed associato al nodo creato
    pnuovo->inf=numero;      // il numero inserito è posto nella parte
                             // informazione del nodo

    pnuovo->psucc=NULL;      // nella parte puntatore del nodo viene
                             // inserita la costante NULL
 }
//------------------------------------------------
// Controllo lista vuota
bool ListaVuota()
{
  bool vuota = true;
  if (tdl == NULL)    // se il punt. di inizio lista è nullo la lista è vuota
    {
      cout <<" ATTENZIONE !! Lista vuota. "<<endl;
      vuota = false;
    }

  return vuota;
}
//-----------------------------------------------
// Inserimento in testa di un nodo
void InserimentoT()
{
   system("cls");                      //per pulire lo schermo
   cout<<"\n==========================================";
   cout<<"\n==== Inserimento in testa di un nodo  ====";
   cout<<"\n==========================================\n";
   classLista::CreaNodo();
  if (tdl != NULL)           // se la lista non è vuota
    {
      pnuovo->psucc=tdl;     // il punt. di inizio lista viene inserito nella
                             // parte punt. del nuovo nodo
    }
  tdl = pnuovo;             // il punt. del nuovo nodo diventa, comunque, il
                            // punt. di inizio lista
  classLista::Visualizzazione();

}
//-----------------------------------------------
// Inserimento in coda di un nodo
void InserimentoC()
{
  system("cls");                      //per pulire lo schermo
  cout<<"\n==========================================";
  cout<<"\n==== Inserimento in coda di un nodo   ====";
  cout<<"\n==========================================\n";
  CreaNodo();
  if (tdl == NULL)     // se la lista è vuota il nodo viene inserito in testa
    {
      tdl=pnuovo;     // il nuovo puntatore diventa il puntatore di inizio lista
    }
  else
    {  // se la lista è piena si scorre fino all'ultimo nodo
       // ed il nuovo puntatore viene inserito nella parte
       // puntatore dell'ultimo nodo (che diventa il penultimo)
     p = tdl;      // tdl viene assegnato al puntatore di comodo
     while (p->psucc != NULL)     // vedi NOTA
        {
            p=p->psucc;  // si scorre la lista
        }
     // fino ad arrivare all'ultimo nodo in cui nella parte
     // puntatore si inserisce il puntatore del nuovo nodo
     p->psucc=pnuovo;
    }

}
//-----------------------------------------------
// Inserimento ordinato
// con tale procedura si ottiene una lista i cui nodi risultano ordinati
// in senso crescente rispetto alla parte informativa
void Inserimento_Ordinato()
{
    system("cls");                      //per pulire lo schermo
    cout<<"\n===========================================";
    cout<<"\n==== Inserimento ordinato di un nodo   ====";
    cout<<"\n===========================================\n";
    CreaNodo();
    if (tdl == NULL)     // se la lista è vuota il nodo inserito diventa
        {tdl = pnuovo;}  // il primo nodo
    else{
      // se il nodo da inserire con puntatore pnuovo è minore o uguale
      // al primo nodo della lista, si inserisce in tdl ovvero come primo nodo
      if (tdl->inf >= pnuovo->inf)
        {
          pnuovo->psucc=tdl;
          tdl = pnuovo;
         }
       else{
            // si scorre la lista fino alla fine e finchè il nodo pnuovo
            // risulta maggiore del nodo corrente. Se si arriva alla fine
            // della lista o si trova un nodo maggiore di quello pnuovo,
            // si procede all'inserimento
            p = tdl;
            while ((p!= NULL) && (pnuovo->inf > p->inf))
                {
                  pprec = p;       // si salva il puntatore corrente
                  p = p->psucc;    // per scorrere la lista
                 }
             pnuovo->psucc = p;      //inserimento intermedio : vedi Nota1
             pprec->psucc = pnuovo;
            }
      }
}

/* ====================== Nota 1 =====================
   Inserimento intermedio di un nodo :

 per inserire un nodo nuovo (puntatore pnuovo) fra due nodi qualsiasi
 occorre gestire il puntatore del primo nodo (pprec) ed il puntatore
 del secondo nodo (p). L'inserimento viene ottenuto inserendo il puntatore
 (p) del secondo nodo nella parte puntatore del nodo nuovo (pnuovo->psucc)
 ed inserendo il puntatore (pnuovo) del nuovo nodo nella parte puntatore
 del primo nodo (pprec->psucc).
*/

//-----------------------------------------------
// Inserimento intermedio di un nodo in una data posizione
void Inserimento_Nodo()
{
    int pos;  // posizione richiesta
    int x;    // per contare i nodi della lista
    system("cls");                      //per pulire lo schermo
    cout<<"\n========================================================";
    cout<<"\n==== Inserimento di un nodo in una data posizione   ====";
    cout<<"\n========================================================\n";
    CreaNodo();
    cout<<"\nDigitare la posizione in cui inserire il nodo nella lista...: ";
    cin>>pos;

    if (tdl == NULL)         // se la lista è vuota il nodo inserito diventa
        {tdl = pnuovo;}      // il primo nodo
    else
       {
         if (pos==1)   // per la prima pos. si effettua l'inserimento in testa
            {
              pnuovo->psucc=tdl;
              tdl = pnuovo;
            }
         else
            {
              x=1;
              p=tdl;
              /* si effettua un ciclo per scorrere la lista fino alla posizione
                 richiesta e finchè la lista è piena. Se la posizione richiesta
                 supera il numero di nodi presenti nella lista, il nodo viene
                 inserito in coda.
              */
              while (x < pos && p != NULL)
               {
                  pprec = p;       // si salva il puntatore corrente
                  p = p->psucc;    // per scorrere la lista
                  ++x;             // si contano i nodi
               }
               pnuovo->psucc = p;      //inserimento intermedio : vedi Nota1
               pprec->psucc = pnuovo;
            }
       }
}
//-----------------------------------------------------
// Estrazione in testa di un nodo
void EstrazioneT()
{
    system("cls");                      //per pulire lo schermo
    cout<<"\n===========================================";
    cout<<"\n====  Estrazione in  testa di un nodo  ====";
    cout<<"\n===========================================\n";

  if (ListaVuota() == true)
    {
       p = tdl;     // p puntatore di comodo
       cout << " Nodo estratto --->  " << p->inf<<endl;
       // la coda potrebbe essere costituita da un solo nodo
       if (p->psucc == NULL)
           {tdl = NULL;}
       else
           {tdl = p->psucc;}
       delete p;
    }

}
//-----------------------------------------------------
// Estrazione in coda di un nodo
void EstrazioneC()
{
    system("cls");                      //per pulire lo schermo
    cout<<"\n===========================================";
    cout<<"\n====  Estrazione in coda di  un nodo   ====";
    cout<<"\n===========================================\n";
  if (ListaVuota() == true)
    {
       p = tdl;        // p puntatore di comodo per scorrere la lista
                       // è il puntatore del nodo attuale
       pprec = NULL;  // puntatore del nodo precedente a quello
                      // attuale puntato dal puntatore p

     // il ciclo serve per scorrere l'intera lista ed arrivare all'ultimo nodo
     // conservando il puntatore del nodo precedente, in cui si deve
     // inserire la costante NULL nella sua parte puntatore
       while (p->psucc != NULL)
           {
             pprec = p;       // si salva il puntatore corrente
             p = p->psucc;    // per scorrere la lista
           }

       cout << " Nodo estratto --->  " << p->inf<<endl;
       delete p;
       // se la lista è costituita da un solo nodo si elimina l'intera lista
       if (p == tdl)
           {tdl = NULL;}
       else
           {pprec->psucc = NULL;}

    }

}
//-----------------------------------------------------
// Estrazione di un determinato nodo (estrazione intermedia)
void Estrazione_Nodo()
{
 int cerca;
 bool flag;
    system("cls");                   //per pulire lo schermo
    cout<<"\n=======================================";
    cout<<"\n====  Estrazione di un dato nodo   ====";
    cout<<"\n=======================================\n";
 if (ListaVuota() == true)
   {
      cout<<"Digitare il nodo da eliminare dalla lista...: ";
      cin>>cerca;
      p = tdl;
      pprec = NULL;
      if (p->inf == cerca)   // il nodo da eliminare è il primo
        {
           tdl = p->psucc;
           cout << " Nodo eliminato --->  " << p->inf<<endl;
           delete p;
        }
      else
        {
            flag = false;
            while (p != NULL && flag == false)
              {
                if (p->inf == cerca)
                   {
                     cout << " Nodo eliminato --->  " << p->inf<<endl;
                     pprec->psucc = p->psucc;    // vedi Nota2
                     delete p;
                     flag=true;
                   }
                else
                    {
                       pprec = p;      // si salva il puntatore corrente
                       p = p->psucc;   // per scorrere la lista
                    }
              }
              if (flag==false)
                {
                   cout << "Nodo inesistente nella lista"<<endl;
                }
        }
   }
}
/* ====================== Nota 2 =====================
   Estrazione  intermedia di un nodo :

 per estrarre dalla lista un nodo posto fra due nodi qualsiasi
 occorre gestire il puntatore del nodo (pprec) precedente
 a quello da estrarre ed il puntatore del nodo da estrarre (p).
 L'estrazione viene ottenuta inserendo la parte puntatore del
 nodo da estrarre (p->psucc) nella parte puntatore del nodo
 precedente (pprec->psucc). In questo nodo viene così inserito
 il puntatore del nodo successivo a quello estratto.
*/
//-------------------------------------------------
//Visualizzazione lista
void Visualizzazione()
{
 int x=0;
     system("cls");
     cout<<"\n=====================================\n";
     cout<<"==== Visualizzazione della lista ====\n";
     cout<<"=====================================\n";
 if (classLista::ListaVuota() == true)
   {
     p = tdl;            // p parte da tdl per scorrere tutta la lista
     while (p != NULL)   // vedi NOTA
        {
          ++x;   // per la posizione del nodo nella lista
          cout <<" Nodo "<<x<<"--> "<< p->inf<<endl;
          p = p->psucc;
        }
    }

}
//-----------------------------------------------------
// Ricerca nodo
void Ricerca()
{
 int cerca;
 bool flag=false;
 int x=0;
      system("cls");
      cout<<"\n========================================\n";
      cout<<"==== Ricerca di un nodo nella lista ====\n";
      cout<<"========================================\n";
 if (ListaVuota() == true)
   {
      cout<<"\n Digita il nodo da ricercare .....: ";
      cin>>cerca;
      p = tdl;
      while (p != NULL && flag == false)
         {
           ++x;    // per contare i nodi
           if (p->inf == cerca)
              {
                 flag=true;
              }
           else
              {
                 p = p->psucc;   // per scorrere la lista
              }
         }
     if (flag == true)
          {cout << "\n Il nodo occupa la posizione numero "<<x<<"\n";}
     else
          {cout << "\n Nodo non trovato !!\n";}
   }

}

};
