#include <iostream>
#include <queue>
#include <climits>
using namespace std;

class node {
public:
	int data;
	node* left, *right;
	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
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


void preOrder(node* root) {
	if (!root) return;

	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(node* root) {
	if (!root) return;

	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

void postOrder(node* root) {
	if (!root) return;

	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}

void levelOrder(node* root) {
	if (!root) return;

	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		node* x = q.front();
		q.pop();

		if (x) {
			cout << x->data << " ";
			if (x->left) q.push(x->left);
			if (x->right) q.push(x->right);
		}
		else {
			cout << endl;
			if (!q.empty()) q.push(NULL);
		}
	}
}

// Print  range
void printRange(node*root, int k1, int k2) {
	if (!root) return;

	printRange(root->left, k1, k2);
	if (root->data >= k1 and root->data <= k2)cout << root->data << " ";
	printRange(root->right, k1, k2);
}

// Search in BST
node* searchBST(node*root, int key) {
	if (!root) return NULL;

	if (root->data == key) return root;
	else if (root->data >= key) return searchBST(root->left, key);
	else return searchBST(root->right, key);
}

bool isBST(node*root, int mi = INT_MIN, int mx = INT_MAX) {
	if (!root) return  true;

	if (root->data >= mi and root->data <= mx
	        and isBST(root->left, mi, root->data)
	        and isBST(root->right, root->data, mx)) {
		return  true;
	}
	return false;
}

class Pair {
public:
	bool balanced;
	int height;
};

Pair isBalanced(node*root) {
	// base case
	if (!root) return{true, 0};

	// recursive case
	Pair left = isBalanced(root->left);
	Pair right = isBalanced(root->right);

	Pair p;
	p.height = max(left.height, right.height) + 1;
	if (left.balanced and right.balanced and
	        abs(left.height - right.height) <= 1) p.balanced = true;
	else p.balanced = false;

	return p;
}


int main() {
	// 8 3 10 1 6 14 4 7 13 9 -1
	node* root = buildBST();

	preOrder(root);
	cout << endl;
	inOrder(root);
	cout << endl;
	postOrder(root);
	cout << endl;
	// levelOrder(root);
	// printRange(root, 3, 10);
	Pair p = isBalanced(root);
	if (p.balanced) cout << "Balanced\n";
	else cout << "Not Balanced\n";

	cout << p.height << endl;


	return 0;
}