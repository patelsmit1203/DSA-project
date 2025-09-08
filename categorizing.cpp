#include <iostream>
using namespace std;

const int SIZE = 100;
int arr[SIZE];
int n;

// Selection Sort
void selectionSort() {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
    cout << "Array sorted using Selection Sort.\n";
}

// Merge Sort Helpers
void merge(int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[SIZE], R[SIZE];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        merge(l, m, r);
    }
}

// Linear Search
void linearSearch(int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at index " << i << "\n";
            return;
        }
    }
    cout << "Element not found.\n";
}

// Binary Search (requires sorted array)
void binarySearch(int key) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == key) {
            cout << "Element found at index " << mid << "\n";
            return;
        }
        if (arr[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << "Element not found.\n";
}

// Display Array
void display() {
    cout << "Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// Main Menu
int main() {
    int choice, key;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    do {
        cout << "\nMenu:\n";
        cout << "1. Selection Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Linear Search\n";
        cout << "4. Binary Search (array must be sorted)\n";
        cout << "5. Display Array\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            selectionSort();
            break;
        case 2:
            mergeSort(0, n - 1);
            cout << "Array sorted using Merge Sort.\n";
            break;
        case 3:
            cout << "Enter element to search: ";
            cin >> key;
            linearSearch(key);
            break;
        case 4:
            cout << "Enter element to search: ";
            cin >> key;
            binarySearch(key);
            break;
        case 5:
            display();
            break;
        case 0:
            cout << "Exiting.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}

