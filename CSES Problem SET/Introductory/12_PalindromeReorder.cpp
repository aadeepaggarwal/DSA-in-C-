#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string s;
    cin >> s;
    unordered_map<char, int> freq;
    
    // Count frequencies
    for(char c : s) {
        freq[c]++;
    }
    
    // Check if palindrome is possible
    int oddCount = 0;
    char oddChar;
    for(auto x : freq) {
        if(x.second % 2 == 1) {
            oddCount++;
            oddChar = x.first;
        }
    }
    
    if(oddCount > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    
    // Construct palindrome
    string result;
    // Add first half
    for(auto x : freq) {
        string temp(x.second/2, x.first);
        result += temp;
    }
    
    // Add middle character if exists
    if(oddCount == 1) {
        result += oddChar;
    }
    
    // Add second half
    string firstHalf = result;
    if(oddCount == 1) {
        firstHalf.pop_back();  // Remove middle character
    }
    for(int i = firstHalf.length()-1; i >= 0; i--) {
        result += firstHalf[i];
    }
    
    cout << result << "\n";
    return 0;
}