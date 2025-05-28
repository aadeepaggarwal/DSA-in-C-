#include <iostream>
#include<cstring>
#include<vector>
using namespace std;
int lcs_front(char*a, char*b,int i, int j){
    // base case
    if (a[i]=='\0' || b[j]=='\0')// or write !a[i] || !b[j]
    {
       return 0;
    }
    
    // recursive case
    if(a[i]==b[j]) return 1+ lcs_front(a,b,i+1,j+1);

    else {
        return max(
            lcs_front(a,b,i+1,j),lcs_front(a,b,i,j+1)
        );
    }
}
int lcs_back(char*a, char*b,int n, int m){
    // base case
    if (n<0 || m<0)
    {
       return 0;
    }
    
    // recursive case
    if(a[n-1]==b[m-1]) return 1+ lcs_back(a,b,n-1,m-1);

    else {
        return max(
            lcs_back(a,b,n-1,m),lcs_back(a,b,n,m-1)
        );
    }
}
int topdown(char*a,int n, char*b,int m, int dp[][100]){
    // base case
    if(n<=0 || m<=0){
        return dp[n][m]==0;
    }
    // recursive case
    if (dp[n][m]!= -1)
    {
        return dp[n][m];
    }
    if (a[n-1]==b[m-1])
    {
         return dp[n][m]=1+ topdown(a,n-1,b,m-1,dp);
    }
    else {
        return dp[n][m]=max(
            topdown(a,n-1,b,m,dp),topdown(a,n,b,m-1,dp)
        );
    }
    
    
}
int bottomup(char *a, char*b){
    int n=strlen(a);
    int m=strlen(b);
    int dp[100][100]={0};
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=m ; j++)
        {
            if (a[i-1]==b[j-1])
            {
                dp[i][j]=1+ dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);// means dekho ki dono strings mein se ek ek element karke jo se hai usmein se max kaha se lcs aa raha hai
            }
        }
        
    }
    // for (int i = 0; i <= strlen(a); i++)
    // {
    //     for (int j = 0; j <= strlen(b); j++)
    //     {
    //        dp[i][j]!=-1? cout<<dp[i][j]<<" ": cout<<" ";
    //     }
    //     cout<<endl;
    // }
   return dp[n][m];
}
void LCSPrint1(int dp[][100],int n,int m,char *a,char*b){
     int i = n, j = m;
    vector<char> list;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            list.push_back(a[i - 1]);
            i--;
            j--;// agar last n m wala matches to store it and diagonally move back
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;  // Move up in the table
        } else {
            j--;  // Move left in the table
        }
    }

    // The LCS is stored in reverse order, so print it in correct order
    cout << "LCS: ";
    for (int k = list.size() - 1; k >= 0; k--) {
        cout << list[k];
    }
    cout << endl;
}
void findLCS(int dp[][100], int n, int m, char* ans, int i, char*a, char *b) {
	// base case
	if (i == -1) {
		cout << ans << endl;
		return;
	}
	// recursive case
	if (a[n - 1] == b[m - 1]) {
		ans[i] = a[n - 1];
		findLCS(dp, n - 1, m - 1, ans, i - 1, a, b);
	}
	else {
		if (dp[n - 1][m] == dp[n][m - 1]) {
			findLCS(dp, n - 1, m, ans, i, a, b);
			findLCS(dp, n, m - 1, ans, i, a, b);
		}
		else if (dp[n - 1][m] > dp[n][m - 1]) findLCS(dp, n - 1, m, ans, i, a, b);
		else findLCS(dp, n, m - 1, ans, i, a, b);
	}
}
int main() {
    char a[]="abdb";
    char b[]="adb";
    int dp[100][100];
    memset(dp,-1,sizeof(dp));
    cout<<lcs_front(a,b,0,0)<<endl;
    cout<<lcs_back(a,b,strlen(a),strlen(b))<<endl;
    cout<<topdown(a,strlen(a),b,strlen(b),dp)<<endl;

    for (int i = 0; i <= strlen(a); i++)
    {
        for (int j = 0; j <= strlen(b); j++)
        {
           if(dp[i][j]==-1){
            cout<<"_ ";
           } 
           else cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<endl;
    cout<< bottomup(a,b)<<endl;

    LCSPrint1(dp,strlen(a),strlen(b),a,b);
    cout<<endl;

    int x = bottomup(a, b);
	cout << endl<< x << endl;

	char ans[1000];
	ans[x] = '\0';
	findLCS(dp, strlen(a), strlen(b), ans, x - 1, a, b);
    
}