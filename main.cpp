#include <iostream>
#include <string>
using namespace std;

struct Customer {
    string name;
    int age;
    string address;
};
class Account {
private:
    int accountNumber;
    double balance;
    Customer customer;
public:
    void createAccount(int accNum) {
        accountNumber = accNum;
        cout << "Enter customer first name: ";
        cin >> customer.name;
        cout << "Enter customer age: ";
        cin >> customer.age;
        cout << "Enter customer address: ";
        cin >> customer.address;
        cout << "Enter starting balance: $";
        cin >> balance;
    }
    void deposit(double amount) {
        balance += amount;
        cout << "New balance: $" << balance << endl;
    }
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "New balance: $" << balance << endl;
        } else {
            cout << "Not enough money!" << endl;
        }
    }
    void showAccount() {
        cout << "\nAccount Number: " << accountNumber << endl;
        cout << "Name: " << customer.name << endl;
        cout << "Age: " << customer.age << endl;
        cout << "Address: " << customer.address << endl;
        cout << "Balance: $" << balance << endl << endl;
    }
    int getAccountNumber() {
        return accountNumber;
    }
};
int main() {
    Account accounts[5];
    int totalAccounts = 0;
    int choice;
    int accountNum = 100;

    while (true) {
        cout << "\nBanking System Menu:\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Show Account\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
 switch (choice) {
 case 1: 
 if (totalAccounts < 5) {
 accounts[totalAccounts].createAccount(++accountNum);
 totalAccounts++;
 cout << "Account created! Number: " << accountNum << endl;
 } else  
 {
 cout << "Bank is full! No more accounts.Go to another bank." << endl;
 }
 break;

 case 2: { 
 int num;
 double amount;
 cout << "Enter account number: ";
 cin >> num;
 bool found = false;
 for (int i = 0; i < totalAccounts; i++) {
 if (accounts[i].getAccountNumber() == num) {
 cout << "Enter amount to deposit: $";
 cin >> amount;
 accounts[i].deposit(amount);
 found = true;
 break;
 }
 }
 if (!found) cout << "Account not found!" << endl;
 break;
 }

 case 3: {
 int num;
 double amount;
 cout << "Enter account number: ";
 cin >> num;
 bool found = false;
 for (int i = 0; i < totalAccounts; i++) {
 if (accounts[i].getAccountNumber() == num) {
 cout << "Enter amount to withdraw: $";
 cin >> amount;
 accounts[i].withdraw(amount);
 found = true;
 break;
 }
 }
 if (!found) cout << "Account not found!" << endl;
 break;
 }

 case 4: {
 int num;
 cout << "Enter account number: ";
 cin >> num;
 bool found = false;
 for (int i = 0; i < totalAccounts; i++) {
 if (accounts[i].getAccountNumber() == num) {
 accounts[i].showAccount();
 found = true;
 break;
 }
 }
 if (!found) cout << "Account not found!" << endl;
 break; 
 }

 case 5:
 cout << "Goodbye!" << endl;
 return 0;
 default:
 cout << "Invalid choice!" << endl;
 }
 }
    return 0;
}

