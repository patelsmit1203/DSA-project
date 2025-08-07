#include <iostream>
using namespace std;

// Base Class
class BankAccount {
public:
    int accountNumber;
    string accountHolderName;
private:
    double balance;

public:
    void createAccount(int accNo, string name, double bal) {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
    }

         // Deposit method to add money

    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
        else
            cout << "Invalid amount\n";
    }

      // Withdraw method 

    void withdraw(double amount) {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "non-sufficient balance.\n";
    }

    double getBalance() {
        return balance;
    }

       // Display account details

    void display() {
        cout << "\nAccount Number: " << accountNumber<<endl;
        cout << "\nAccount Holder: " << accountHolderName<<endl;
        cout << "\nBalance: $" << balance << endl;
    }
};

// Derived Class
      
class SavingsAccount : public BankAccount {
public:
    double interestRate;

       // Method to calculate and show interest

    void Interest() {
        double interest = getBalance() * interestRate / 100;
        cout << "Interest: $" << interest << endl;
    }
};

int main() {
    SavingsAccount acc[10]; 
    int total = 0;
    int choice;

           // Show menu
    do {
        cout << "\n=== MENU ===\n";
        cout << "1 Create Account\n";
        cout << "2 Deposit\n";
        cout << "3 Withdraw\n";
        cout << "4 Display Account\n";
        cout << "5 Interest\n";
        cout << "6 Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        int index;
        double amount;
        switch (choice) {
        	// Create account
        case 1:
            if (total < 10) {
                int accNo;
                string name;
                double bal, rate;
                cout <<"Enter Account Number :"<<endl;
                cout<<"Enter Your Name :"<<endl;
                cout<<"Your bank Balance :"<<endl;
                cout<<"Interest Rate :"<<endl;
                cin >> accNo >> name >> bal >> rate;
                acc[total].createAccount(accNo, name, bal);
                acc[total].interestRate = rate;
                total++;
            } else {
                cout << "Account limit reached.\n";
            }
            break;

        case 2:
        	// Deposit
            cout << "Enter account index and deposit amount: ";
            cin >> index >> amount;
            if (index >= 0 && index < total)
                acc[index].deposit(amount);
            else
                cout << "Invalid index.\n";
            break;

        case 3:
        	// Withdraw
            cout << "Enter account index and withdraw amount: ";
            cin >> index >> amount;
            if (index >= 0 && index < total)
                acc[index].withdraw(amount);
            else
                cout << "Invalid index.\n";
            break;

        case 4:
        	// Display account
            cout << "Enter account index to display: ";
            cin >> index;
            if (index >= 0 && index < total)
                acc[index].display();
            else
                cout << "Invalid index.\n";
            break;

        case 5:
        	    //interest
            cout << "Enter account index to  interest: ";
            cin >> index;
            if (index >= 0 && index < total)
                acc[index].Interest();
            else
                cout << "Invalid index.\n";
            break;

        case 6:
            cout << "Exit\n";
            break;

        default:
            cout << "Invalid option!\n";
        }

    } while (choice != 6);

    return 0;
}

