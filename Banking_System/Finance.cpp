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
    std::cout << "How much would you like to deposit?" << std::endl;
    std::cin >> funds;
    std::cin.ignore();
    balance[0] += funds;

    std::cout << "Your deposit was a success" << std::endl;
    std::cout << "Your available balance is R" << balance[0] << std::endl;
}
//end deposit

//make withdrawal
void Finance::withdrawFunds(){
    double withdrawAmnt{0};
    char choice{};
    std::cout << "How much would you like to withdraw?" << std::endl;
    std::cin >> withdrawAmnt;
    std::cin.ignore();
    if(withdrawAmnt < balance[0]){
        balance[0] -= withdrawAmnt;
        std::cout << "Withdrawal successfull :)" << std::endl;
        std::cout << "Your current balance is R" << balance[0]  << std::endl;
    }
    else{
        std::cout << "Sorry...you seem to have insuffecient funds in your account" << std::endl;
        std::cout << "Would you like to make a deposit? y/n__";
        std::cin >> choice;
        std::cin.ignore();
        if(toupper(choice) == 'Y'){
            depositFunds();
        }
        else{
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

    std::cout << "Based on your salary and current balance," << std::endl;
    std::cout << "we can offer you temporay loan of R" << loanAmnt << ",";
    std::cout << "payable over a span of 24 months" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "We offer a fixed interest rate of " << interestRate * 100 << "%" << std::endl;
    std::cout << "Your monthly installments will be R" << monthlyInstallment
     << " payable by the last day of the month" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Accept loan deal and proceed? y/n__";
    std::cin >> choice;
    std::cin.ignore();

    toupper(choice) == 'Y' ?  std::cout << "Loan approved :)" << std::endl :
     std::cout << "Sorry we couldn't come to an agreement :(" << std::endl;

}


//transaction screen
void Finance::transactions(){
int choice{0};

do{

    std::cout << "1. Make a deposit" << std::endl;
    std::cout << "2. Make a withdrawal" << std::endl;
    std::cout << "3. Take a temporary loan" << std::endl;
    std::cout << "4. Check balance" << std::endl;
    std::cout << "5. Invest your money" << std::endl;
    std::cout << "6. Transer money to another account" << std::endl;
    std::cout << "7. Print statement" << std::endl;
    std::cout << "8. View details" << std::endl;

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
             std::cout << "Your current balance is R" << balance[0] << std::endl;
            break;

            case 5:
            break;

            case 6:
            break;

            case 7:
            break;

        case 8:
        std::cout << "Account holder      ------> " << getFullName()[0] << std::endl;
        std::cout << "Account number      ------> " << getAccNum()[0] << std::endl;
        std::cout << "Account holder pin  ------> " << getPin()[0] << std::endl;
        std::cout << "Salary              ------> R" << getSalary()[0] << std::endl;
        std::cout << "Account balance     ------> R" << getBalance()[0] << std::endl;
        break;

        case 9:
        break;

        default:
        std::cout << "Running anyway" << std::endl;
    }

}while(choice != 0);

}

//to access existing account
void Finance::authorization(int pin)
{
    int input{0};
    std::cout << "Please enter your pin code to access account__ ";
    std::cin >> input;
    std::cin.ignore();
    if(input == pin){
    transactions();
    } else std::cout << "Incorrect pin" << std::endl;
}

