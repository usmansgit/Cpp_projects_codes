#include <iostream>

using namespace std;

int main()
{
    int number = 0;
    cout << "Enter a number: ";
    cin >> number;
    int cube = number*number*number;

    if (cube/(number*number) != number){
        cout << "The cube of "<<number<<" is not " << cube <<endl;
    }
    else {
        cout << "The cube of "<<number<<" is " << cube <<endl;
    }
    return 0;
}

