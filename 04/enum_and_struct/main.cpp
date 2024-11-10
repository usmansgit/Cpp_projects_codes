#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum PostalAbbreviation {AL, AK, AZ, AR, CA, CO, ERROR_CODE};  // Excluded the rest 44 elements

// Version 1: First idea
/*PostalAbbreviation name_to_abbreviation(const std::string& name)
{
    if(name == "Alabama"){
        return AL;
    } else if (name == "Alaska"){
        return AK;
    } else if (name == "Arizona"){
        return AZ;
    } else if (name == "Arkansas"){
        return AR;
    } else if (name == "California"){
        return CA;
    } else if (name == "Colorado"){
        return CO;
    } else {   // Excluded 44 "else if" blocks
        return ERROR_CODE;
    }
}*/

//version 2

struct StateInfo{
    string name;
    PostalAbbreviation abbreviation;
};

const vector<StateInfo> STATES ={
    { "Alabama", AL },
        { "Alaska", AK },
        { "Arizona", AZ },
        { "Arkansas", AR },
        { "California", CA },
        { "Colorado", CO }
};

PostalAbbreviation name_to_abbreviation(const string& name){

    for (auto s:STATES){
        if(name == s.name){
            return s.abbreviation;
        }
    }
    return ERROR_CODE;
}



int main(){

    cout << name_to_abbreviation("Colorado") <<endl;
    return 0;
}
