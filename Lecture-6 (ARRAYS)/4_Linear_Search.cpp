#include <iostream>
using namespace std;
int main() {
    int A[]={1,4,2,13,8,9};
    int key;
    cout<<"Enter the value of the key :";
    cin>>key;
    bool keyFound=0;
    int i, N=sizeof(A)/sizeof(int);
    for ( i = 0; i < N; i++)
    {
        // if we get i== N when we go out of the loop means 0 to N-1 mein we did not get the key hence print not found
        if(key==A[i]){
            cout<<"Key found at the index :"<<i;
            keyFound=1;
           // break;// removing break will cause us to print all the occurences of the key if multiple 
            // and now to check if key found or not we can take a bool variable which will turn true if we find the key else bool is false
            // and if bool is false when we come outisde the loop then we print key not found
        }

    }
    
    if(keyFound==0){// i==N use this if one occurence/1st occurence checking
        cout<<"Key Not Found";
    }
    return 0;
}