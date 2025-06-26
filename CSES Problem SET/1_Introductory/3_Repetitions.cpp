#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
    string dna;
    cin>>dna;
    int curr=1, ans=1;
    for(int i=1;i<dna.length();i++){
        if(dna[i]==dna[i-1]){
            curr++;

        }
        else{
            ans=max(curr,ans);
            curr=1;
        }
    }
    ans=max(curr,ans);
    cout<<ans;

    return 0;
}