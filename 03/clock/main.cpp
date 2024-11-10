#include <iostream>
#include "clock.hh"

using namespace std;

int main() {
    Clock time(23, 59);
    time.print();
    time.tick_tock();
    time.print();
}
