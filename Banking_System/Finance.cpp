#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include "AccountHolder.h"
#include "Finance.h"
#include "General.h"

Finance::Finance() {}
General go;
//make deposit
void Finance::depositFunds()
{
    double funds{0.0};
    system("clear");

    //check input
    while(true){
    go.displayTransactionPrompt("deposit");
    std::cin >> funds;

     if(std::cin.good()) break;
     else{
        system("clear");
        go.displayInvalidInput("numbers");
        std::cin.clear();
        std::cin.ignore(100000, '\n');
    }

    }

    std::cin.ignore();
    balance[searchIndex] += funds;
    recentDeposits[searchIndex] = funds;
    system("clear");
    std::cout << "Your deposit was a success" << std::endl;
    go.displayBalance(balance, searchIndex);
}
//end deposit

//make withdrawal
void Finance::withdrawFunds()
{


    double withdrawAmnt{0};
    char choice{};
    system("clear");

     while(true){
     go.displayTransactionPrompt("withdraw");
     std::cin >> withdrawAmnt;

     if(std::cin.good()) break;
     else{
        system("clear");
        go.displayInvalidInput("numbers");
        std::cin.clear();
        std::cin.ignore(100000, '\n');
    }
    }

    std::cin.ignore();
    if(withdrawAmnt < balance[searchIndex])
    {
        go.withdrawFunc(withdrawAmnt, recentWithdrawals, balance, searchIndex, "Withdrawal");

    }
    else
    {
        system("clear");
        go.insufficientFunds();
        std::cin >> choice;
        std::cin.ignore();
        if(toupper(choice) == 'Y')
        {
            depositFunds();
        }
        else
        {
            system("clear");
            std::cout << "back to menu." << std::endl;
        }

    }

}
//end withdrawal

//loan function ***improve ** make loan amount higher
void Finance::tempLoan()
{
    long double salaryVal  {salary[searchIndex]};
    long double currentBalance {balance[searchIndex]};
    const double interestRate {0.08};
    long double loanAmnt {0.0};
    char choice{};
    currentBalance > salaryVal ? loanAmnt = salaryVal + (salaryVal * 0.15) :
                                            loanAmnt = salaryVal - (salaryVal * 0.15);

    double monthlyInstallment = (loanAmnt + (loanAmnt * interestRate)) / 24;

    system("clear");
    std::cout << "Based on your salary and current balance," << std::endl;
    std::cout << " we can offer you a temporay loan of R" << loanAmnt << ",";
    std::cout << " payable over a span of 24 months" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "We offer a fixed interest rate of " << interestRate * 100 << "%" << std::endl;
    std::cout << "Your monthly installments will be R" << monthlyInstallment
              << " payable at the end of every month" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Accept loan deal and proceed? (y/n)  ";
    std::cin >> choice;
    std::cin.ignore();

    if(toupper(choice) == 'Y')
    {
        balance[searchIndex] += loanAmnt;
        system("clear");
        std::cout << "Loan approved..." << std::endl;
        go.displayBalance(balance, searchIndex);
    }
    else
    {
        system("clear");
        std::cout << "Sorry we couldn't come to an agreement :(" << std::endl;
    }
}


//invest choice
void Finance::investChoice(long double initiallInvestment)
{
    char choice{};
    //system("clear");
    std::cout << "Would you like to go ahead with the investment? (y/n)  ";
    std::cin >> choice;
    std::cin.ignore();

    //check if user wants to invest
    if(toupper(choice) == 'Y')
    {

        //check if user has enough in balance
        if(initiallInvestment < balance[searchIndex])
        {
            balance[searchIndex] -= initiallInvestment;

            system("clear");
            std::cout << "Transaction successfull :) Thank you for investing your money with us. " << std::endl;
            go.displayBalance(balance, searchIndex);
        }
        else
        {
            system("clear");
            go.insufficientFunds();
            char makeDeposit{};
            std::cin >> makeDeposit;
            std::cin.ignore();
            if(toupper(makeDeposit) == 'Y')
            {
                depositFunds();
            }
            else
            {
                system("clear");
                std::cout << "Sorry we couldn\'t come to an agreement" << std::endl;
            }

        }//end check if user has enough in balance

    }
    else
    {
        system("clear");
        std::cout << "Sorry we couldn\'t help you today. Goodbye" << std::endl;
    }//end check if user wants to invest



}


//invest display
void Finance::investOptionDisplay(int minInvestYears, long double initiallInvestment,
                                  int percentage, std::string investmentPlan)
{


    std::cout << "The " << investmentPlan
              << " requires an initial investment of R" << initiallInvestment << "." << std::endl;
    std::cout << "You won't be allowed to touch your funds for a minimum of "
              << minInvestYears << " years.";
    std::cout << " The investment will gain you an increase of " << percentage << "% per month" <<
              " depending on the state of your investment account, balance and frequency of interaction." << std::endl;
    std::cout << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << std::endl;
    investChoice(initiallInvestment);
}

//invest
void Finance::invest()
{
    int option{0};
    do
    {
        std::cout << "We offer a number of investment options";
        std::cout << "...choose option to learn more" << std::endl;
        std::cout << "1. Silver Investment Path" << std::endl;
        std::cout << "2. Gold Investment Path" << std::endl;
        std::cout << "3. Platinum Investment Path" << std::endl;
        std::cout << "4. Back to main screen" << std::endl;
        std::cin >> option;
        std::cin.ignore();

        switch(option)
        {
        case 1:
            system("clear");
            investOptionDisplay(2, 10000, 2, "Silver Investment Path");
            break;

        case 2:
            system("clear");
            investOptionDisplay(4, 50000, 5, "Gold Investment Path");
            break;

        case 3:
            system("clear");
            investOptionDisplay(5, 10000, 8, "Platinum Investment Path");
            break;

        default:
            std::cout << "" << std::endl;
        }

    }
    while(option != 4);
}
//end invest


//transfer
void Finance::moneyTransfer()
{
    system("clear");
    int transferTo{0};


     while(true){
        std::cout << "Enter the account number you'd like to transfer funds to" << std::endl;
        std::cin >> transferTo;
         if(std::cin.good()) break;
         else{
            system("clear");
            go.displayInvalidInput("numbers");
            std::cin.clear();
            std::cin.ignore(100000, '\n');
        }

    }

    std::cin.ignore();
    int cnt{0};
    int amnt{0};

    for(int i = 0; i < accountNumber.size(); i++)
    {
        if(transferTo == accountNumber[i])
        {
            cnt = i;
            go.displayTransactionPrompt("transfer");
            std::cin >> amnt;
            std::cin.ignore();
            if(amnt > balance[searchIndex])
            {

                system("clear");
                go.insufficientFunds();
                char makeDeposit{};
                std::cin >> makeDeposit;
                std::cin.ignore();
                if(toupper(makeDeposit) == 'Y')
                {
                    depositFunds();
                }
                else
                {
                    system("clear");
                    std::cout << "Sorry we couldn\'t come to an agreement" << std::endl;
                }

            }
            else
            {
                balance[searchIndex] -= amnt;
                balance[cnt] += amnt;
                system("clear");
                std::cout << "Transfer complete" << std::endl;
                std::cout << "You just transfered R" << amnt << " to " << fullName[cnt] << std::endl;
                go.displayBalance(balance, searchIndex);
            }//end check balance

        }
        else
            cnt++;
    }
    if(cnt == accountNumber.size())
    {
        system("clear");
        std::cout << "Sorry account number not found :( Please enter a another account number" << std::endl;
    }

}
//end transfer

//transaction screen
void Finance::transactions()
{
    int choice{0};
    system("clear");
    std::cout << "Welcome " << getFullName()[searchIndex] << ". Choose one of the options below"<< std::endl;
    do
    {

        std::cout << std::endl;
        std::cout << "1. Make a deposit" << std::endl;
        std::cout << "2. Make a withdrawal" << std::endl;
        std::cout << "3. Take a temporary loan" << std::endl;
        std::cout << "4. Check balance" << std::endl;
        std::cout << "5. Invest your money" << std::endl;
        std::cout << "6. Transer money to another account" << std::endl;
        std::cout << "7. Print statement" << std::endl;
        std::cout << "8. View details" << std::endl;
        std::cout << "0. Back" << std::endl;

        std::cin >> choice;
        std::cin.ignore();

        switch(choice)
        {
        case 1:
            depositFunds();
            break;

        case 2:
            withdrawFunds();
            break;

        case 3:
            tempLoan();
            break;

        case 4:
            system("clear");
            go.displayBalance(balance, searchIndex);
            break;

        case 5:
            invest();
            break;

        case 6:
            moneyTransfer();
            break;

        case 7:
            std::cout << "Sorry...this feature is currently disabled :(" << std::endl;
            break;

        case 8:
            system("clear");
            std::cout << "Account holder      ------> " << getFullName()[searchIndex] << std::endl;
            std::cout << "Account number      ------> " << getAccNum()[searchIndex] << std::endl;
            std::cout << "Account holder pin  ------> " << getPin()[searchIndex] << std::endl;
            std::cout << "Salary              ------> R" << getSalary()[searchIndex] << std::endl;
            std::cout << "Account balance     ------> R" << getBalance()[searchIndex] << std::endl;
            std::cout << "Recent withdrawals  ------> R" << recentWithdrawals[searchIndex] << std::endl;
            std::cout << "Recent deposits     ------> R" << recentDeposits[searchIndex] << std::endl;
            break;

        case 9:
            break;

        default:
            system("clear");
            std::cout << "" << std::endl;
        }

    }
    while(choice != 0);

}

//to access existing account
void Finance::authorization(std::vector<int> pin)
{
    int input{0};
    int cnt{0};
    system("clear");
    std::cout << "Please enter your pin code to access account__ ";
    std::cin >> input;
    std::cin.ignore();

    for(int i = 0; i < pin.size(); i++)
    {
        if(input == pin[i])
        {
            searchIndex = i;
            transactions();
            break;
        }
        cnt++;
    }
    if(cnt == pin.size())
    {
        system("clear");
        std::cout << "Incorrect pin" << std::endl;
    }

}

