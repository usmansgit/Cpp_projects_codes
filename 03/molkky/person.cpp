#include "person.hh"

Person::Person(const std::string &name):
    points_(0),
    name_(name)
{

}

std::string Person::get_name()
{
    return name_;

}

int Person::get_points()
{
    return points_;

}

void Person::add_points(int points)
{
    points_ +=points;
    if(points_ > 50){
            points_ = 25;
        }

}

bool Person::has_won()
{
    return points_ ==50;

}
