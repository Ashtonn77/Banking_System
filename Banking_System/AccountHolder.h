#ifndef ACCOUNTHOLDER_H
#define ACCOUNTHOLDER_H
#include <iostream>
#include <vector>

class AccountHolder
{
    friend class Finance;
public:
    AccountHolder();
    void newAccount(long int accNum, std::string fName,
                    int pin, long double openingAmt, long double sal);
    std::vector<long int> getAccNum();
    std::vector<std::string> getFullName();
    std::vector<int> getPin();
    std::vector<long double> getBalance();
    std::vector<long double> getSalary();
    int searchIndex{-1};
    std::vector<int> recentWithdrawals{0};
    std::vector<int> recentDeposits{0};


private:
    std::vector<long int> accountNumber;
    std::vector<std::string> fullName;
    std::vector<int> pinCode;
    std::vector<long double> balance;
    std::vector<long double> salary;

};

#endif // ACCOUNTHOLDER_H
