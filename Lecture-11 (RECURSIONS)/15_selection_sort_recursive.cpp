// #include <iostream>
// #include <climits>
// using namespace std;

// void selection_sort(int *a, int n, int i = 0, int j = 1) {
//     // Base case: If we have reached the end of the array
//     if (i == n - 1) return;

//     int smallest = i;

//     if (j < n) {
//         if (a[j] < a[smallest]) {
//             smallest = j;
//         }
//         selection_sort(a, n, i, j + 1); // Continue finding the smallest element in the subarray
//     } else {
//         swap(a[i], a[smallest]); // Swap the smallest element with the first element of the subarray
//         selection_sort(a, n, i + 1, i + 1); // Move to the next subarray
//     }
// }

// int main() {
//     int n;
//     cout << "Enter the size: ";
//     cin >> n;
//     int a[n];
//     for (int i = 0; i < n; i++) {
//         cout << "Enter the value of " << i << "th index: ";
//         cin >> a[i];
//     }

//     selection_sort(a, n); // Call the sorting function

//     for (int i = 0; i < n; i++) {
//         cout << a[i] << " ";
//     }

//     return 0;
// }
#include <iostream>
using namespace std;

void selection_sort(int *a, int n, int i = 0, int j = -1, int smallest = -1) {
    // Base case: if we have reached the end of the array
    if (i == n - 1) return;

    // Initialize j and smallest if they are not set
    if (j == -1) {
        j = i + 1;
        smallest = i;
    }

    // Find the smallest element in the unsorted portion of the array
    if (j < n) {
        if (a[j] < a[smallest]) {
            smallest = j;
        }
        // Recursively call to compare the next element
        selection_sort(a, n, i, j + 1, smallest);
    } 
    else {
        // Swap the found smallest element with the element at index 'i'
        if (smallest != i) {
            swap(a[i], a[smallest]);
        }
        // Recursively call selection_sort for the next index
        selection_sort(a, n, i + 1);
    }
}

int main() {
    int n;
    cout << "Enter the size: ";
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter the value of " << i << "th index: ";
        cin >> a[i];
    }

    selection_sort(a, n); // Call the sorting function

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
