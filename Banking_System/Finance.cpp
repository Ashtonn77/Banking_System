#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include "AccountHolder.h"
#include "Finance.h"

Finance::Finance(){}

//make deposit
void Finance::depositFunds(){
    double funds{0.0};
    system("clear");
    std::cout << "How much would you like to deposit?" << std::endl;
    std::cin >> funds;
    std::cin.ignore();
    balance[0] += funds;

    system("clear");
    std::cout << "Your deposit was a success" << std::endl;
    std::cout << "Your available balance is R" << balance[0] << std::endl;
}
//end deposit

//make withdrawal
void Finance::withdrawFunds(){
    double withdrawAmnt{0};
    char choice{};
    system("clear");
    std::cout << "How much would you like to withdraw?" << std::endl;
    std::cin >> withdrawAmnt;
    std::cin.ignore();
    if(withdrawAmnt < balance[0]){
        balance[0] -= withdrawAmnt;
        system("clear");
        std::cout << "Withdrawal successfull :)" << std::endl;
        std::cout << "Your current balance is R" << balance[0]  << std::endl;
    }
    else{
        system("clear");
        std::cout << "Sorry...you seem to have insuffecient funds in your account" << std::endl;
        std::cout << "Would you like to make a deposit? (y/n)  ";
        std::cin >> choice;
        std::cin.ignore();
        if(toupper(choice) == 'Y'){
            depositFunds();
        }
        else{
            system("clear");
            std::cout << "back to menu." << std::endl;
        }

    }

}
//end withdrawal

//loan function ***improve ** make loan amount higher
void Finance::tempLoan(){
    long double salaryVal  {salary[0]};
    long double currentBalance {balance[0]};
    const double interestRate {0.08};
    long double loanAmnt {0.0};
    char choice{};
    currentBalance > salaryVal ? loanAmnt = salaryVal + (salaryVal * 0.15) :
    loanAmnt = salaryVal - (salaryVal * 0.15);

    double monthlyInstallment = (loanAmnt + (loanAmnt * interestRate)) / 24;

    system("clear");
    std::cout << "Based on your salary and current balance," << std::endl;
    std::cout << "we can offer you a temporay loan of R" << loanAmnt << ",";
    std::cout << "payable over a span of 24 months" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "We offer a fixed interest rate of " << interestRate * 100 << "%" << std::endl;
    std::cout << "Your monthly installments will be R" << monthlyInstallment
     << " payable at the end of every month" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Accept loan deal and proceed? (y/n)  ";
    std::cin >> choice;
    std::cin.ignore();

    if(toupper(choice) == 'Y'){
        balance[0] += loanAmnt;
        system("clear");
        std::cout << "Loan approved...your current balance is R" << balance[0] << std::endl;
    }
    else{
        system("clear");
        std::cout << "Sorry we couldn't come to an agreement :(" << std::endl;
    }
}


//invest choice
void Finance::investChoice(long double initiallInvestment){
    char choice{};
    //system("clear");
    std::cout << "Would you like to go ahead with the investment? (y/n)  ";
    std::cin >> choice;
    std::cin.ignore();

    //check if user wants to invest
    if(toupper(choice) == 'Y'){
        //std::cout << "Ok" << std::endl;

        //check if user has enough in balance
        if(initiallInvestment < balance[0]){
            balance[0] -= initiallInvestment;

            system("clear");
            std::cout << "Transaction successfull :) Thank you for investing your money with us. " << std::endl;
            std::cout << "Your current balance is R" << balance[0] << std::endl;
        }
        else{
            system("clear");
            std::cout << "I'm sorry you don\'t have suffecient funds in your accout to proceed" << std::endl;
            std::cout << "Would you like to make a deposit? (y/n)  ";
            char makeDeposit{};
            std::cin >> makeDeposit;
            std::cin.ignore();
            if(toupper(makeDeposit) == 'Y'){
                depositFunds();
            }
            else{
                system("clear");
                std::cout << "Sorry we couldn\'t come to an agreement" << std::endl;
            }

        }//end check if user has enough in balance

    }
    else{
        system("clear");
        std::cout << "Sorry we couldn\'t help you today. Goodbye" << std::endl;
    }//end check if user wants to invest



}


//invest display
void Finance::investOptionDisplay(int minInvestYears, long double initiallInvestment,
                            int percentage, std::string investmentPlan){


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
void Finance::invest(){
    int option{0};
    do{
    std::cout << "We offer a number of investment options";
    std::cout << "...choose option to learn more" << std::endl;
    std::cout << "1. Silver Investment Path" << std::endl;
    std::cout << "2. Gold Investment Path" << std::endl;
    std::cout << "3. Platinum Investment Path" << std::endl;
    std::cout << "4. Back to main screen" << std::endl;
    std::cin >> option;
    std::cin.ignore();

    switch(option){
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

    }while(option != 4);
}
//end invest


void Finance::moneyTransfer(){
    std::cout << "Enter the account number you'd like to transfer funds to" << std::endl;
    int transferTo{0};
    std::cin >> transferTo;
    std::cin.ignore();
    int cnt{0};
    int amnt{0};

    for(int i = 0; i < accountNumber.size(); i++){
        if(transferTo == accountNumber[i]) {
        cnt = i;
        std::cout << "How much would you like to transfer?" << std::endl;
        std::cin >> amnt;
        std::cin.ignore();
        balance[searchIndex] -= amnt;
        balance[cnt] += amnt;

        std::cout << "Transfer complete" << std::endl;
        std::cout << "Your current balance is R" << balance[searchIndex] << std::endl;
        std::cout << fullName[cnt] << "'s current balance is R" << balance[cnt] << std::endl;
        }
        else cnt++;
    }
    if(cnt == accountNumber.size()){
        system("clear");
        std::cout << "Sorry account number not found :( Please enter a another account number" << std::endl;
    }

}


//transaction screen
void Finance::transactions(){
    int choice{0};
    system("clear");
    std::cout << "Welcome " << getFullName()[searchIndex] << ". Choose one of the below options"<< std::endl;
do{

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

    switch(choice){
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
             std::cout << "Your current balance is R" << balance[0] << std::endl;
            break;

            case 5:
            invest();
            break;

            case 6:
            moneyTransfer();
            break;

            case 7:
            break;

        case 8:
        system("clear");
        std::cout << "Account holder      ------> " << getFullName()[searchIndex] << std::endl;
        std::cout << "Account number      ------> " << getAccNum()[searchIndex] << std::endl;
        std::cout << "Account holder pin  ------> " << getPin()[searchIndex] << std::endl;
        std::cout << "Salary              ------> R" << getSalary()[searchIndex] << std::endl;
        std::cout << "Account balance     ------> R" << getBalance()[searchIndex] << std::endl;
        break;

        case 9:
        break;

        default:
        system("clear");
        std::cout << "" << std::endl;
    }

}while(choice != 0);

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

    for(int i = 0; i < pin.size(); i++){
        if(input == pin[i]){
        searchIndex = i;
        transactions();
        break;
        }
        cnt++;
    }
    if(cnt == pin.size()){
    system("clear");
    std::cout << "Incorrect pin" << std::endl;
    }

}

