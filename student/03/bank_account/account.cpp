#include "account.hh"
#include <iostream>

// Define static member variable
int Account::running_number_ = 0;

Account::Account(const std::string& owner, bool has_credit)
{
    owner_ = owner;
    has_credit_ = has_credit;
    generate_iban();
}

void Account::generate_iban()
{
    ++running_number_;

    std::string suffix = "";

    if(running_number_ < 10)
        suffix.append("0");

    suffix.append(std::to_string(running_number_));

    iban_ = "FI00 1234 ";

    iban_.append(suffix);
}

void Account::save_money(int amount)
{
    balance_ += amount;
}

bool Account::take_money(int amount)
{
   if (amount > balance_)
   {
       if (has_credit_)
       {
           if (amount - balance_ > credit_limit_)
           {
               std::cout << "Cannot take money: credit limit overflow" << std::endl;
               return false;
           }
           else
           {
               balance_ -= amount;
               std::cout << amount << " euros taken: new balance of " << iban_ << " is " << balance_ << " euros" << std::endl;
               return true;
           }
       }
       else
       {
           std::cout << "Cannot take money: balance underflow" << std::endl;
           return false;
       }
   }
   else
   {
       balance_ -= amount;
       std::cout << amount << " euros taken: new balance of " << iban_ << " is " << balance_ << " euros" << std::endl;
       return true;
   }
}

bool Account::transfer_to(Account& other_account, int amount)
{
   if (take_money(amount))
   {
       other_account.save_money(amount);
       return true;
   }
   else
   {
       std::cout << "Transfer from " << iban_ << " failed" << std::endl;
       return false;
   }
}

void Account::set_credit_limit(int limit)
{
   if (has_credit_)
       credit_limit_ = limit;
   else
       std::cout << "Cannot set credit limit: the account has no credit card" << std::endl;
}

void Account::print() const
{
   std::cout << owner_ << " : " << iban_ << " : ";

   if (balance_ < 0)
       std::cout << balance_ << " euros" << std::endl;
   else
       std::cout << balance_ << " euros" << std::endl;
}
