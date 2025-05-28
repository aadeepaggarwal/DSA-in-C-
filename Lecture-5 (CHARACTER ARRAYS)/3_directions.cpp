#include <iostream>
using namespace std;
// tell the final position of the person based on the input of the ditections given
// answer must be lexicographic means alphabetical
// and give the smallest route based on input given
// hence note N cancels a S and E cancels W vice versa
// North is (x,y) mein y++ and South y-- and East x++ west is x--
// and initially we were at (0,0)
// finally print shortest path and for that see if y positive by 3 thus 3 times we have N=NNN
// if y negative means that many times south
// order is E N S W
int main()
{
    int x = 0, y = 0;
    char ch;
    ch = cin.get();
    while (ch != '\n')
    {
        if (ch == 'N')
        {
            y++;
        }
        else if (ch == 'S')
        {
            y--;
        }
        else if (ch == 'E')
        {
            x++;
        }
        else if (ch == 'W')
        {
            x--;
        }

        ch = cin.get();
    }
    cout << '(' << x <<','<< y << ')'<<'\n';

    // dictionary wise output E, N, S, W
    if (x >= 0)// note if ayega but then N S ke liye if dobara yega because condition ends at if ki implementation
    { // print E x times
        for (int i = 0; i < x; i++)
        {
            cout << 'E';
        }
    }
    if (y >= 0)
    { // print  N  xtimes
        for (int i = 0; i < y; i++)
        {
            cout << 'N';
        }
    }
    else if (y <= 0)
    { // print S y times
        for (int i = 0; i < abs(y); i++)
        {
            cout << 'S';
        }
    }
    if (x <= 0)
    { // print W x times
        for (int i = 0; i < abs(x); i++)
        {
            cout << 'W';
        }
    }

    return 0;
}