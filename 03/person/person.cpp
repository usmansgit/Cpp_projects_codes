#include "person.hh"
#include <iostream>
#include <string>

using namespace std;



Person::Person(const string &name, int age):
    name_(name),
    age_(age){

}

string Person::get_name() const{
    return name_;
}

void Person::celebrate_birthday(int next_age){

    age_=next_age;

}

void Person::print() const{
    cout << name_ << " : " << age_ << endl;
}
