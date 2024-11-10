#include <iostream>
#include <string>
#include "person.hh"

using namespace std;



int main() {
    Person pal("Matt", 18);
    cout << pal.get_name() << endl;
    pal.print();
    pal.celebrate_birthday(19);
    pal.print();
}


