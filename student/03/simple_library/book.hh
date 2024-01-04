#ifndef BOOK_HH
#define BOOK_HH

#include "date.hh"
#include <string>

class Book
{
public:
    Book(std::string const &author, std::string const &title);
    void loan(Date const &load_date);
    void renew();
    void print();
    void give_back();



private:
    std:: string auth_;
    std:: string title_;
    Date loanDate_ = Date();
    Date dueDate_ = Date();
    bool loanable_ = true;

};

#endif // BOOK_HH
