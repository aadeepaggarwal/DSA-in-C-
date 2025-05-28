#include <iostream>
using namespace std;

bool isSafe(int board[][10], int i, int j, int n)
{
    // pehle check kar ki current coulmn mein kahin koi queen already na ho
    for (int k = 0; k < i; k++)
    {
        if (board[k][j] == 1)
        {
            return 0; // queen hui to 0 karde
        }
    }
    int original_i = i;
    int original_j = j; // i and j update ho jayenge isilye store them
    // check left diagonal
    while (i >= 0 and j >= 0)
    {
        if (board[i--][j--] == 1)
        {
            return 0;
        }
    }
    // check right wali diagonal
    // because i and j update ho gaya tha so update karde bas usey
    i = original_i;
    j = original_j;
    while (i >= 0 and j <= n)
    {
        if (board[i--][j++] == 1)
        {
            return 0;
        }
    }
    // if we pass all the loops of check means safe to place return 1
    return 1;
}

bool NQueen(int board[][10], int i, int n)
{
    // base case
    // stop jab sab rows mein mai queen place kar chuka hounga
    if (i == n)
    {   // print bhi base case mein hi hoga
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                board[i][j] == 1 ? cout << "Q " : cout << "_ ";
            }
            cout << '\n';
        }
        cout << '\n';

        // return true; agar ek hi case chaiye warna return false saare cases ke liye
        return false; // ye karke ek case ke baad false agaya jaise to peeche jayenge backtracking lagegi aur 1st row pe reach ke j+1 lagega and next possibilty ayegi
    }
    

    // recursive case
    for (int j = 0; j < n; j++)// iterate over the j coulmns of the ith row
    {
        if (isSafe(board, i, j, n))// check if jth cell is safe in ith row
        {
            board[i][j] = 1; // agar safe hai uss cell pe rakhne ko to waha place the queen
            bool kyaBakiRakhSakteHain = NQueen(board, i + 1, n);// check ki i,j pe rakhne ke baad kya neeche ke baaki place ho pa rahe hain ya nahi
            if (kyaBakiRakhSakteHain == 1)
            {
                return 1;// agar baki pe place hua to return true
            }
            else
                board[i][j] = 0; // call it on j+1 because i+1 nahi chala and board[i][j] ko 0 karde jp pehle 1 kara tha -> BACKTRACKING
        }
    }
    return 0; // agar we came out of loop and kisi bhi j pe place nahi hui queen to false return
}
int main()
{
    int n;
    cout << " Enter the value of n : ";
    cin >> n;
    int board[10][10] = {0};
    NQueen(board, 0, n);

    return 0;
}