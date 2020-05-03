#ifndef FINANCE_H
#define FINANCE_H


class Finance: public AccountHolder
{
public:
    Finance();
    void authorization(std::vector<int> pin);
    void depositFunds();
    void withdrawFunds();
    void transactions();
    void tempLoan();
    void investChoice(long double initiallInvestment);
    void investOptionDisplay(int minInvestYears, long double initiallInvestment, int percentage, std::string investmentPlan);
    void invest();
    void moneyTransfer();


private:
};

#endif // FINANCE_H
