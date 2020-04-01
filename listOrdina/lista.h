
#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;

class classLista
{
    public:
    struct nodo
     {
       int inf;               // parte informazione del nodo (un solo dato)
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


classLista()
{
    tdl = NULL;
    pnuovo = NULL;
    p = NULL;
    pprec = NULL;
}

void CreaNodo()
{
    int numero;
    cout<<"\nDigita il valore da inserire nel nodo...:  ";
    cin>>numero;
    pnuovo = new nodo;       // dall'area heap viene prelevato un indirizzo
                             // ed associato al nodo creato
    pnuovo->inf=numero;      // il numero inserito � posto nella parte
                             // informazione del nodo

    pnuovo->psucc=NULL;      // nella parte puntatore del nodo viene
                             // inserita la costante NULL
}

bool ListaVuota()
{
  bool vuota = true;
  if (tdl == NULL)    // se il punt. di inizio lista � nullo la lista � vuota
    {
      cout <<" ATTENZIONE !! Lista vuota. "<<endl;
      vuota = false;
    }

  return vuota;
}

void InserimentoT()
{
   system("cls");                      //per pulire lo schermo
   cout<<"\n==========================================";
   cout<<"\n==== Inserimento in testa di un nodo  ====";
   cout<<"\n==========================================\n";
   classLista::CreaNodo();
  if (tdl != NULL)           // se la lista non � vuota
    {
      pnuovo->psucc=tdl;     // il punt. di inizio lista viene inserito nella
                             // parte punt. del nuovo nodo
    }
  tdl = pnuovo;             // il punt. del nuovo nodo diventa, comunque, il
                            // punt. di inizio lista
  classLista::Visualizzazione();

}

void InserimentoC()
{
  system("cls");                      //per pulire lo schermo
  cout<<"\n==========================================";
  cout<<"\n==== Inserimento in coda di un nodo   ====";
  cout<<"\n==========================================\n";
  CreaNodo();
  if (tdl == NULL)     // se la lista � vuota il nodo viene inserito in testa
    {
      tdl=pnuovo;     // il nuovo puntatore diventa il puntatore di inizio lista
    }
  else
    {  // se la lista � piena si scorre fino all'ultimo nodo
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

void Inserimento_Ordinato()
{
    system("cls");                      //per pulire lo schermo
    cout<<"\n===========================================";
    cout<<"\n==== Inserimento ordinato di un nodo   ====";
    cout<<"\n===========================================\n";
    CreaNodo();
    if (tdl == NULL)     // se la lista � vuota il nodo inserito diventa
        {tdl = pnuovo;}  // il primo nodo
    else{
      // se il nodo da inserire con puntatore pnuovo � minore o uguale
      // al primo nodo della lista, si inserisce in tdl ovvero come primo nodo
      if (tdl->inf >= pnuovo->inf)
        {
          pnuovo->psucc=tdl;
          tdl = pnuovo;
         }
       else{
            // si scorre la lista fino alla fine e finch� il nodo pnuovo
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

    if (tdl == NULL)         // se la lista � vuota il nodo inserito diventa
        {tdl = pnuovo;}      // il primo nodop1.is_file()
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
                 richiesta e finch� la lista � piena. Se la posizione richiesta
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

void EstrazioneC()
{
    system("cls");                      //per pulire lo schermo
    cout<<"\n===========================================";
    cout<<"\n====  Estrazione in coda di  un nodo   ====";
    cout<<"\n===========================================\n";
  if (ListaVuota() == true)
    {
       p = tdl;        // p puntatore di comodo per scorrere la lista
                       // � il puntatore del nodo attuale
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
       // se la lista � costituita da un solo nodo si elimina l'intera lista
       if (p == tdl)
           {tdl = NULL;}
       else
           {pprec->psucc = NULL;}

    }

}

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
      if (p->inf == cerca)   // il nodo da eliminare � il primo
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

void oderLista(){
    p = tdl;
    nodo *p1 = p;
    nodo *sposta = p;
    nodo *sposta1 = p;
    nodo *spoCon = NULL;
    nodo *appogio = NULL;


    while(p){
        //cout << "> "<< p << " " << p1 << " " << p->psucc << " " << p->inf << "\n\n";
        while(sposta != NULL){
          //cout << p << " " << sposta << "\n";
          
          //! faccio il spostamento se valore controll < sposta
          if(p->inf > sposta->inf){
              cout << p->inf<<", "<<p << " " << sposta->inf<<", "<<sposta <<"\n";

              appogio = sposta;
              p1->psucc = appogio;          
              appogio->psucc = p;

              cout << appogio->inf<<", "<<appogio << " " << p1->psucc->inf<<", "<<p1->psucc <<"\n";

              // spoCon = p;
              // sposta1->psucc = spoCon;
              // spoCon->psucc = sposta->psucc;

              //p = appogio;
          }
          sposta = sposta->psucc;
          //sposta1 = sposta;
        }
      sposta = p->psucc;
      //p1 = p;
      p = p->psucc;
    }
}

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
