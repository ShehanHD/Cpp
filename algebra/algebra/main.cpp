#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>     /* atoi */ 
#include <vector>
#include <list>
#include <iterator>
#include <stack>

using namespace std;

void vectorSTL(vector<int>* num, int x);    
void vectorSTLPrint(vector<int> num);       

void listSTL(list<int>* num, int x);       
void listSTLPrint(list<int> num);           

void stackSTL(stack<int>* num, int x);      
void stackSTLPrint(stack<int> num);        

int main()
{
    char s[255] = "(100+200)*3-(25+5)"; 
    char s1[25] = ""; 
    int i = 0;
    int j = 0;

    vector<int> numVectorB;
    vector<int> numVector;
     

    printf("Espressione iniziale: %s\n\n", s);

    while (s[i] != '\0') {                    
        j = 0;
        if (s[i] == '(') {
            i++;
            while (s[i] >= '0' && s[i] <= '9') {    
                s1[j] = s[i];
                i++;
                j++;
                if (!(s[i] >= '0' && s[i] <= '9'))
                {
                    s1[j] = '\0';

                    vectorSTL(&numVectorB, atoi(s1));
                }
            }
        }
        if (s[i] != ')' || s[i] != '+' || s[i] != '-' || s[i] != '/' || s[i] != '*') {
            while (s[i] >= '0' && s[i] <= '9') {
                s1[j] = s[i];
                i++;
                j++;
                if (!(s[i] >= '0' && s[i] <= '9'))
                {
                    s1[j] = '\0';

                    vectorSTL(&numVectorB, atoi(s1));
                }
            }
        }
        else {
            while (s[i] >= '0' && s[i] <= '9') {
                s1[j] = s[i];
                i++;
                j++;
                if (!(s[i] >= '0' && s[i] <= '9'))
                {
                    s1[j] = '\0';

                    vectorSTL(&numVector, atoi(s1));
                }
            }
        }
        i++;
    }

    cout << "\nVector STL \t=>\t ";
    vectorSTLPrint(numVector);


    return 0;
}

void vectorSTL(vector<int>* num, int x) {
    num->push_back(x);
}

void vectorSTLPrint(vector<int> num) {
    for (auto i = num.begin(); i != num.end(); ++i) {
        cout << *i << " ";
    }
}

void listSTL(list<int>* num, int x) {
    num->push_back(x);
}

void listSTLPrint(list<int> num) {
    list <int> ::iterator i;
    for (i = num.begin(); i != num.end(); ++i)
        cout << *i << ' ';

}

void stackSTL(stack<int>* num, int x) {
    num->push(x);
}

void stackSTLPrint(stack<int> num) {
    while (!num.empty())
    {
        cout << num.top() << ' ';
        num.pop();
    }
}
