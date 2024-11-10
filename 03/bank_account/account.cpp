#include "account.hh"
#include <iostream>

Account::Account(const std::string& owner, bool has_credit):
    iban_(""),
    owner_(owner),
    has_credit_(has_credit),
    balance_(0),
    credit_limit_(0)
{
    generate_iban();
}

void Account::set_credit_limit(int limit)
{
    credit_limit_ = limit;

}

void Account::save_money(int amount)
{
    balance_ += amount;

}

void Account::take_money(int withdraw)
{
    balance_ -= withdraw;

}

void Account::transfer_to(Account &account, int transfer_money)
{
    account.save_money(transfer_money);
    take_money(transfer_money);

}

void Account::print() const
{
    std::cout << owner_ << " : "
        << iban_ << " : " <<balance_<< " euros"<<std::endl;

}

// Setting initial value for the static attribute running_number_
int Account::running_number_ = 0;

void Account::generate_iban()
{
    ++running_number_;
    std::string suffix = "";
    if(running_number_ < 10)
    {
        suffix.append("0");
    }
    else if(running_number_ > 99)
    {
        std::cout << "Too many accounts" << std::endl;
    }
    suffix.append(std::to_string(running_number_));

    iban_ = "FI00 1234 ";
    iban_.append(suffix);
}
