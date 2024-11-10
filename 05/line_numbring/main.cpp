#include <iostream>
#include <fstream>  // Notice the required library for file handling
#include <string>

using namespace std;

int main() {
   string filename_in = "";
   cout <<"Input file name: ";
   getline(cin,filename_in);
   ifstream my_file;
   my_file.open(filename_in);

   string filename_out = "";
   cout <<"out file name: ";
   getline(cin,filename_out);


   if(my_file.fail()){
       cerr <<"Error opening file"<<endl;
       exit(1);
   }
   else {
           ofstream write_file(filename_out);
           int sum = 0;
           string line;
           while ( getline(my_file, line) ) {
               write_file<<sum<<" "<<line<<endl;
               cout << line<<endl;
               sum ++;
           }
           cout << "line: " << line << endl;
           my_file.close();
           write_file.close();
           cout << "Sum: " << sum << endl;

       }


}
