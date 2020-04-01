#include <iostream>

using namespace std;

class operatore {
 void show (int i){
 cout << "sono il figlio N." << i << endl;
 }

};

int main()
{
    //int dim, i ;
    operatore *arr ;
    //cout << "number of object :_";
   // cin >> dim;
    //arr = new operatore [3];
    operatore op_1;
     operatore op_2;
      operatore op_3;
    * (arr + 0 ) =  &op_1;
    * (arr + 1 ) =  &op_2;
    * (arr + 2 ) =  &op_3;

    cout << arr.show(1) << endl;
        cout << *(arr+1).show(2) << endl;
    cout << *(arr + 2).show(3) << endl;

    //for (i = 0; i < dim; i++){
  //      *(arr + i) = &operatore ogg_+i;
//        cout << *(arr + i) << endl;

    //}
    return 0;
}
