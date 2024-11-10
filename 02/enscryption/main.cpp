#include <iostream>

using namespace std;

void Check_errors(string &key);
void encryption(string key, string text);

int main()
{
    string key="";
    cout << "Enter the encryption key: ";
    cin >> key;

    string text="";
    cout << "Enter the text to be encrypted: ";
    cin >> text;

    Check_errors(key);
    encryption(key,text);



    return EXIT_SUCCESS;
}


void Check_errors(string &key){

    if(!(key.length()==26)){

        cout << "Error! The encryption key must contain 26 characters."<<endl;
        exit(EXIT_FAILURE);
    }

    for (char c:key){

        if(!(islower(c))){
            cout << "Error! The encryption key must contain only lower case characters."<<endl;
            exit(EXIT_FAILURE);
        }
    }

    for(uint c=97 ; c<=122; c++){
        if(key.find(c)==string::npos){

            cout << "Error! The encryption key must contain all alphabets a-z."<<endl;
            exit(EXIT_FAILURE);
        }
    }

}


void encryption(string key, string text){


    for (char c:text){

        if(!(islower(c))){
            cout << "Error! The encryption key must contain only lower case characters."<<endl;
            exit(EXIT_FAILURE);
        }
    }

    for (uint i=0; i<text.length(); i++){

            char c = text.at(i);
            text.at(i) = key.at(c-97);
        }

    cout << "Encrypted text: "<<text<<endl;


}
