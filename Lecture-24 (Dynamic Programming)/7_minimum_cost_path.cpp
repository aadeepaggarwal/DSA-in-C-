#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int cost[4][4] = {{1,1,4,2},
                      {5,1,1,6},
                      {2,3,1,1},
                      {2,4,1,3}};
    
    // Initialize a 4x4 dp array with 0 values
    vector<vector<int>> dp(4, vector<int>(4, 0));
    
    dp[0][0] = cost[0][0];
    
    // Fill the dp array using bottom-up approach
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(i == 0 && j > 0) {
                dp[i][j] = dp[i][j-1] + cost[i][j];  // First row
            } 
            else if(j == 0 && i > 0) {
                dp[i][j] = dp[i-1][j] + cost[i][j];  // First column
            } 
            else if(i > 0 && j > 0) {
                dp[i][j] = cost[i][j] + min(dp[i-1][j], dp[i][j-1]);  // Remaining cells
            }
        }
    }
    
    // Output the dp array
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
