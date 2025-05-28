#include <iostream>
using namespace std;
int main() {

    int a[][4]={
        {1,2,3,4},
        {4,5,6,7},
        {7,8,9,10}// takes the un entered last column automatically as 0
    };

    // to print or traverse take two loop one of row one of column inside it

    int row, col;
    row = sizeof(a)/sizeof(a[0]);
    // sizeof(a) gives 36 bytes total elements 9 and size 4
    //sizeof(a[0]) returns 12 the size of 1st row all coulmns

    col= sizeof(a[0])/sizeof(int);
    // ek row ke size ko integer ki bucket ke size se divide karenge to coulmns mil jayenge
    for (int i = 0; i < col; i++)
    {   if(i%2==0){
        for (int j = 0; j < row; j++)
        {
            cout<<a[j][i]<<' ';
        }
        cout<<'\n';  
    }
        else{
            for (int j = row-1; j >=0; j--)
        {
            cout<<a[j][i]<<' ';
        }
        cout<<'\n';

        }
       
        
    }
    
    return 0;
}