#include <iostream>
using namespace std;
void print_array(int A[],int N){
    for (int i = 0; i < N; i++)
    {
       cout<<A[i]<<" ";
    }
    
}

void BubbleSort(int A[],int N){
     for (int i = 0; i < N - 1; i++) // run loop N-1 times
    {
        // to optimize my code more I can add a flag here so that the code stops once the array is sorted in between so that more time is not watsed in doing further calculations
        bool flag=1;
        for (int j = 0; j < N - i; j++) // N-i because last element har iteration ke bad sahi ho jayega
        {
            if (A[j] > A[j + 1])
            {
                // swapping the 2 numbers using temporary 3rd variable
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                flag=0;
            }
        }
        if(flag==1){
            break;// if flag was not changed means if loop above in 2nd for loop did not work even once hence all elements are in place and we need not go ahead
        }
    }

     cout << " Sorted array is: ";
    for (int i = 0; i < N; i++)
    {
        cout << A[i] << " ";
    }

}
int main() {
    int N;
    cout<<" Enter the size : ";
    cin>>N;
    int a[N];
    
for (int i = 0; i < N; i++)
    {
        cout<<"enter the value of "<< i<<"th index : ";
       cin>>a[i];
    }
    print_array(a,N);
    BubbleSort(a,N);

    return 0;
}