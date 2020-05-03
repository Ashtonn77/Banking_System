#include <iostream>
#include <vector>
#include "General.h"

General::General()
{
    //ctor
}

long int General::getRandom(long int minNum, long int maxNum){
    srand(time(nullptr));
    return minNum + (rand() % maxNum);
}

//account number
std::string General::getAccountHolderName(){
    system("clear");
    std::cout << "Enter full name...don't forget the space between each name__" << std::endl;
    std::string fName;
    std::getline(std::cin, fName);
    return fName;
}

//salary details
long double General::getSalaryVal(){
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
long double General::getInitialAmt(){
    system("clear");
    std::cout << "How much will your initial deposit be? ";
    long double amt;
    std::cin >> amt;
    std::cin.ignore();
    return amt;
}

//withdraw
void General::withdrawFunc(int amnt, std::vector<int> &wDrawVec,
                    std::vector<long double> &tempBal,
                    int i, std::string str){
        tempBal[0] -= amnt;
        wDrawVec[i] = amnt;
        system("clear");
        std::cout << str << " successfull :)" << std::endl;
        displayBalance(tempBal, i);
}

//display balance
void General::displayBalance(std::vector<long double> tempBal, int i){
    std::cout << "Your current balance is R" << tempBal[i] << std::endl;
}

//transaction prompt
void General::displayTransactionPrompt(std::string trans){
    std::cout << "How much would you like to " << trans << "?" << std::endl;
}
