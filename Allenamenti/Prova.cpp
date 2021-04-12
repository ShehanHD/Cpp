#include "Prova.h"

void Prova::menu(std::string menuItem[]) {
    int count = 0;

    for (count = 0; count < 2; count++)
    {
        std::cout << menuItem[count] << " ";
    }
}