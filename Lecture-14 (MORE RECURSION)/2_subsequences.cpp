#include <iostream>
using namespace std;

void subsequences(char *a, char *op, int i, int j)
{
    // base case
    if (a[i] == '\0')
    {
        op[j] = '\0';
        cout << op << endl; // print ho jayega phi lagake saara jitna stored tha op mein ab tak
        return;
    }
    // recursive case
    subsequences(a, op, i + 1, j); // yaha we call it for 1st element ke aage wale sab
    // part 2
    op[j] = a[i]; // copy pehla element op mein
    // copy karke uss op pe call function
    subsequences(a, op, i + 1, j + 1);
}
int main()
{
    char a[] = "abc";
    char op[10];
    subsequences(a, op, 0, 0);
    return 0;
}