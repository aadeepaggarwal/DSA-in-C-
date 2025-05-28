#include <iostream>
using namespace std;
int main() {
    int testcases;
    cin>>testcases;
    while(testcases){
    int n,temp,currtime=0;
    cin>>n>>temp;
    while(n){
        int enter,lo,ho;
        cin>>enter>>lo>>ho;
        if(lo>temp){
            if((lo-temp)<=enter-currtime){
                
                cout<<"YES"<<endl;

            }
            else cout<<"NO"<<endl;
        }
        else if(temp>ho){
            if((temp-ho)<=enter-currtime){
                cout<<"YES\n";
            }
            else cout<<"NO\n";
        }
        currtime=enter;

        n--;
    }

    testcases--;
    }

    return 0;
}