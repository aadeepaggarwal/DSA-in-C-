#include <iostream>
using namespace std;
class node{
    public:
    int no;
    node* left, *right;
    node(int x): no(x){
        left=right=NULL;
    }
};
void insertInteger(node* root, int n){
    for(int i=30;i>=0;i--){// this is to check kaunsi bit hai because and it with 1 to check woh bit 1 hai ya 0
    if((n & (1<<i))==0){
        if(root->left ==NULL) root->left= new node(0);// agar bit 0 thi to left wala check kar exist karta hai to move to it warna just create it and move on it
        root=root->left;
    }
    else{
        if(root->right== NULL) root->right= new node(1);// same agar bit 1 thi to right pe do like we did on left
        root=root->right;
    }
}
root->no=n;// at the end of the number store it in the last bit taki exor kar sake findmax karte wakt
}

int FindMaxXOR(node* root, int no){
    int ans;// to store the answer
    for(int i=30;i>=0;i--){
        int bit= no & (1<<i);
        if(bit){// if bit==1 then we need 0 so that exor 0^1=1 and 0 pe we need 1 so find that if exists so move to that else jo hai uspe move karjao 
            if(root->left) root=root->left;
            else root=root->right;
        }
        else {
            if(root->right) root=root->right;
            else root=root->left;
        }
    }
    return no^(root->no);// jab end mein 32 bits cover ho gayi kyonki 32 bits milengi hi milnegi to jo number present hai ussey exor karke max wala ans mein store karlo
}
int main() {
    int a[]={3,5,2,1,4};
    int n=sizeof(a)/ sizeof(int);
    node* root = new node(-1);
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		insertInteger(root, a[i]);// insert an integer in tries
		int x = FindMaxXOR(root, a[i]);// find max using present tries
		ans = max(ans, x);// update ans if needed
	}
	cout << ans << endl;

/////// normal way n^2 Tim complexity wala

	/*
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				ans = max(a[i] ^ a[j], ans);
			}
		}
		cout << ans << endl;
	*/


    return 0;
}