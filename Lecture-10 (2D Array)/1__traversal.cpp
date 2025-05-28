#include <iostream>
using namespace std;
int main() {

    int a[][4]={
        {1,2,3,4},
        {4,5,6,7},
        {7,8,9}// takes the un entered last column automatically as 0
    };

    // to print or traverse take two loop one of row one of column inside it

    int row, col;
    row = sizeof(a)/sizeof(a[0]);
    // sizeof(a) gives 48 bytes total elements 12 and size 4
    //sizeof(a[0]) returns 16 the size of 1st row all coulmns

    col= sizeof(a[0])/sizeof(int);
    // ek row ke size ko integer ki bucket ke size se divide karenge to coulmns mil jayenge
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
        
    }
    
    return 0;
}