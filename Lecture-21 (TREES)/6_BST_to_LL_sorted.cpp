#include <iostream>
#include <queue>
using namespace std;
class node{
public:
    int data;
    node* left;
    node* right;
node(int d){
    data=d;
    left=NULL;
    right=NULL;
}
};
node* insertInBST(node*root, int d) {
	// base case
	if (!root) {
		root = new node(d);
		return root;
	}

	// recursive case
	if (root->data >= d) {
		root->left = insertInBST(root->left, d);
	}
	else {
		root->right = insertInBST(root->right, d);
	}
	return root;
}

node* buildBST() {
	node* root = NULL;
	int data;
	cin >> data;

	while (data != -1) {
		root = insertInBST(root, data);
		cin >> data;
	}
	return root;
}

int height(node* root){
    if (!root)
    {
        return 0;
    }
    return max((height(root->left)),(height(root->right)))+1;
    
}

class LinkedList{
    public:
    node* head, *tail;
};

LinkedList BstToLL(node* root){
    // base case
    if(!root){
        return {NULL,NULL};
    }

    // recusrive case
    if (root->left and root->right)
    {
       LinkedList left= BstToLL(root->left);
       LinkedList right= BstToLL(root->right);
       // yaha ab automatically class ke objects ban gaye hain left aur right
        left.tail->right=root;
        root->right=right.head;
        return{left.head, right.tail};
    }
    else if(!root->left and root->right){
        LinkedList right =BstToLL(root->right);
        root->right= right.head;
        return {root,right.tail};
    }
    else if(root->left and !root->right){
        LinkedList left =BstToLL(root->left);
        left.tail->right=root;
        return {left.head,root};
    }
    else return {root,root};
}

void printLL(node*root){
    while(root){
        cout<<root->data<<" -> ";
        root=root->right;
    }
}

int main() {
node* root= buildBST();
LinkedList L=BstToLL(root);
printLL(L.head);

    return 0;
}