#include<iostream>
using namespace std;
int main() {
	int N;
	cin>> N;
	int i=2;
	int mult=1;
	while(N!=0){
		while(N%i==0){
			mult=mult*i;
			N=N/i;
		}
		
		i++;
	}
    cout<<mult;
	return 0;
}