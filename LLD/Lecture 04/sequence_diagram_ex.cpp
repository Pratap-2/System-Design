#include <bits/stdc++.h>
using namespace std;

class Account {
public:
    bool checkBalance(int amount) {
        return amount <= 5000;
    }
};

class CashDispenser {
public:
    void dispenseCash(int amount) {
        cout << "Dispensing cash: " << amount << endl;
    }
};

class Transaction {
    Account* account;
    CashDispenser* dispenser;

public:
    Transaction(Account* acc, CashDispenser* disp)
        : account(acc), dispenser(disp) {}

    void withdraw(int amount) {
        if (account->checkBalance(amount)) {
            dispenser->dispenseCash(amount);
        } else {
            cout << "Insufficient funds\n";
        }
    }
};

int main() {
    Account acc;
    CashDispenser dispenser;

    Transaction tx(&acc, &dispenser);
    tx.withdraw(3000);
    tx.withdraw(7000);

    return 0;
}
