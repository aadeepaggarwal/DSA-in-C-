#include <iostream>
using namespace std;
int main() {

//     //asume the given number to be  a perfect square
//     int N;
//     cin>>N;

//     float ans=0;
//     while(ans*ans<=N){
//         ans++;
//     }
//     ans--;
//    // cout<<ans<<endl;

//     // what if the number is not a perfect square, then in that case we will get the integral part if we use the above code, like for 10 we get 3 point something typecasted as 3.
//     // let us try to find for non perfect square upto 2 decimal places thus precision P=2
//     // thus first find the integer using the above code then iterate for +0.1 to get 1st decimal place in the same manner as above and get 1st decimal place
    
//     // float j= ans;// convert integer output of step to float type
//     // while(j*j<=N){
//     //     j=j+0.1;
//     // }
//     // j=j-0.1;
//     // so on do for 0.01 
// // let us take a loop for precision part
//     int P;
//     cin>>P;
//     int CP=1;
//     float inc=0.1;
//     while(CP<=P){
//         while(ans*ans<=N){
//             ans=ans+inc;
//         }
//         ans=ans-inc;
//         inc=inc/10;
//         CP++;
//     }
//     cout<<ans;

// another way of a common loop from beginning for N2
int P2;
    int N2;
    cin>>N2;
    cin>>P2;
    int CP2=0;
    float inc2=1;
    float ans=1;
    while(CP2<=P2){
        while(ans*ans<=N2){
            ans=ans+inc2;
        }
        ans=ans-inc2;
        inc2=inc2/10;
        CP2++;
    }
    cout<<ans;

    return 0;
}