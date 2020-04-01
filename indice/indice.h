#include <iostream>

typedef struct self{
    std::string word;
    struct self *next;
}nodo;

class INDEX{
private:
    nodo *arr[26];

public:
    void addNodo(int, std::string);
    INDEX();
    void stampa();
};
