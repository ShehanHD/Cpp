#include <iostream>

typedef struct self{
    std::string key;
    int index;
    struct self *next;
}nodo;

class dictionary{
    private:
        int index;
        nodo *testa;
        int *arr;

    public:
        dictionary();
        void add(std::string, int);
        void get(std::string);
        void stampa();
        void save();
};
