/* COMP.CS.110 Project 2: GIGS
 * ===========================
 * EXAMPLE SOLUTION
 * ===========================
 *
 *  Acts as a simple gig calendar with n commands:
 * ARTISTS - Prints all known artist names
 * ARTIST <artist name> - Prints single artist's gigs
 * STAGES - Prints all known stage names and their locations
 * STAGE <stage name> - Prints all artists having a gig at the given stage
 * ADD_ARTIST <artist name> - Adds a new artist
 * ADD_GIG <artist name> <date> <town name> <stage name> - Adds a new gig for
 * an artist with the given date, town, and stage (the artist can't already
 * have a gig on the same date and there can't be other gigs at the same stage
 * at the same time)
 * CANCEL <artist name> <date> - Cancels artist's gigs after the given date
 *
 *  The data file's lines should be in format
 * artist_name;date;town_name;stage_name.
 * Otherwise the program execution terminates instantly (but still gracefully).
 *
 * */
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

using DMAP = std::multimap<std::string,std::vector<std::string>>;
using STAGES_MAP = std::multimap<std::string,std::string>;

// Farthest year for which gigs can be allocated
const std::string FARTHEST_POSSIBLE_YEAR = "2030";

// Casual split func, if delim char is between "'s, ignores it.
std::vector<std::string> split(const std::string& str, char delim = ';')
{
    std::vector<std::string> result = {""};
    bool inside_quotation = false;
    for ( char current_char : str )
    {
        if ( current_char == '"' )
        {
            inside_quotation = not inside_quotation;
        }
        else if ( current_char == delim and not inside_quotation )
        {
            result.push_back("");
        }
        else
        {
            result.back().push_back(current_char);
        }
    }
    if ( result.back() == "" )
    {
        result.pop_back();
    }

    return result;
}

// Checks if the given date_str is a valid date, i.e. if it has the format
// dd-mm-yyyy and if it is also otherwise possible date.
bool is_valid_date(const std::string& date_str)
{
    std::vector<std::string> date_vec = split(date_str, '-');
    if ( date_vec.size() != 3 )
    {
        return false;
    }

    std::string year = date_vec.at(0);
    std::string month = date_vec.at(1);
    std::string day = date_vec.at(2);
    std::vector<std::string> month_sizes
            = { "31", "28", "31", "30", "31", "30",
                "31", "31", "30", "31", "30", "31" };

    if ( month < "01" or month > "12" )
    {
        return false;
    }
    if ( year < "0001" or year > FARTHEST_POSSIBLE_YEAR )
    {
        return false;
    }
    unsigned int year_int = stoi(year);
    bool is_leap_year = (year_int % 400 == 0) or
                        (year_int % 100 != 0 and year_int % 4 == 0);
    if ( day >= "01" and
        (day <= month_sizes.at(stoi(month) - 1) or
        (month == "02" and is_leap_year and day <= "29")) )
    {
        return true;
    }
    else
    {
        return false;
    }
}

int read_write(std::ifstream &file,DMAP &gig){
    std::string line;
    std::vector<std::string> data;
    while(std::getline(file, line)){

         data = split(line);
         if (data.size() != 4){
             std::cout << "formattion error"<<std::endl;
             return EXIT_FAILURE;
             }

         gig.insert({data.at(0),{data.at(1),data.at(2),data.at(3)}});

    }
       /* DMAP::iterator it;
    for (it = gig.begin(); it != gig.end(); ++it)
        {
           std::cout << (*it).first<<"  "<< (*it).second.at(0)
                     <<"  "<< (*it).second.at(1)
                    <<"  "<< (*it).second.at(2)<< std::endl;
        }*/

    return 1;
}

void artists(DMAP & gig){
    DMAP::iterator it;
    std::list<std::string> artists;
    std::cout << "All artists in alphabetical order: "<<std::endl;
 for (it = gig.begin(); it != gig.end(); ++it)
     {
        if(std::find(artists.begin(), artists.end(), (*it).first) == artists.end()){
            artists.push_back((*it).first);
            std::cout << (*it).first<< std::endl;
        }
     }

}

void one_artist(DMAP &gig, const std::string & artist_name){
    std::cout << "Artist Elastinen has the following gigs in"
                 " the order they are listed:"<<std::endl;
    std::string key = artist_name;
        for (auto itr = gig.begin(); itr != gig.end(); itr++){
            if (itr -> first == key){
                std::cout << itr -> first << "  "
                     << itr -> second.at(0) << std::endl;
            }
        }
}

void stages_order(DMAP & gig){
    STAGES_MAP stages;
     DMAP::iterator it;
 for (it = gig.begin(); it != gig.end(); ++it)
     {

        /*std::cout << (*it).second.at(1)
                 <<",  "<< (*it).second.at(2)<< std::endl;*/
        stages.insert({(*it).second.at(1),(*it).second.at(2)});
     }

    STAGES_MAP::iterator itr;
    std::cout<<"All gig places in alphabetical order:"<<std::endl;
 for (itr = stages.begin(); itr != stages.end(); ++itr)
     {

     std::cout << (*itr).first<<",  "<< (*itr).second<< std::endl;

     }
}

void artist_at_stage(DMAP &gig,std::string &stage_name){

    std::string key = stage_name;
        for (auto itr = gig.begin(); itr != gig.end(); itr++){
            if (itr -> second.at(2) == key){
                std::cout << itr -> first << "  "<< std::endl;
            }
        }
}


int main()
{
    DMAP gig;
    //Opening the File
    std::string filename = "input.txt";
    //std::cout << "Give a name for input file: ";
    //std::getline(std::cin,filename);

    std::ifstream file(filename);
    if(!file){
        std::cout << "Error: File could not be read." << std::endl;
        return EXIT_FAILURE;
    }

    //reading file and writing to data structure
    read_write(file,gig);

    while(true){
        std::string line;
            std::cout << "gigs> ";
            getline(std::cin, line);
            std::vector<std::string> parts = split(line,' ');
            if(parts.size() == 0)
                    {
                        continue;
                    }
            std::string command =parts.at(0);
            if(command == "ARTISTS" || command == "artists"){

                //printing artists names
                artists(gig);
            }
            else if(command == "STAGES" || command == "stages"){

                //stages in order
                stages_order(gig);
            }
            else if(command == "ARTIST" || command == "artist"){
                if(parts.size()!= 2){
                    std::cout<<"Error: Invalid input."<<std::endl;
                    continue;
                }

                //printing one artist gigs
                one_artist(gig,parts.at(1));
            }
            else if(command == "STAGE" || command == "stage"){
                artist_at_stage(gig,parts.at(1));
            }

            else if(command == "QUIT" || command == "quit"){
                return EXIT_SUCCESS;
            }

            //std::cout<<parts.at(0)<<std::endl;

 }

}

    //printing artists names
    //artists(gig);

    //printing one artist gigs
    //std::string artist_name;
    //std::cout << "Give artist name: ";
    //std::getline(std::cin,artist_name);
    //one_artist(gig,artist_name);

    //stages in order
    //stages_order(gig);

    //gigs at a stage printing artist names haveing gigs at that stage
    //std::string stage_name;
    //std::cout << "Give stage name: ";
    //std::getline(std::cin,stage_name);
    //artist_at_stage(gig,stage_name);

    //return EXIT_SUCCESS;


