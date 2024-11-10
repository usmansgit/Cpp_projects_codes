#include <iostream>

using namespace std;

void jackpot(unsigned long int all, unsigned long int part){

    unsigned long int frac_all = 1;
    for (unsigned long int i=1; i<=all; i++){
        frac_all *=i;
    }
    //cout << frac_all<<endl;
    unsigned long int frac_part = 1;
    for (unsigned long int j=1; j<=part; j++){
        frac_part *=j;
    }
    //cout <<frac_part<<endl;
    unsigned long int diff = (all -part);
    unsigned long int frac_diff = 1;
    if (diff == 0){
        frac_diff = 1;
    }else {
for (unsigned long int k=1; k<=diff;k++){
    frac_diff *=k;
}
}
    //cout << frac_diff<<endl;
    unsigned long int prob = frac_all/(frac_diff*frac_part);
    cout <<"The probability of guessing"
" all "<<part<<" balls correctly is 1/"<<prob<<endl;
}


int main()
{
    int total = 0;
    int drawn = 0;
   cout << "Enter the total number of lottery balls: ";
   cin >> total;
   //cout << total <<endl;
   cout << "Enter the number of drawn balls: ";
   cin >> drawn;
   //cout << drawn<<endl;
   if(total <= 0 || drawn <= 0){
       cout << "The number of balls must be"
" a positive number."<<endl;
       return 0;
   }
   else if (drawn > total){
       cout << "The maximum number of drawn"
" balls is the total amount of balls."<<endl;
       return 0;
   }

   jackpot(total,drawn);
}
