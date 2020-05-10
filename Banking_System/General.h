#ifndef GENERAL_H
#define GENERAL_H


class General
{
public:
    General();
    long int getRandom(long int minNum, long int maxNum);
    std::string getAccountHolderName();
    long double getSalaryVal();
    long double getInitialAmt();
    void withdrawFunc(int amnt, std::vector<int> &wDrawVec,
                      std::vector<long double> &tempBal,
                      int i, std::string str);
    void displayBalance(std::vector<long double> tempBal, int i);
    void displayTransactionPrompt(std::string trans);
    void insufficientFunds();
    int dateAndTime();
    void displayInvalidInput(std::string str);
    void createFile(std::string name, long int accNum, int pin, long double sal, long double bal,
                    int recWithdraw, int recDeposit)

};

#endif // GENERAL_H
