#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a positive number: " ;

    uint number;
    cin >> number;

    if(number <= 0)
    {
        cout << "Only positive numbers accepted" <<endl;
        return 0;
    }

    uint minimal_distance = number;
    uint p1 = 0;
    uint p2 = 0;

    for(uint i = 1; i < number; i++)
    {
        uint dividion_result = number/i;
        if(dividion_result*i == number)
        {
            uint distance = dividion_result -i;

            if(distance < minimal_distance)
            {
                minimal_distance = distance;
                p1 = i;
                p2 = dividion_result;
            }
        }
    }

    cout << number << " = " << p1 << " * " << p2 << endl;

    return 0;
}
