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

};

#endif // GENERAL_H
