#include <iostream>
using namespace std;
class node{
public:
    int data;
    node* next;
// constructor to pass value on creation
    node(int d)
    {
        data = d;
        next = NULL;
    }
};
void insertAtend(node *&b, node *&tail, int data)
{                             // node* type ki bucket hai and & for call by reference
    node *n = new node(data); // dono case mein aata bas ab neeche case check karle
    if (b == NULL)
    {
        b = tail = n;
    }
    else
    {
        tail->next = n;
        tail = n;
        // and n already deafult constructor se jab bana to null pe point karrha tha
    }
}


void printLL(node *b)
{
    while (b)
    {
        cout << b->data << "-->";
        b = b->next;
    }
    cout << "NULL"; // because last node points at NULL
}

node* merge(node* a, node*b){
// base case
if(a==NULL){
    return b;
}
if(b==NULL){
    return a;
}

//recursive call
node* nh=NULL;// nh means new head
if(a->data <b->data){
    nh=a;
    nh->next=merge(a->next,b);
}
else{
    nh=b;
    nh->next=merge(a,b->next);
}
return nh;
}
int main() {
    node *a = NULL, *tail2 = NULL;
    insertAtend(a, tail2, 1);
    insertAtend(a, tail2, 2);
    insertAtend(a, tail2, 7);
    insertAtend(a, tail2, 14);
    insertAtend(a, tail2, 46);
    cout<<"LIST 1 \n";
    printLL(a);
    cout<<endl;

    node *b = NULL, *tail = NULL;
    insertAtend(b, tail, 3);
    insertAtend(b, tail, 5);
    insertAtend(b, tail, 13);
    insertAtend(b, tail, 40);
    cout<<"LIST 2 \n";
    printLL(b);
    cout<<endl;
    cout<<"LIST MERGED \n";
    printLL(merge(a,b));
    
    return 0;
}