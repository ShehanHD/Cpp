#include <iostream>
#include <exception>
#include <stdio.h>
#include <math.h>

using namespace std;

class equazione{
protected:
        float a, b, c;

public:
        void setValues(float a = 0, float b = 0, float c = 0);

};

class secondoGrado : public equazione{
public:
        float setDelta();
};


int main()
{
    secondoGrado eq;

    try
    {
       cout << eq.setDelta();
    }
    catch(const std::underflow_error& e)
    {
        std::cerr<< e.what() << '\n';
    }


    return 0;
}

void equazione::setValues(float a, float b, float c){
    if(a == 0){
        throw std::underflow_error("a non puo' essere 0");
    }
    else{
        this->a = a;
        this->b = b;
        this->c = c;
    }
}

float secondoGrado::setDelta(){
    float delta;
    this->setValues(1, 5, 3);
    delta = pow(this->b, 2) - (4 * a * c);

    if(delta < 0){
        throw std::underflow_error("Delta e' negativo");
    }

    return delta;
}
