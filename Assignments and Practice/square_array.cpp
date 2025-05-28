#include <iostream>
using namespace std;

void square(int A[],int N){
    for(int i=0; i<N;i++){
        A[i]=A[i]*A[i];
    }
}
void print_array(int A[], int N){
    for(int i=0; i<N;i++){
        cout<<A[i]<<" ";
    }
}
void sorted(int A[],int N){
    for(int i=0; i <N-1; i++){
        bool flag=1;
        for(int j=0; j<N-i; j++){

            if(A[j]>A[j+1]){
                swap(A[j],A[j+1]);
                flag=0;
                }
        }
        if(flag==1){
            break;
        }
     }
     
}
int main() {
    int N;
    cin>>N;
    int A[N];
    for(int i=0; i<N;i++){
        cin>>A[i];
    }

square(A,N);
sorted(A,N);
print_array(A,N);

return 0;

}
