#include<iostream>
using namespace std;

// ---------------- Linked List ----------------
struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void addToList(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
        head = newNode;
    else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void showList() {
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// ---------------- Merge Sort ----------------
void merge(int a[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[50], R[50];

    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}

// ---------------- Quick Sort ----------------
int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            int t = a[i]; a[i] = a[j]; a[j] = t;
        }
    }
    int t = a[i+1]; a[i+1] = a[high]; a[high] = t;
    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

// ---------------- Binary Search ----------------
int binarySearch(int a[], int size, int key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high)/2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// ---------------- Main Menu ----------------
int main() {
    int choice;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Add to Linked List\n";
        cout << "2. Show Linked List\n";
        cout << "3. Sort Array (Merge Sort)\n";
        cout << "4. Sort Array (Quick Sort)\n";
        cout << "5. Binary Search\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int val;
            cout << "Enter value: ";
            cin >> val;
            addToList(val);
        } else if (choice == 2) {
            showList();
        } else if (choice == 3 || choice == 4) {
            int n, arr[50];
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter elements: ";
            for (int i = 0; i < n; i++)
                cin >> arr[i];
            if (choice == 3)
                mergeSort(arr, 0, n - 1);
            else
                quickSort(arr, 0, n - 1);
            cout << "Sorted Array: ";
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
        } else if (choice == 5) {
            int n, arr[50], key;
            cout << "Enter number of elements: ";
            cin >> n;
            cout << "Enter sorted elements: ";
            for (int i = 0; i < n; i++)
                cin >> arr[i];
            cout << "Enter value to search: ";
            cin >> key;
            int pos = binarySearch(arr, n, key);
            if (pos != -1)
                cout << "Found at index " << pos << endl;
            else
                cout << "Not found.\n";
        }
    } while (choice != 0);

    return 0;
}

