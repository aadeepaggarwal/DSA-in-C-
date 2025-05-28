#include <iostream>
#include <vector>
using namespace std;
int main() {
    int rows,cols,value;
    rows=5;
    cols=4;
    value=9;// means 2d array ki har value 9
    vector<vector<int>> a(rows, vector<int>(cols,value));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}