#include<iostream>
using namespace std;
// int rangesum(int *a,int l,int r){
// int sum=0;
// for(int i=l;i<=r;i++){
// 	sum+=a[i];
// }
// return sum;
// }
int solve(int *a,int l,int r,int *ps){
	//1.base case
	if(l>=r)return 0;
	//2.recursive case

	int indx=-1;
	for(int i=l;i<=r;i++){
		int sumleft=ps[i]-(l?ps[l-1]:0);// l-1 less than 0 nhi ho sakta

		int sumright=ps[r]-ps[i+1-1];
		if(sumleft==sumright){
			indx=i;
			break;
		}
	}
	if(indx==-1){// nhi mila koi index
	return 0;

	}
	return 1+max(solve(a,l,indx,ps),solve(a,indx+1,r,ps));

}
int main() {

	int t;
	cin>>t;

	while(t--){//post decrement 
	   int n;
		cin>>n;
		int *a=new int[n];
		// prefix sum banayenge idhar
        int *ps=new int[n];
        
		for(int i=0;i<n;i++){
          
			cin>>a[i];
              if(i==0)ps[i]=a[i];
              else ps[i]=ps[i-1]+a[i];
		}
		cout<<solve(a,0,n-1,ps)<<endl;
		delete[]a;// jab while loop waapis chalega toh memory leak na ho

	}
	return 0;
}