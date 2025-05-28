#include <iostream>
using namespace std;
class node
{

public:
    string key;
    int data;
    node *next;

    node(string s, int d)
    {
        key = s;
        data = d;
        next = NULL;
    }
};

class hashmap
{
private:
    int hashfunction(const string &key)
    {
        int ans = 0;
        int mul = 1;
        for (int i = 0; i < key.size(); i++)
        {// ye step hai woh string se key nikalne wala ascii leke
            ans += ((mul % ts) * (key[i] % ts /*yaha bhi mod karne pe farak nahi pad raha*/)) % ts;
            mul *= 37; // apna c=37
            mul %= ts;
            ans %= ts;
        }
        return (ans % ts);
    }

    void rehashing()
    {
        node **olda = a;
        int oldts = ts; // yaha pehle we made a copy of current data in a pointer
                        // now allot new memory
        a = new node *[2 * ts];
        ts *= 2;
        // mark sare nodes as null pehle
        for (int i = 0; i < ts; i++)
        {
            a[i] = NULL;
        }
        cs = 0;
        // ab copy old data bari bari as per their new value
        for (int i = 0; i < oldts; i++)
        {
            node *head = olda[i]; // store 0th index ka address and uski sari nodes pe traverse karenge
            while (head)
            {
                string key = head->key; // store key mein abhi wale hea dki key
                int data = head->data;
                // call insert in new a ka alloted data
                insert(key, data);
                node *temp = head;
                head = head->next;
                delete temp;
            }
        }
        delete[] olda;
    }

public:
    node **a; // store address of address
    int ts;   // table size
    int cs;   // current size if it reaches near ts so double ts

    hashmap(int s = 7)
    {
        a = new node *[s] /*ye har bucket mein NULL daaldega yani abhi sabka address null hai*/;
        for (int i = 0; i < s; i++)
        {
            a[i] = NULL;
        }

        ts = s;
        cs = 0;
    }

    void insert(const string &key, int data)
    {// yaha pe pehle hash index yani key nikao
        int hash_index = hashfunction(key);
        node *n = new node(key, data);// make the new node
        n->next = a[hash_index];// ab nayi node ka next point at 1st node's address at 
        //that place and then aage main list mein store address of n 
        //taki append o(1) mein ho jaaye 
        a[hash_index] = n;
        cs++;
    // ye 0.6 se agar zyada tha to rehashing karne wala hai
        float load_factor = cs / (ts * 1.0);
        if (load_factor >= 0.6)
        {
            rehashing();
        }
    }
    void print()
    {
        for (int i = 0; i < ts; i++)
        {
            node *head = a[i];
            cout << i << "-->";
            while (head)
            {
                cout << "(" << head->key << "," << head->data << ")";
                head = head->next;
            }
            cout << endl;
        }
    }
    node* search (string &key){
        int hash_idx=hashfunction(key);
        node*head=a[hash_idx];
        while(head){
            if (head->key==key)
            {
                return head;
            }
            head=head->next;
            
        }
        return NULL;
    }
   int&/*ye & yaha by reference return karwayega iss bar taaki neeche se ham iss value pe insert kara sake*/operator[](string key){
        node* ans=search(key);
        if (ans==NULL)
        {
            // present nahi hogi key
            int randomval;
            insert(key,randomval);
            ans=search(key);
            return ans->data;
        }
        else{
            //present hogi key
            return ans->data;// sirf print karne ke liye
            // same yaha delete bhi kar sakte hain uska function alag banega prev curr 2 pointer lele prev ka next curr ka next karke curr ko delete karde
        }
        
   } 
};
int main()
{
    hashmap h;
    h.insert("Mango", 100);
    h.insert("Apple", 150);
    h.insert("Kiwi", 50);
    h.insert("Pineapple", 800);
    h.insert("Guava", 70);

   

    // insertion
    h["Apple"]=50;

    //print
    cout<<h["Apple"]<<endl;

    // update
    h["Apple"]=140;

    h.print();
    return 0;
}