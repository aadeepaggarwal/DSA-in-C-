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
void insertAtend(node *&head, node *&tail, int data)
{                             // node* type ki bucket hai and & for call by reference
    node *n = new node(data); // dono case mein aata bas ab neeche case check karle
    if (head == NULL)
    {
        head = tail = n;
    }
    else
    {
        tail->next = n;
        tail = n;
        // and n already deafult constructor se jab bana to null pe point karrha tha
    }
}

void reverse(node* &head,node* &tail){
    node* c,*p,*n;
    c=head;
    p=NULL;
    while (c)
    {
       n=c->next;
       c->next=p;
       p=c;
       c=n;
    }
    swap(head, tail);// ye passed by reference tha
    
}
void printLL(node *head)
{
    while (head)
    {
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "NULL"; // because last node points at NULL
}
void BreakCycle(node* head, node*f){
    node *s=head;
    node* fp=head;
    while (fp->next != f)
    {
        fp=fp->next;
    }
    while (f !=s)
    {
        fp=f;
        f=f->next;
        s=s->next;
    }
    fp->next=NULL;// this breaks the cycle
    
}
bool detectcycle(node*head){
    node*f=head, *s=head;
    while (f and f->next)
    {
        f=f->next->next;
        s=s->next;
        if (f==s)
        {
            BreakCycle(head,f);
        return true;
        }
    }
    
    
    return false;// agar cycle na mile

}

int main() {
    node *head2 = NULL, *tail2 = NULL;
    insertAtend(head2, tail2, 1);
    insertAtend(head2, tail2, 2);
    insertAtend(head2, tail2, 3);
    insertAtend(head2, tail2, 4);
    insertAtend(head2, tail2, 5);
    insertAtend(head2, tail2, 6);
    insertAtend(head2, tail2, 7);
    insertAtend(head2, tail2, 8);
    printLL(head2);
    tail2->next=head2->next;
    if(detectcycle(head2)){
        cout<<"\n Yes \n";
    }
    else cout<<"\n No \n";
    
    
    return 0;
}