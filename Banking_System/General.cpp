#include <iostream>
#include <vector>
#include "General.h"

General::General()
{
    //ctor
}

void General::displayInvalidInput(std::string x){
    std::cout << "Invalid...please use " << x << " only" << std::endl;
    std::cin.clear();
}

bool gotDigit(std::string str){

    for(auto character:str){
        if(isdigit(character)) return true;
    }
    return false;
}

long int General::getRandom(long int minNum, long int maxNum)
{
    srand(time(nullptr));
    return minNum + (rand() % maxNum);
}

//account number
std::string General::getAccountHolderName()
{
    system("clear");
    std::string fName;

    while(true){
    std::cout << "Enter full name...don't forget the space between each name__" << std::endl;
    std::getline(std::cin, fName);

    if(gotDigit(fName)) displayInvalidInput("letters");
    else break;
    }

    return fName;
}

//salary details
long double General::getSalaryVal()
{
    long double sal{0.0};
    int choice{0};
    system("clear");
    std::cout << "Choose salary option: " << std::endl;
    std::cout << "1. Weekly" << std::endl;
    std::cout << "2. Fortnightly" << std::endl;
    std::cout << "3. Monthly" << std::endl;
    std::cin >> choice;
    std::cin.ignore();
    switch(choice)
    {
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
long double General::getInitialAmt()
{
    system("clear");

    long double amt;

    //check input for digits only
    while(true){
    std::cout << "How much will your initial deposit be? ";
    std::cin >> amt;
    if(std::cin.good()) break;
    else{
        displayInvalidInput("numbers");
        std::cin.clear();
        std::cin.ignore(100000, '\n');

    }

    }
    std::cin.ignore();
     return amt;
}
//withdraw
void General::withdrawFunc(int amnt, std::vector<int> &wDrawVec,
                           std::vector<long double> &tempBal,
                           int i, std::string str)
{
    tempBal[0] -= amnt;
    wDrawVec[i] = amnt;
    system("clear");
    std::cout << str << " successfull :)" << std::endl;
    displayBalance(tempBal, i);
}

//display balance
void General::displayBalance(std::vector<long double> tempBal, int i)
{
    std::cout << "Your current balance is R" << tempBal[i] << std::endl;
}

//transaction prompt
void General::displayTransactionPrompt(std::string trans)
{
    std::cout << "How much would you like to " << trans << "?" << std::endl;
}

//insufficient funds
void General::insufficientFunds()
{
    std::cout << "Sorry, you seem to have insuffecient funds in your account to proceed" << std::endl;
    std::cout << "Would you like to make a deposit? (y/n)  ";
}

int General::dateAndTime(){
    system("clear");
    time_t now = time(0);
    // Convert now to tm struct for local timezone
    tm* localtm = localtime(&now);
    std::cout << "The local date and time is: " << asctime(localtm) << std::endl;
    // Convert now to tm struct for UTC
    tm* gmtm = gmtime(&now);
    if (gmtm != NULL) {
    std::cout << "The UTC date and time is: " << asctime(gmtm) << std::endl;
    }
    else {
    std::cerr << "Failed to get the UTC date and time" << std::endl;
    return EXIT_FAILURE;
}
}
