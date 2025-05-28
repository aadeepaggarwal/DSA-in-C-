#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int row=1;
	while(row<=(n+1)/2){
		//LOOP FOR BLANKSPACES
		int i=1;
		while(i<=n+1-row*2){
			cout<<"  ";
			i=i+1;
		}
		i=row;
		while(i>=1){
			cout<<i<<" ";
			i--;
		}
		i=1;
		while(i<=2*row-3 &&row!=1){
			cout<<"  ";
			i=i+1;
		}
		i=1;
		while(i<=row &&row!=1){
			cout<<i<<" ";
			i=i+1;
		}
		cout<<"\n";
		row=row+1;
	}
	// LOOP FOR BLANK SPACES
	row=1;
	while(row<(n+1)/2){
		int i=1;
		while(i<=2*row){
			cout<<"  ";
			i=i+1;
		}
		i=((n+1)/2) -row;
		while(i>=1){
			cout<<i<<" ";
			i--;
		}
		i=1;		
		while(i<=(n/2)-row*2+2 &&row!=n/2){
			cout<<"  ";
			i=i+1;
			
		}
		i=1;
		while(i<=(n+1)/2-row &&row!=n/2){
			cout<<i<<" ";
			i=i+1;
		}
		cout<<'\n';
		row=row+1;
	}

	return 0;
}