#include <iostream>
using namespace std;
void Merge(int *a,int *b,int *c,int s,int e){
    int mid=(s+e)/2;
    int i=s,j=mid+1,k=s;
    while (i<=mid and j<=e)
    {
        if (b[i]<c[j])
        {
            a[k++]=b[i++];
        }
        else a[k++]=c[j++]; 
    }
    // copy the leftover elements from ba nd c to a if left
    while (i<=mid)
    {
        a[k++]=b[i++];
    }
    while (j<=e)
    {
        a[k++]=c[j++];
    }
    

}

void MergeSort(int *a,int s, int e){
    // base case
    if(s>=e){
        return;
    }
    //recurrence relation
    // 1. divide karo a[] ko b[] and c[] mein
    int mid=(s+e)/2;
    int b[10000], c[10000];
    for (int i = s; i <=mid; i++)
    {
        b[i]=a[i];
    }
    for (int i =mid+1; i <=e; i++)
    {
        c[i]=a[i];// c mein 0 se nahi mid+1 se store hoga, initial 0 se mid tak garbage values
    }
    // 2. sorting kara b[] and c[] pe
    // b ko kar s to mid
    MergeSort(b,s,mid);
    // c ko sort karo
    MergeSort(c,mid+1,e);

    // 3. merge it ab
    Merge(a,b,c,s,e);
    
}
int main() {

    int n;
    cout<<"enter the size :";
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"enter the value of "<< i<<"th index : ";
        cin>>a[i];
    }
    
    MergeSort(a,0,n-1);
    for (int i = 0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
