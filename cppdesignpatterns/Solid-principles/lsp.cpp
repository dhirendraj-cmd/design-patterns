#include <iostream>
#include <vector>
#include <typeinfo>
#include <stdexcept>

using namespace std;


class DepositOnlyAccount{
    public:
        virtual void deposit(double amount) = 0;
};


class WithdrawAccount: public DepositOnlyAccount{
    public:
        virtual void withdraw(double amount) = 0;
};


class SavingsAccount: public WithdrawAccount{
    private:
        double balance;

    public:
        void deposit(double amount) override{
            balance += amount;
            cout << "After depositing "<< amount <<" new balance is "<<balance << endl;
        }

        void withdraw(double amount) override{
            if(balance>=amount){
                balance -= amount;
                cout << "After withdrawal "<< amount <<" new balance is "<<balance << endl;
            } else{
                cout<<"You don't have sufficient balance\n";
            }
        }
};


class FixedDepositAccount: public DepositOnlyAccount{
    private:
        double balance;

    public:
        FixedDepositAccount(){
            balance = 0;
        }

        void deposit(double amount) override{
            balance += amount;
            cout << "After depositing in FD"<< amount <<" new balance is "<<balance << endl;
        }

};


class BankClient{
    private:
        vector<WithdrawAccount*> withdrawableAccounts;
        vector<DepositOnlyAccount*> fdAccount;

    public:
        BankClient(vector<WithdrawAccount*> withdrawableAccounts, vector<DepositOnlyAccount*> fdAccount){
            this->withdrawableAccounts = withdrawableAccounts;
            this->fdAccount = fdAccount;
        }

        void processTransaction(){
            for(WithdrawAccount* acc: withdrawableAccounts){
                acc->deposit(1024);
                acc->withdraw(230);
            }

            for(DepositOnlyAccount* acc: fdAccount){
                acc->deposit(10240);
            }
        }


};


int main(){
    vector<WithdrawAccount*> withdrawableAccounts;
    withdrawableAccounts.push_back(new SavingsAccount());

    vector<DepositOnlyAccount*> fdAccount;
    fdAccount.push_back(new FixedDepositAccount());


    BankClient* bcl = new BankClient(withdrawableAccounts, fdAccount);
    bcl->processTransaction();


    return 0;
}
