#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(std::string line,const char sep, bool empty=false){

    std::string text = line;
    std::string word = "";
    std::vector<std::string> words;

    while(text.find(sep) != std::string::npos){
        word = text.substr(0,text.find(sep));

    }


}
// TODO: Implement split function here
// Do not change main function


int main()
{
    std::string line = "";
    std::cout << "Enter a string: ";
    getline(std::cin, line);
    std::cout << "Enter the separator character: ";
    char separator = getchar();

    std::vector< std::string > parts  = split(line, separator);
    std::cout << "Splitted string including empty parts: " << std::endl;
    for( auto part : parts ) {
        std::cout << part << std::endl;
    }

    std::vector< std::string > parts_no_empty  = split(line, separator, true);
    std::cout << "Splitted string ignoring empty parts: " << std::endl;
    for( auto part : parts_no_empty ) {
        std::cout << part << std::endl;
    }
}
