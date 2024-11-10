#include "book.hh"

Book::Book()
{

}

Book::~Book()
{
    //deallocate memory
    for(std::pair<std::string, Chapter*> ch : chapters_){

        delete ch.second;
    }
}

void Book::addNewChapter(const std::string &id, const std::string &fullName, int length)
{
    //check if the chapter already exists
    if(chapters_.find(id) != chapters_.end())

        // print erroe if required
        return;

    //add new chapeter
    // allocate memory
    //Chapter *new_chapter = new Chapter{(id, fullName, length)};
    Chapter *new_chapter = new Chapter;
    new_chapter->id_ = id;
    new_chapter->fullName_ = fullName;
    new_chapter->length_ = length;

    //add to data structure
    chapters_.insert({new_chapter->id_
                     , new_chapter});

   /* Data::const_iterator iter;
     for(auto iter : chapters_){

         std::cout << iter.second->id_ << std::endl;
     }*/


}

void Book::addRelation(const std::string &subchapter, const std::string &parentChapter)
{
    //check if the chapters exixst
    if(chapters_.find(subchapter) == chapters_.end()
       || chapters_.find(parentChapter) == chapters_.end())

        return;
    //fetch the parent and subchapter pointers
    Chapter *sub_ptr = chapters_.at(subchapter);
    Chapter *parent_ptr = chapters_.at(parentChapter);
    //std::cout <<"this is parent pointer >--" <<parent_ptr->id_ << std::endl;
    //std::cout <<"this is subpointer    -->" <<sub_ptr->id_ << std::endl;

    // add subchapter to parent
    parent_ptr->subchapters_.push_back(sub_ptr);
    sub_ptr->parentChapter_ = parent_ptr;


   /*Data::const_iterator iter;
    for(auto iter : chapters_){

        std::cout << iter.first << std::endl;
    }*/

}

void Book::printIds(Params params) const
{

}

void Book::printContents(Params params) const
{
    //in order to avoid repetative prints
    //find the topmost chapters first
    std::vector<Chapter*> topmost = {};

    for(std::pair<std::string, Chapter*> ch : chapters_){

        // topmost doesnt have parent chapter
        if(ch.second->parentChapter_ == nullptr){

            topmost.push_back(ch.second);
        }
    }

    int counter = 1;
    for(Chapter *ch : topmost){
                //std::cout << ch->fullName_<< "           This is topmost hello i m here"<<std::endl;
                printChapterRecursively(ch,"",counter++);
            }

}

void Book::close(Params params) const
{

}

void Book::open(Params params) const
{

}

void Book::openAll(Params params) const
{

}

void Book::printParentsN(Params params) const
{

}

void Book::printSubchaptersN(Params params) const
{

}

void Book::printSiblingChapters(Params params) const
{

}

void Book::printTotalLength(Params params) const
{

}

void Book::printLongestInHierarchy(Params params) const
{

}

void Book::printShortestInHierarchy(Params params) const
{

}

void Book::printParent(Params params) const
{

}

void Book::printSubchapters(Params params) const
{

}

Chapter *Book::findChapter(const std::string &id) const
{
    Chapter *chapter_ptr = nullptr;
    //check if chapter in book
    Data::const_iterator iter = chapters_.find(id);
    if(iter != chapters_.end()){

        chapter_ptr = chapters_.at(id);
    }
    return chapter_ptr;
}

void Book::printGroup(const std::string &id, const std::string &group, const IdSet &container) const
{

}

IdSet Book::vectorToIdSet(const std::vector<Chapter *> &container) const
{
    IdSet idSet = {};
    for(const Chapter *p : container){

        idSet.insert(p->id_);

    }
    return idSet;
}

void Book::printChapterRecursively(const Chapter *ptr, const std::string &indents,
                                            int index) const
{
    //head recursive
    //print out current chapter and sign if open or not

    char sign = ptr->isOpen_ ? '-' : '+';
    std::cout << sign << indents << index << ". "
              << ptr->fullName_ << " (" << ptr->length_ <<") "
              << std::endl;

    // chapter is open
    if(ptr ->isOpen_){
        int counter = 1;
        for (Chapter *ch : ptr->subchapters_) {

            printChapterRecursively(ch,indents + "  ", counter++);
        }
    }


}
