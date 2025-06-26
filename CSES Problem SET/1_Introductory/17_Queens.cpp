#include<bits/stdc++.h>
using namespace std;



bool issafe(vector<vector<char>>& board, int row, int col) {
    int n = 8;
    // Check column
    for(int i = 0; i < row; i++) {
        if(board[i][col] == '1') return false;
    }
    
    // Check left diagonal
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == '1') return false;
    }
    
    // Check right diagonal
    for(int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if(board[i][j] == '1') return false;
    }
    
    return true;
}

bool solve(vector<vector<char>>& board, int n, int row, int &count) {
    // base case
    if(row == 8) {
        count+=1;
        return false;
    }
    
    // recursive case
    for(int col = 0; col < 8; col++) {
        if(board[row][col] != '*' && issafe(board, row, col)) {
            board[row][col] = '1';
            solve(board, n-1, row+1,count);
            board[row][col] = '.';
        }
    }
    return false;
}

int main() {
    int n = 8;
    int count =0;
    vector<vector<char>> board(n, vector<char>(n));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    
    solve(board, n, 0, count);
    cout << count << endl;
    return 0;
}