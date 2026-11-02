#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Account {
    int accNo;
        string holder;
            double balance;

            public:
                Account(int no, string name, double initial)
                        : accNo(no), holder(name), balance(initial) {}

                            int getAccNo() const { return accNo; }
                                string getHolder() const { return holder; }
                                    double getBalance() const { return balance; }

                                        void deposit(double amount) {
                                                if (amount <= 0) { cout << "Invalid amount.\n"; return; }
                                                        balance += amount;
                                                                cout << "Deposited: ₹" << amount << " → Balance: ₹" << balance << "\n";
                                                                    }

                                                                        bool withdraw(double amount) {
                                                                                if (amount <= 0) { cout << "Invalid amount.\n"; return false; }
                                                                                        if (amount > balance) { cout << "Insufficient balance.\n"; return false; }
                                                                                                balance -= amount;
                                                                                                        cout << "Withdrew: ₹" << amount << " → Balance: ₹" << balance << "\n";
                                                                                                                return true;
                                                                                                                    }
                                                                                                                    };

                                                                                                                    class Bank {
                                                                                                                        string bankName;
                                                                                                                            vector<Account> accounts;
                                                                                                                                int nextAccNo;

                                                                                                                                public:
                                                                                                                                    Bank(string name) : bankName(name), nextAccNo(1001) {}

                                                                                                                                        void createAccount(string name, double initial) {
                                                                                                                                                accounts.push_back(Account(nextAccNo++, name, initial));
                                                                                                                                                        cout << "Account #" << nextAccNo - 1 << " created for " << name << "\n";
                                                                                                                                                            }

                                                                                                                                                                Account* findAccount(int accNo) {
                                                                                                                                                                        for (auto& a : accounts)
                                                                                                                                                                                    if (a.getAccNo() == accNo) return &a;
                                                                                                                                                                                            return nullptr;
                                                                                                                                                                                                }

                                                                                                                                                                                                    void displayAll() {
                                                                                                                                                                                                            cout << "\n===== " << bankName << " =====\n";
                                                                                                                                                                                                                    cout << setprecision(2) << fixed;
                                                                                                                                                                                                                            for (auto& a : accounts)
                                                                                                                                                                                                                                        cout << "#" << a.getAccNo() << " | " << a.getHolder()
                                                                                                                                                                                                                                                         << " | ₹" << a.getBalance() << "\n";
                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                             };

                                                                                                                                                                                                                                                             int main() {
                                                                                                                                                                                                                                                                 Bank bank("SBI");

                                                                                                                                                                                                                                                                     bank.createAccount("Rahul", 5000);
                                                                                                                                                                                                                                                                         bank.createAccount("Sneha", 3000);

                                                                                                                                                                                                                                                                             Account* acc = bank.findAccount(1001);
                                                                                                                                                                                                                                                                                 acc->deposit(2000);
                                                                                                                                                                                                                                                                                     acc->withdraw(1000);
                                                                                                                                                                                                                                                                                         acc->withdraw(10000);   // should fail

                                                                                                                                                                                                                                                                                             bank.displayAll();
                                                                                                                                                                                                                                                                                                 return 0;
                                                                                                                                                                                                                                                                                                 }