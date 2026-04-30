#include <iostream>
#include <string>

class BankAccount 
{
private:
    std::string owner;
    double balance;

public:
    BankAccount(std::string ownerName, double cash)
    {
        owner = ownerName;
        balance = cash;
    }

    void setOwner(std::string Name){
        owner = Name;
    }
    std::string getOwner(){
        return owner;
    }
    void deposit(double amount){
        if (amount <= 0){
            std::cout << "Invalid amount to deposit!" << std::endl;
        }
        balance += amount;
        std::cout << "Your new balance is: " << balance << std::endl;
    }
    void withdraw(double amount){
        if (amount > balance || amount <= 0)
        {
            std::cout << "Invalid amount to withdraw!" << std::endl;
        }
        balance -= amount;
        std::cout << "Your new balance is: " << balance << std::endl;
    }
    double getBalance();
    void getAccountInfo();
};

double BankAccount::getBalance()
{
    return balance;
}

void BankAccount::getAccountInfo()
{
    std::cout << "Owner: " << owner << std::endl;
    std::cout << "Balance: " << balance << std::endl;
}


int main()
{
    BankAccount myAccount("Daniel", 2500);
    std::string Name = myAccount.getOwner();
    std::cout << "Old Name: " << Name << std::endl;
    myAccount.setOwner("Daniel (new)");
    Name = myAccount.getOwner();
    std::cout << "New Name: " << Name << std::endl;

    double myCash = myAccount.getBalance();
    std::cout << "Current balance: " << myCash << std::endl;
    myAccount.deposit(300);
    myAccount.withdraw(1000);

    myAccount.getAccountInfo();

    return 0;
}