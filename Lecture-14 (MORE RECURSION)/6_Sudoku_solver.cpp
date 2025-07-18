#include <iostream>
#include <cmath>
using namespace std;

bool isSafe(int mat[][9], int i, int j, int n, int number ){
    // check kar row and coulmn mein koi aur pe same number na ho
    for (int k = 0;  k< n ;  k++)
    {
        if ( mat[i][k]== number or mat[k][j]==number)
        {
            return false;
        }
        
    }
    // small box mein bhi number na mile ye check karo
    n=sqrt(n);
    int start_i=(i/n)*n;
    int start_j=(j/n)*n; // ye sab int hai isilye kaam kar jayega 
    for (size_t i = 0; i < n; i++)
    {
        for (size_t i = 0; i < n; i++)
        {
            if (mat[i][j]==number)
            {
               return false;
            }
            
        }
        
    }
    return true;// agar dono loops se bahar agaye to true kyonki number kahin nahi mila
    
    

}
bool SudokuSolver(int mat[][9], int i, int j, int n){
    // base case
    if(i==n)// we reached the end ke baad last row ke baad i++ kardia matlab solve hua beech mein false nahi aya to ab print
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<mat[i][j]<<" ";
            }
            cout<<"\n";
            
        }
        return true;
        
    }
    // recursive case

    // what if j overshoots n yani row ke end ke bahar aagaye to matlab next row ja
    if (j==n)
    {
        return SudokuSolver(mat, i+1,0,n);
    }
    // if the current cell is already filled
    if(mat[i][j]!=0){
        return SudokuSolver(mat,i,j+1,n);
    }
    // solve for one cell and call recursion for the rest of the matrice
    for (int number =1; number <=n; number++)
    {
        if(isSafe(mat, i,j,n,number)){
            mat[i][j]=number;
            bool KyaBakiSolveHua=SudokuSolver(mat, i, j+1, n);
            if (KyaBakiSolveHua)
            {
                return true;
            }
            mat[i][j]=0;
            
        }
    }
    return false;// agar sudoku nahi solve ho sakta upar wale tareeke se to neeche aajao
    
    

}
int main() {
    int mat[9][9] = {
		{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9}
	};
SudokuSolver(mat,0,0,9);
    return 0;
}