#include <iostream>
#include <cstring>
using namespace std;

void substring(char *ch)
{
    int n = strlen(ch);
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++) /* har bar j times ab print karenge
                                    jth element from ith element */
        {
            int k = i; // j baar print hai to k lrlo jo j times kaam karega
            while (k <= j)
            {
                cout << ch[k++];
            }
            cout << endl;
        }
        cout << '\n';
    }
}
int main()
{
    char ch[100];
    cin.getline(ch, 100);
    substring(ch);
    return 0;
}