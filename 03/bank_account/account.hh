#ifndef ACCOUNT_HH
#define ACCOUNT_HH

#include <string>

class Account
{
public:
    // Constructor
    Account(const std::string& owner, bool has_credit = false);

    void set_credit_limit(int limit);
    void save_money(int amount);
    void take_money(int withdraw);
    void transfer_to(Account &account, int transfer_money);
    void print() const;

    // More methods

private:
    // Generates IBAN (based on running_number_ below).
    // Allows no more than 99 accounts.
    void generate_iban();

    // Used for generating IBAN.
    // Static keyword means that the value of running_number_ is the same for
    // all Account objects.
    // In other words, running_number_ is a class-wide attribute, there is
    // no own copies of it for each object of the class.
    static int running_number_;

    // More attributes/methods
    std::string iban_;
    std::string owner_;
    bool has_credit_;
    int balance_;
    int credit_limit_;
};

#endif // ACCOUNT_HH
