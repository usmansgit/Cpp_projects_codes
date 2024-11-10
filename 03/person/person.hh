#ifndef PERSON_HH
#define PERSON_HH
#include <string>

using namespace std;



class Person{
public:
    Person(const string &name, int age);
    string get_name() const;
    void celebrate_birthday(int next_age);
    void print() const;
private:
    string name_;
    int age_;

};

#endif // PERSON_HH
