#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void solve(vector<string>&arr ,int i , int n){
	if(n < 0){
		return ;
	}
	int savei = i;
	int newsave = i;
	int count = 0;
	while(savei>0){
		savei = savei/10;
		count++;
	}
	char ch[count];
	int index = 0;
	if(newsave ==0){
		ch[0] = '0';
	}
	while(newsave>0){
		ch[index] = newsave%10 -'0';
		index++;
		newsave = newsave/10;
	}
	arr.push_back(ch);
	solve(arr,i+1 , n-1);

}
int main() {
	int n;
	cin >> n;
	int i = 0;
	vector<string>arr;
	solve(arr,i,n);
	sort(arr.begin() , arr.end());
	for(auto ch : arr){
		cout << ch << " ";
	}
	
	return 0;
}