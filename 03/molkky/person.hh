#ifndef PERSON_HH
#define PERSON_HH
#include <iostream>
#include <string>

class Person
{
public:
    Person(const std::string &name);
    std::string get_name();
    int get_points();
    void add_points(int points);
    bool has_won();
private:
    int points_;
    std::string name_;
};

#endif // PERSON_HH
