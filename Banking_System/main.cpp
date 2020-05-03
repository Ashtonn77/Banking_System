#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdio>
#include "AccountHolder.h"
#include "Finance.h"

//random function
long int getRandom(long int minNum, long int maxNum){
    srand(time(nullptr));
    return minNum + (rand() % maxNum);
}

//account number
std::string getAccountHolderName(){
    system("clear");
    std::cout << "Enter full name...don't forget the space between each name__" << std::endl;
    std::string fName;
    std::getline(std::cin, fName);
    return fName;
}

//salary details
long double getSalaryVal(){
    long double sal{0.0};
    int choice{0};
    system("clear");
    std::cout << "Choose salary option: " << std::endl;
    std::cout << "1. Weekly" << std::endl;
    std::cout << "2. Fortnightly" << std::endl;
    std::cout << "3. Monthly" << std::endl;
    std::cin >> choice;
    std::cin.ignore();
    switch(choice){
        case 1 :
        system("clear");
        std::cout << "Please enter your total weekly earnings" << std::endl;
        std::cin >> sal;
        std::cin.ignore();
        break;

        case 2 :
        system("clear");
        std::cout << "Please enter your total fortnightly earnings" << std::endl;
        std::cin >> sal;
        std::cin.ignore();
        break;

        case 3 :
        system("clear");
        std::cout << "Please enter your total monthly earnings" << std::endl;
        std::cin >> sal;
        std::cin.ignore();
        break;

        default:
        system("clear");
        std::cout << "Invalid entry" << std::endl;
    }
    return sal;
}

//starting deposit
long double getInitialAmt(){
    system("clear");
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
    int cnt{-1};

            do{
            std::cout << "Make choice___" << std::endl;
            std::cout << "1. New Account" << std::endl;
            std::cout << "2. Existing Account" << std::endl;
            std::cout << "3. Test" << std::endl;
            std::cout << "4. Exit" << std::endl;
            std::cin >> choice;
            std::cin.ignore();

            switch(choice){
                case 1:
                {
                cnt++;
                long int accountNum = getRandom(100000000, 999999999);
                std::string fullNameVar = getAccountHolderName();
                int pin = getRandom(1234, 9999);
                long double openingBalance = getInitialAmt();
                long double salaryVal = getSalaryVal();
                interact.newAccount(accountNum, fullNameVar, pin, openingBalance, salaryVal);
                system("clear");
                std::cout << "Your pin code is " << interact.getPin()[cnt] << std::endl;
                std::cout << "Keep it concealed at all times!!!" << std::endl;
                }
                break;

                case 2:
                if(cnt == -1){
                std::cout << "No accounts created...create an account first!" << std::endl;
                break;
                }
                interact.authorization(interact.getPin());
                break;

                case 3:
                interact.moneyTransfer();
                break;

                default:
                std::cout << "<---The End------> ";
            }

            }while(choice != 4);

    return 0;
}
