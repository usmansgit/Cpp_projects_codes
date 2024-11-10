#include "clock.hh"
#include <iostream>
#include <iomanip>

using namespace std;

Clock::Clock(int hour, int minute):
    hours_(hour),
    minutes_(minute){

}

void Clock::tick_tock()
{
    ++minutes_;
       if ( minutes_ >= 60 ) {
           minutes_ = 0;
           ++hours_;
       }
       if ( hours_ >= 24 ) {
           hours_ = 0;
       }

}

void Clock::print()
{
    cout << setw(2) << setfill('0') << hours_
            << "."
            << setw(2) << minutes_
            << endl;
}
