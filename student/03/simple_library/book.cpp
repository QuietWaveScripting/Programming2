#include "book.hh"
#include <iostream>

Book::Book(const std::string &author, const std::string &title):
    auth_(author),
    title_(title)
{

}

void Book::loan(const Date &load_date)
{
    //check if book can be loaned
    if(!loanable_){
       std::cout << "Already loaned: cannot be loaned" << std::endl;
       return;
    }

    loanDate_ = load_date;
    dueDate_ = loanDate_;
    dueDate_.advance(28);
    loanable_ = false;



}

void Book::renew()
{
    //is book loaned?
    if(loanable_){
        std::cout << "Not loaned: cannot be renewed" << std::endl;
        return;
    }
    dueDate_.advance(28);

}

void Book::print()
{
    std::cout << auth_ << " : " << title_ << std::endl;

    if(loanable_){
        std::cout << "- available" << std::endl;
        return;
    }
    else {
        std::cout << "- loaned: ";
        loanDate_.print();
        std::cout << "- to be returned: ";
        dueDate_.print();
    }

}

void Book::give_back()
{
    loanable_ = true;

}
