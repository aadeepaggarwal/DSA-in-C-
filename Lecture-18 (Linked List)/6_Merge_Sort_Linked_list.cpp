#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    // default constructor

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
node *FindMiddle(node *&head)
{

    if (!head || !head->next)
    {
        return head;
    }
    node *f = head->next, *s = head;
    while (f and f->next)
    {
        f = f->next->next;
        s = s->next;
    }
    return s;
}
node *merge(node *a, node *b)
{
    // base case
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }

    // recursive call
    node *nh = NULL;
    if (a->data < b->data)
    {
        nh = a;
        nh->next = merge(a->next, b);
    }
    else
    {
        nh = b;
        nh->next = merge(a, b->next);
    }
    return nh;
}
node *mergesort(node *&head)
{
    // base case
    if (!head || !head->next)
    {
        return head;
    }

    // recursive
    // 1. Divide
    //  make 2 other linked list a and b aur mid ka ek pointer
    node *m = FindMiddle(head);
    node *a = head;
    node *b = m->next;
    m->next = NULL;// taki do mein divide kar paayen Linked List ko
    // 2. Sort
    a = mergesort(a);
    b = mergesort(b);
    // 3. Merge
    node *nh = merge(a, b);
    return nh;
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
int main()
{
    node *head = NULL, *tail = NULL;

    insertAtend(head, tail, 4);
    insertAtend(head, tail, 3);
    insertAtend(head, tail, 1);
    insertAtend(head, tail, 7);
    insertAtend(head, tail, 2);
    insertAtend(head, tail, 8);

    printLL(head);
    cout << endl;

    printLL(mergesort(head));

    return 0;
}