#include <iostream>
using namespace std;

bool rat_and_maze(char maze[][5], int solution[][10], int i, int j, int n, int m){
    // base case
    if (i==n-1 and j==m-1)
    {
        solution[i][j]=1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout<<solution[i][j]<<" ";
            }
            cout<<endl;
            
        }
        cout<<endl;
        return false; // true karte for ek path but we need all so we do false backtracking hoti rahegi fir
    }
    

    // recursive case
    // assume present wala cell is a part of the path abhi
    solution[i][j]=1;
    // right side se check solution hai ya nahi
    if (j+1<n and maze [i][j+1]!='X')
    {
        bool KyaRightSeBaatBani= rat_and_maze(maze, solution, i, j+1,n,m);
        if (KyaRightSeBaatBani)
        {
            return true;
        }
        
    }
    // down check kar 
    if (i+1<n and maze [i+1][j]!='X')
    {
        bool KyaNeecheSeBaatBani= rat_and_maze(maze, solution, i+1, j,n,m);
        if (KyaNeecheSeBaatBani)
        {
            return true;
        }
        
    }
    // agar upar wale true nahi aaya aur ham yaha tak pahuch gaaye to ab means that cell shouldn't be 1
    solution[i][j]=0;// BACKTRACKING
    return false;
    
    
}
int main() {
    char maze[][5]={ // n X m ki maze hai 
        "0000",
        "00XX",
        "0000",
        "XX00"
    };
    int solution[10][10]={0};
rat_and_maze(maze,solution,0,0,4,4);
    return 0;
}