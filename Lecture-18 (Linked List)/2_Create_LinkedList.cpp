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
void insertAtFront(node *&head, node *&tail, int data)
{                             // node* type ki bucket hai and & for call by reference
    node *n = new node(data); // dono case mein aata bas ab neeche case check karle
    if (head == NULL)
    {
        head = tail = n;
    }
    else
    {
        n->next = head;
        head = n;
    }
}
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
int lengthLL(node *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}
void insertMiddle(node *&head, node *&tail, int pos, int data)
{ // node* type ki bucket hai and & for call by reference
    // agar shuruat wala hi kehdia
    if (pos == 0)
    {
        insertAtFront(head, tail, data);
    }
    // agar end wala kehdia middle ke zariye
    else if (pos >= lengthLL(head))
    {
        insertAtend(head, tail, data);
    }

    else
    {
        node *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        node *n = new node(data);
        n->next = temp->next;
        temp->next = n;
    }
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


void delete_at_front(node *&head, node *&tail)
{
    if (!head)
    {
        return;
    }
    else if (!head->next) // agar ek hi element hai

    {
        delete head;
        head = tail = NULL;
    }

    else
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
}
void delete_at_end(node *&head, node *&tail)
{
    if (!head)
    {
        return;
    }
    else if (!head->next) // agar ek hi element hai

    {
        delete head;
        head = tail = NULL;
    }

    else
    {
        node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        delete tail;       // tail wali value uda do
        tail = temp;       // ab tail ko temp karwado
        tail->next = NULL; // ab tail ka next NULL pe point karwado
    }
}

void DeleteMiddle(node *&head, node *&tail, int pos)
{ // node* type ki bucket hai and & for call by reference
    // agar shuruat wala hi kehdia
    if (pos == 0)
    {
        delete_at_front(head, tail);
    }
    // agar end wala kehdia middle ke zariye
    else if (pos >= lengthLL(head)-1/*zero based indexing so len-1 ya uske upar koi pos daala to last wala hi uda do*/)
    {
        delete_at_end(head, tail);
    }

    else
    {
        node *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
          
        }
        
        node* n=temp->next;// yaha n ko temp ke next pe dalde
        temp->next=n->next;

        delete n;
    }
}
int main()
{
    node *head = NULL, *tail = NULL; // making two pointers right now
    insertAtFront(head, tail, 1);
    insertAtFront(head, tail, 2);
    insertAtFront(head, tail, 3);
    insertAtFront(head, tail, 4); // yaha 4 3 2 1 order hai kyonki front pe insert ho raha hai sab
    insertMiddle(head, tail, 2, 8);
    printLL(head);
    cout << endl
         << "length of linked list is : " << lengthLL(head);
    cout << endl;
    node *head2 = NULL, *tail2 = NULL;
    insertAtend(head2, tail2, 1);
    insertAtend(head2, tail2, 2);
    insertAtend(head2, tail2, 3);
    insertAtend(head2, tail2, 4);
    printLL(head2);
    cout << endl
         << "length of linked list is : " << lengthLL(head2);

    DeleteMiddle(head,tail,3);
    cout<<endl<<"after deletion from LinkedList 1 : \n ";
    printLL(head);
    return 0;
}