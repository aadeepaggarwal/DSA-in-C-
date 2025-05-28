#include <iostream>
using namespace std;
int main()
{
    int a[] = {
        1,1,0,0,0,1,1,1,1,0,0,0,1,
    };
    int n = sizeof(a) / sizeof(int);
    // mera tareeka
    int total = 0;
    int i = 0;
    while (i < n)
    {
        int curr = 0, prev = 0;
        int start = a[i];
        if (start == 0)
        {
            do
            {
                prev++;
                i++;
            } while (a[i] == 0 and a[i + 1] != 1);
        }
        else
        do
        {
            curr++;
            i++;
        } while (a[i] == 1 and a[i + 1] != 0);
        if (curr < prev)
        {
            total = total + curr;
        }
        else
            total += prev;

        if (start == 0)
        {
            i = i - curr;
        }
        else
            i = i - prev;
    }
    cout << total << '\n';

    // sir ka tareeka

    int prev = 0, curr = 1, substring = 0;
    // ham pehle 1st index pe currebt ko rakhenge considering 0th wala count karke current is 1
    // agar curr == uske pehle wala so curr++ kardo
    // nahi to curr ki value prev mein dalde aur min of curr and prev ko add in total
    // means 1100 hai to 2nd a[1] pe curr aya dekha same as prev to ++
    // ab a[2] is not same to ab prev ko=2 kardo yani curr ke barabar and curr ab 0s count karega
    for(int i=1;i<n;i++){
        if(a[i-1]==a[i]){
            curr++;
        }
        else{
            substring+=min(prev,curr);
            prev=curr;
            curr=1;
        }
        
    }
    substring+=min(prev,curr);
    cout<<substring;

    return 0;
}