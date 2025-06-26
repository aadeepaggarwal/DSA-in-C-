#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    while(n--){
        long long x,y;
        cin>>x>>y;
        long long mx=max(x,y);
        long long mn=min(x,y);
        if(mx%2==0 and mx==x){
            cout<<mx*mx -mn +1<< endl;
        }
        else if(mx%2==1 and mx==x){
            cout<<(mx-1)*(mx-1 )+1+ mn -1<< endl;
        }
        else if(mx%2==0 and mx==y){
            cout<<(mx-1)*(mx-1 )+1+ mn -1<< endl;
        }
        else cout<<mx*mx -mn +1<< endl;
    }
    return 0;
}