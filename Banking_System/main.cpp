#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <fstream>
#include "AccountHolder.h"
#include "Finance.h"
#include "General.h"


void createFile(){

}


int main()
{
    Finance interact;
    General start;

    int choice{0};
    int cnt{-1};


    std::cout << "Welcome to A.N Bank" << std::endl;
    std::cout << "How can we help you today?" << std::endl;

    do
    {
        std::cout << "1. Open a new account" << std::endl;
        std::cout << "2. Access an existing account" << std::endl;
        std::cout << "3. View current date and time" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "5. Test" << std::endl;
        std::cin >> choice;
        std::cin.ignore();

        switch(choice)
        {
        case 1:
        {
            cnt++;
            long int accountNum = start.getRandom(100000000, 999999999);
            std::string fullNameVar = start.getAccountHolderName();
            int pin = start.getRandom(1234, 9999);
            long double openingBalance = start.getInitialAmt();
            long double salaryVal = start.getSalaryVal();
            interact.newAccount(accountNum, fullNameVar, pin, openingBalance, salaryVal);
            system("clear");
            std::cout << "Your pin code is " << interact.getPin()[cnt] << std::endl;
            std::cout << "Keep it concealed at all times!!!" << std::endl;
        }
        break;

        case 2:
            if(cnt == -1)
            {
                std::cout << "No accounts created...create an account first!" << std::endl;
                break;
            }
            interact.authorization(interact.getPin());
            break;

        case 3:
            start.dateAndTime();
            break;
        case 4:
        std::cout << "Hope to see you again soon. Goodbye!" << std::endl;
        exit(4);
        break;

        case 5:

        break();

        default:
            system("clear");
            std::cout << "Invalid entry :(" << std::endl;
        }

    }
    while(choice != 4);

    return 0;
}
