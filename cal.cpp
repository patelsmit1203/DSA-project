#include <iostream>
using namespace std;

int main() {
    int choice;
    double num1, num2, result;

    while (true) {
        cout << "\nCalculator Menu\n";
        cout << "Press 1 to Add (+)\n";
        cout << "Press 2 to Multiply (*)\n";
        cout << "Press 3 to Subtract (-)\n";
        cout << "Press 4 to Divide (/)\n";
        cout << "Press 0 to Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Exiting " << endl;
            break;
        }

        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;

        switch (choice) {
            case 1:
                result = num1 + num2;
                cout << "Result: " << result << endl;
                break;
            case 2:
                result = num1 * num2;
                cout << "Result: " << result << endl;
                break;
            case 3:
                result = num1 - num2;
                cout << "Result: " << result << endl;
                break;
            case 4:
                if (num2 != 0) {
                    result = num1 / num2;
                    cout << "Result: " << result << endl;
                } else {
                    cout << "Error: Division by zero is not allowed." << endl;
                }
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
    return 0;
}

