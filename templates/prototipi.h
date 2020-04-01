#include <iostream>

using namespace std;

template <typename tipo>
class equazione{
private:
    tipo delta;
    void deltaControllo(tipo const&, tipo const&, tipo const&);
    void pura(tipo const&, tipo const&);

public:
    void operandi();
};
