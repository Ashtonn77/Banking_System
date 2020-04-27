#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include "AccountHolder.h"
#include "Finance.h"

//random function
long int getRandom(long int minNum, long int maxNum){
    srand(time(nullptr));
    return minNum + (rand() % maxNum);
}

//account number
std::string getAccountHolderName(){
    std::cout << "Enter full name...don't forget the space between each name__" << std::endl;
    std::string fName;
    std::getline(std::cin, fName);
    //std::cin.ignore();
    return fName;
}

//salary details
long double getSalaryVal(){
    long double sal{0.0};
    int choice{0};
    std::cout << "Choose salary option: " << std::endl;
    std::cout << "1. Weekly" << std::endl;
    std::cout << "2. Fortnightly" << std::endl;
    std::cout << "3. Monthly" << std::endl;
    std::cin >> choice;
    std::cin.ignore();
    switch(choice){
        case 1 :
        std::cout << "Please enter your total weekly earnings" << std::endl;
        std::cin >> sal;
        std::cin.ignore();
        break;

        case 2 :
        std::cout << "Please enter your total fortnightly earnings" << std::endl;
        std::cin >> sal;
        std::cin.ignore();
        break;

        case 3 :
        std::cout << "Please enter your total monthly earnings" << std::endl;
        std::cin >> sal;
        std::cin.ignore();
        break;

        default:
        std::cout << "Invalid entry" << std::endl;
    }
    return sal;
}

//starting deposit
long double getInitialAmt(){
    std::cout << "How much will your initial deposit be? ";
    long double amt;
    std::cin >> amt;
    std::cin.ignore();
    return amt;
}

int main()
{
    Finance interact;

    int choice{0};

            do{
            std::cout << "Make choice___" << std::endl;
            std::cout << "1. New Account" << std::endl;
            std::cout << "2. Existing Account" << std::endl;
            std::cout << "3. Test" << std::endl;
            std::cin >> choice;
            std::cin.ignore();

            switch(choice){
                case 1:
                {
                long int accountNum = getRandom(100000000, 999999999);
                std::string fullNameVar = getAccountHolderName();
                int pin = getRandom(1234, 9999);
                long double openingBalance = getInitialAmt();
                long double salaryVal = getSalaryVal();
                interact.newAccount(accountNum, fullNameVar, pin, openingBalance, salaryVal);
                std::cout << "Your pin code is " << interact.getPin()[0] << std::endl;
                }
                break;

                case 2:
                interact.authorization(interact.getPin()[0]);
                break;

                case 3:
                interact.invest();
                break;

                default:
                std::cout << "<---The End------> ";
            }

            }while(toupper(choice) != 3);

    return 0;
}
