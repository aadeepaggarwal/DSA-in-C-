// #include <iostream>
// using namespace std;
// int ratio(int percent)
// {
//     int steps = 1, i = 1, j = 0;
//     while (percent != (i / (i + j)) * 100)
//     {
//         if (percent > (i / (i + j)) * 100)
//         {
//             i++;
//             steps++;
//         }
//         else
//         {
//             j++;
//             steps++;
//         }
//     }

//     return steps;
// }
#include<iostream>
#include<cmath>
using namespace std;
int solve(int k){
    int deno = 100;
    for(int i = k; i>=2 ;){
        if((k%i==0) && (deno%i==0)){
            k = k/i;
            deno = deno / i;
            if(k==1){
                return deno;
            }

        }
        else{
            i++;
        }

    }
    return deno;
}

int main(){
    int t;
    cin>>t;
    for(int i =0 ; i<t ; i++){
        int k;
        cin>>k;
        int val = solve(k);
        cout<<val<<endl;
    }

}