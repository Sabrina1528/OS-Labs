#include <bits/stdc++.h>
using namespace std;

// Function to update the array in most recently used fashion
void recently(int* arr, int size, int elem) {
    int index = (elem % size);  // Calculate index based on modulus
    int temp = index;
    int id = arr[index];        // Store the element at that index

    // Shift elements to the right
    while (temp > 0) {
        arr[temp] = arr[--temp];
    }
    arr[0] = id;  // Place the selected element at the front
}

// Function to print array elements
void print(int* arr, int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int main() {
    int elem = 3;
    int arr[] = {6, 1, 9, 5, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    recently(arr, size, elem);

    cout << "Array in most recently used fashion: ";
    print(arr, size);

    return 0;
}

