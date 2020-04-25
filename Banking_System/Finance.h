#ifndef FINANCE_H
#define FINANCE_H


class Finance: public AccountHolder
{
    public:
        Finance();
        void authorization(int pin);
        void depositFunds();
        void withdrawFunds();
        void transactions();
        void tempLoan();


    private:
};

#endif // FINANCE_H
