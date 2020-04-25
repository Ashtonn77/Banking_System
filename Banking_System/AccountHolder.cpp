#include <iostream>
#include <vector>
#include "AccountHolder.h"
#include "Finance.h"

AccountHolder::AccountHolder()
{

}

void AccountHolder::newAccount(long int accNum, std::string fName,
                               int pin, long double openingAmt, long double sal)
{
    accountNumber.push_back(accNum);
    fullName.push_back(fName);
    pinCode.push_back(pin);
    balance.push_back(openingAmt);
    salary.push_back(sal);
}

std::vector<long int> AccountHolder::getAccNum()
{
    return accountNumber;
}

std::vector<std::string> AccountHolder::getFullName()
{
    return fullName;
}

std::vector<int> AccountHolder::getPin()
{
    return pinCode;
}

std::vector<long double> AccountHolder::getBalance()
{
    return balance;
}

std::vector<long double> AccountHolder::getSalary()
{
    return salary;
}


