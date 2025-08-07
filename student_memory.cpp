#include <iostream>
#include <vector>
using namespace std;

// Template Class
template <class T>
class MemoryCalculate {
public:
    T id;
    string name;

    // Constructor
    MemoryCalculate(T i, string n) {
        id = i;
        name = n;
    }

    // Display function
    void display() {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

int main() {
    vector<MemoryCalculate<int>> students;
    int choice, id;
    string name;

    do {
        cout << "\n1. Add Student\n2. 2. Display All\n3. Search by ID\n4. Remove by ID\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> ws; 
            getline(cin, name);
            students.push_back(MemoryCalculate<int>(id, name));
            break;

        case 2:
            for (int i = 0; i < students.size(); i++) {
                students[i].display();
            }
            break;

        case 3:
            cout << "Enter ID to search: ";
            cin >> id;
            for (int i = 0; i < students.size(); i++) {
                if (students[i].id == id) {
                    students[i].display();
                    break;
                }
            }
            break;

        case 4:
            cout << "Enter ID to remove: ";
            cin >> id;
            for (int i = 0; i < students.size(); i++) {
                if (students[i].id == id) {
                    students.erase(students.begin() + i);
                    cout << "Student removed.\n";
                    break;
                }
            }
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}


