#include <iostream>
#include <vector>
#include "Student.h"

using namespace std;

int main() {
    vector<Student> students;

    students.emplace_back( "shehan", "don", "shehanhd@gmail.com");
    students.emplace_back( "shehani", "dona", "shehanihd2@gmail.com");
    students.emplace_back( "ghj", "rty", "rty@gmail.com");
    students.emplace_back( "tyjytj", "rtyrty", "rtyrs@gmail.com");
    students.emplace_back( "tjtyjtyj", "rtyrty", "rtyesy@gmail.com");
    students.emplace_back( "ffghf", "trytr", "rtyerth@gmail.com");
    students.emplace_back( "fhfghg", "hfgfh", "rteytry@gmail.com");
    students.emplace_back( "fghfgh", "fghfghrt", "retytry@gmail.com");

    for (int i = 0; i < students.size(); i++) {
        cout << students[i] << endl;
    }

    return 0;
}
