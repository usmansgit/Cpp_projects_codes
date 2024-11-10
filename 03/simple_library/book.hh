#ifndef BOOK_HH
#define BOOK_HH

#include "date.hh"
#include <string>

class Book
{
public:
    Book(std::string auther,std::string name);
    void print();

    // Loaning a book
    void loan(Date &date);

    // Renewing a book
    void renew();

    // Returning the book
    void give_back();
private:
    std::string auther_name_;
    std::string book_name_;
    Date loan_date_;
    Date return_date_;
    bool available_;

};

#endif // BOOK_HH
