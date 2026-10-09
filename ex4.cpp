//ex4
#include <iostream>
#include <string>
using namespace std;

// Base Class containing common attributes and behaviors
class BankAccount {
protected:
    string accountHolderName;
    int accountNumber;
    double balance;

public:
    BankAccount(string name, int accNumber, double initialBalance) {
        accountHolderName = name;
        accountNumber = accNumber;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: ₹" << amount << endl;
        }
    }

    // Virtual function so derived classes can override behavior if needed
    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: ₹" << amount << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    // Virtual function for custom account breakdowns
    virtual void display() const {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: ₹" << balance << endl;
    }

    virtual ~BankAccount() {} // Virtual destructor for safe dynamic allocation
};

// Derived Savings Account Class
class SavingAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingAccount(string name, int accNumber, double initialBalance, double rate)
        : BankAccount(name, accNumber, initialBalance), interestRate(rate) {}

    void applyInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Interest Applied: ₹" << interest << endl;
    }

    void display() const override {
        cout << "\n[Savings Account]" << endl;
        BankAccount::display(); // Reuses base display logic
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

// Derived Checking Account Class
class CheckingAccount : public BankAccount {
private:
    double transactionFee;

public:
    CheckingAccount(string name, int accNumber, double initialBalance, double fee)
        : BankAccount(name, accNumber, initialBalance), transactionFee(fee) {}

    // Overriding withdrawal behavior to factor in transaction fees
    void withdraw(double amount) override {
        double total = amount + transactionFee;
        if (total <= balance) {
            balance -= total;
            cout << "Withdrawn: ₹" << amount << " (₹" << transactionFee << " fee applied)" << endl;
        } else {
            cout << "Insufficient balance for withdrawal + fee!" << endl;
        }
    }

    void display() const override {
        cout << "\n[Checking Account]" << endl;
        BankAccount::display(); // Reuses base display logic
        cout << "Transaction Fee: ₹" << transactionFee << endl;
    }
};

// Main Function
int main() {
    SavingAccount savings("Alice", 1001, 5000.0, 3.0);
    CheckingAccount checking("Bob", 1002, 3000.0, 20.0);

    // Operations on Savings Account
    savings.display();
    savings.deposit(1000);
    savings.withdraw(2000);
    savings.applyInterest();
    savings.display();

    // Operations on Checking Account
    checking.display();
    checking.deposit(1500);
    checking.withdraw(1000);
    checking.display();

    return 0;
}
