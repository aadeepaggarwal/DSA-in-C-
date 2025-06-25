#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll; // bade numbers handle karne ke liye long long use kiya hai

// Yeh function check karega ki kya hum array ko k subarrays mein baant sakte hain
// jismein har subarray ka sum maxSum se zyada na ho
bool isPossible(vector<ll>& arr, int k, ll maxSum) {
    int subarrays = 1; // pehla subarray shuru
    ll currentSum = 0;
    
    for (ll num : arr) {
        
        // agar current subarray ka sum maxSum cross kar gaya toh naya subarray shuru karo
        if (currentSum + num > maxSum) {
            subarrays++;      // ek naya subarray bana
            currentSum = num; // usmein current element daal diya

            // agar subarrays ki count k se zyada ho gayi toh impossible hai
            if (subarrays > k) return false;
        } else {
            currentSum += num; // current element ko same subarray mein daal diya
        }
    }
    
    return true; // agar k ya usse kam subarrays ban gaye toh possible hai
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    
    ll maxElement = 0, sum = 0;
    
    // array input lo aur maximum element aur total sum calculate karo
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        maxElement = max(maxElement, arr[i]); // maximum element nikal lo
        sum += arr[i];                       // total sum bhi nikal lo
    }
    
    // Binary Search ka range: [sabse bada element, total sum]
    ll left = maxElement, right = sum, answer = sum;
    
    // Binary Search shuru
    while (left <= right) {
        ll mid = left + (right - left) / 2; // beech ka candidate answer
        
        // check karo ki yeh mid value maximum sum ban ke kaam karegi ya nahi
        if (isPossible(arr, k, mid)) {
            answer = mid;    // agar possible hai toh answer update karo
            right = mid - 1; // chhota answer dhoondhne ki koshish karo
        } else {
            left = mid + 1;  // agar possible nahi hai toh bada answer dhoondo
        }
    }
    
    cout << answer << endl; // final answer print karo
    
    return 0;
}
