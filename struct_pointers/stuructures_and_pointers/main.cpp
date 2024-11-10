#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

struct Chapter
{
    std::string id ;
    std::string fullName;
    int length = 0;
    Chapter* parentChapter= nullptr;
    std::vector<Chapter*> subchapters;
};

using Data = std::map<std::string, Chapter*>;
Data chapters;

int main()
{
    Chapter *chapter1 = new Chapter;
    Chapter *chapter2 = new Chapter;
    Chapter *chapter3 = new Chapter;
    Chapter *chapter4 = new Chapter;

    chapter1 ->id = "id1";
    chapter1 ->fullName = "introduction";
    chapter1 ->length = 1;
    chapter1->parentChapter = nullptr;

    chapter2 ->id = "id2";
    chapter2 ->fullName = "Basic Definitations";
    chapter2 ->length = 3;

    chapter3 ->id = "id3";
    chapter3 ->fullName = "Already Third Chapter";
    chapter3 ->length = 2;

    chapter4 ->id = "id4";
    chapter4 ->fullName = "summary";
    chapter4 ->length = 2;

    chapters.insert({chapter1->id, chapter1});
    chapters.insert({chapter2->id, chapter2});
    chapters.insert({chapter3->id, chapter3});
    chapters.insert({chapter4->id, chapter4});

    Data::const_iterator iter;
     for(auto iter : chapters){

         std::cout << iter.second->fullName << std::endl;
     }

    //Chapter *sub_ptr2 = chapter2;
    //Chapter *sub_ptr3 = chapter3;
    //Chapter *parent_ptr = chapter1;

    /*Chapter *sub_ptr2 = chapters.at(chapter2->id);
    Chapter *sub_ptr3 = chapters.at(chapter3->id);
    Chapter *parent_ptr = chapters.at(chapter1->id);
    parent_ptr->subchapters.push_back(sub_ptr2);
    parent_ptr->subchapters.push_back(sub_ptr3);
    sub_ptr2->parentChapter = parent_ptr;
    sub_ptr3->parentChapter = parent_ptr;




     for(auto iter : chapters){

         std::cout << iter.second->id << std::endl;
     }*/






}

