#include <iostream>
using namespace std;

// print the values of all 32 bits in an integer bit
// NOTE: 1<<0 0 shifts in 1 is equal to 2 ki power 0, 1<<1 is 1 bar 1 shift is 2 ki power 1 thus 1<<n is 2 power n
int main()
{
    // pehle my way
    int N;
    // take checker as power 30, not 31 because 31st bit is sign bit
    int checker = (1 << 30); // dikkat ye hai ki int lelia so last bit sign bit ho gayi... unsigned leleta to dikkat nahi aati
    cout << "enter the number :";
    cin >> N;
    // use this ternary operator to print the sign bit as our checker is integer type
    cout << ((N & (1 << 31)) != 0) ? 1 : 0; // ternary operator condition? (if true task):(if false task);
    for (int i = 1; i <= 31; i++)
    {
        if ((N & checker) == 0)
        {
            cout << '0';
        }
        else
        {
            cout << '1';
        }
        checker >>= 1;
    }
    cout << '\n';
    // or sir ka way ... ye karte hue woh ternary operator wala nahi needed hi ab kyonki yaha checket jo i hai woh integer bucket mein nahi aya
    cout << "output by 2nd method" << endl;
    for (int i = 31; i >= 0; i--)// 32 times 31 se 0 tak ka loop lagaya
    {
        if ((N & (1 << i)) == 0)// check last se and right shift i pe laga de!!
        {
            cout << '0';
        }
        else
        {
            cout << '1';
        }
    }
    return 0;
}
