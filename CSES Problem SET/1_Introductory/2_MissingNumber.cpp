#include <iostream>
#include <vector>
using namespace std;
int main() {
    long long n;
    cin >> n;
    long long sum = 0;  
    vector<int> arr(n - 1); // Array to hold the numbers from 1 to n except the missing one
    for (long long i = 0; i < n - 1; ++i) {
        cin >> arr[i]; // Read the numbers into the array
        sum += arr[i]; // Calculate the sum of the provided numbers
    }
    
    long long totalSum = (n * (n + 1)) / 2; // Sum of first n natural numbers
    long long missingNumber = totalSum - sum; // The missing number
    cout << missingNumber << endl; // Output the missing number
    return 0;
}