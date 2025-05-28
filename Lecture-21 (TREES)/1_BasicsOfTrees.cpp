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
node* BuildTree(){
    int data;
    cin>>data;
    if (data==-1)// basically jab -1 aaye toh matlab null hai
    {
       return NULL;
    }
    node* root=new node(data);
    root->left =BuildTree();
    root->right =BuildTree();
    return root;
}

// input to be given : 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1

void preorder(node* root){// preorder is N L R
    if(!root){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root){
    if(!root){
        return;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(node* root){
    if(!root){
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelorder(node* root){
    if(!root)  return;

    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
       node* x=q.front();
       q.pop();
       if (x!=NULL)
       {
        cout<<x->data<<" ";
        if(x->left) q.push(x->left);
        if(x->right) q.push(x->right);
       }
       else {
        cout<<endl;
        if(!q.empty()) q.push(NULL);
       }
    }
}
int countNodes(node *root){
    if (!root)
    {
        return 0;
    }
    // in a way it is post order because left->right->node
return countNodes(root->left)+ countNodes(root->right)+1/*for root node*/;
    
}
int height(node* root){
    if (!root)
    {
        return 0;
    }
    return max((height(root->left)),(height(root->right)))+1;
    
}

int diameter(node* root){
    if (! root)
    {
        return 0;
    }
    int op1, op2, op3;
    op1= height(root->right)+height(root->left);
    op2= diameter(root->left);
    op3=diameter(root->right);
    int m=max(op1,max(op2,op3));// as we cannot take 3 ka max at once
    return m;
    
}
class Pair{
public:
    int height;
    int diameter;

};
Pair fast_diameter(node* root){
    // base case
    if(!root) return {0,0};
    // recursive case
    Pair left=fast_diameter(root->left);
    Pair right=fast_diameter(root->right);// pehle hamne left and right subtree se har node ke pairs alutwa rahe hain

    Pair P;// pair ban ne wala step yaha shuru hota hai jaha Pair type ki bucket bana lo
    P.height=max(left.height, right.height)+1;// ye height wala normal function hai yaha copy ho gaya ye height alag hai iski naki upar wale function ki
    int op1,op2,op3;
    // again 3 option iss bar thode alag o(n) ke sath
    op1=left.height+ right.height;
    op2= left.diameter;
    op3= right.diameter;
    P.diameter=max(op1, max(op2,op3));
    return P;
}

node* Search(node *root, int key){
    // base case
    if(!root){
        return NULL;
    }
    // recursive case
    if (root->data==key)
    {
       return root;
    }
    node* leftkaans=Search(root->left, key);
    if(leftkaans){
         return leftkaans;
    }
    
    node* rightkaans=Search(root->left, key);
    if(rightkaans){
         return rightkaans;
    }
    return NULL/*agar mila hi nahi to null de*/;
}

void Mirror(node* root){
    // base case
    if(!root){
        return ;
    }
    // recursive case
    swap(root->left,root->right);// yaha swap se seedha node swap ho jayegi naki values because bucket node type ki thi
    Mirror(root->left);
    Mirror(root->right);
}
int main() {
node* root= BuildTree();

cout<<"Pre-order \n";
preorder(root);
cout<<endl;

cout<<"In-order \n";
inorder(root);
cout<<endl;

cout<<"Post-order \n";
postorder(root);
cout<<endl;

cout<<"Total nodes are: "<<countNodes(root);
cout<<endl;

cout<<"Height is: "<<height(root);
cout<<endl;

cout<<"Diameter via slower method is : "<<diameter(root);
cout<<endl;
Pair ans=fast_diameter(root);
cout<<"Faster diameter is: "<<ans.diameter<<endl;

node* temp=Search(root,8);
if (temp)
{
   cout<<temp->data<<" found at "<<temp<<endl;
}


cout<<"Before Mirror\n";
preorder(root);
cout<<endl;
Mirror(root);
cout<<"After Mirror : \n";
preorder(root);
cout<<endl;

cout<<"Level Order : \n";
levelorder(root);
    return 0;
}