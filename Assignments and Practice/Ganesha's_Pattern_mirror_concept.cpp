// #include <iostream>
// using namespace std;
// int main()
// {
//     int N;
//     cin >> N;
//     // We will break the code in 5 parts

//     // 1. 1st Row with a star, N/2-1 spaces and N/2+1 stars
//     cout << '*';
//     int i = 1;
//     while (i <= N / 2 - 1)
//     {
//         cout << " ";
//         i++;
//     }
//     i = 1;
//     while (i <= N / 2 + 1)
//     {
//         cout << "*";
//         i++;
//     }
//     cout << '\n';

//     // 2. the star space star pattern N/2-1 times
//     i = 1;
//     while (i <= N / 2 - 1)
//     {
//         cout << '*';
//         int j = 1;
//         while (j < N / 2 - 1)
//         {
//             cout << " ";
//             j++;
//         }
//         cout << '*';
//         cout << '\n';
//         i++;
//     }

//     // 3. the middle row with N stars
//     i=1;
//     while(i<=N){
//         cout<<"*";
//         i++;
//     }
//     cout<<'\n';
//     // 4. the space star space star part

//     i = 1;
//     while (i <= N / 2 - 1)
//     {   
//         int j = 1;
//         while (j < N / 2 - 1)
//         {
//             cout << " ";
//             j++;
//         }
//         cout << '*';
//         j = 1;
//         while (j < N / 2 - 1)
//         {
//             cout << " ";
//             j++;
//         }
//         cout << '*';
//         cout << '\n';
//         i++;
//     }
//     // 5. the last row

    
//     i = 1;
//     while (i <= N / 2 + 1)
//     {
//         cout << "*";
//         i++;
//     }

//     i = 1;
//     while (i <= N / 2 - 1)
//     {
//         cout << " ";
//         i++;
//     }

//     cout << '*';

//     cout << '\n';


//     return 0;
// }
#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    // We will break the code in 5 parts

    // 1. 1st Row with a star, N/2-1 spaces and N/2+1 stars
    cout << '*';
    int i = 1;
    while (i <= N / 2 - 1)
    {
        cout << " ";
        i++;
    }
    i = 1;
    while (i <= N / 2 + 1)
    {
        cout << "*";
        i++;
    }
    cout << '\n';

    // 2. the star space star pattern N/2-1 times
    i = 1;
    while (i <= N / 2 - 1)
    {
        cout << '*';
        int j = 1;
        while (j <= N / 2 - 1)
        {
            cout << " ";
            j++;
        }
        cout << '*';
        cout << '\n';
        i++;
    }

    // 3. the middle row with N stars
    i=1;
    while(i<=N){
        cout<<"*";
        i++;
    }
    cout<<'\n';
    // 4. the space star space star part

    i = 1;
    while (i <= N / 2 - 1)
    {   
        int j = 1;
        while (j <= N / 2 )
        {
            cout << " ";
            j++;
        }
        cout << '*';
        j = 1;
        while (j <= N / 2 - 1)
        {
            cout << " ";
            j++;
        }
        cout << '*';
        cout << '\n';
        i++;
    }
    // 5. the last row

    
    i = 1;
    while (i <= N / 2 + 1)
    {
        cout << "*";
        i++;
    }

    i = 1;
    while (i <= N / 2 - 1)
    {
        cout << " ";
        i++;
    }

    cout << '*';
    
    cout << '\n';


    return 0;
}
