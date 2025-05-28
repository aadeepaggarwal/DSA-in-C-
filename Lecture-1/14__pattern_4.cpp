#include <iostream>
using namespace std;
/*
    1
  2 3 2
3 4 5 4 3

*/
int main() {
    int N;
    cout << " enter the number of rows:";
    cin >> N;
    int row = 1;

    while (row <= N)
    {
        {
            int i = 1;
            while (i <= (N - row))
            {
                cout << "  ";
                i += 1;
            }
        }
        {
            int j= row;
            int i=1;
            while(i<= row){
                cout<< j<< " ";
                j+=1;
                i+=1;
            }

        }
        {
            int j= (((row)*2)-2);
            int i=1;
            while(i<=row-1){
                cout<< j<<" "; // adding extra space for better view on compiler.
                j-=1;
                i+=1;
            }

        }
        cout<<'\n';
        row+=1;
    }
    return 0;
}