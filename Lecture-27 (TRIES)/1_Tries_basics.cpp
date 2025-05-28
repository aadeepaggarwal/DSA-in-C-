#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

class node{
    public:
    char ch;
    unordered_map<char, node*> h;// har node pe ek to uska wala aplphabet agay aur dusra ayega ek hashmap jo ussey aage possible combination ke next words store karenge
    bool isEND;
    node(char c){
        ch=c;
        isEND=false;// by default false hai 
    }
    
};
class Tries{
    public:
    node* root;
    Tries(){
        root=new node('\0');

    }
    void addWord(string s){
        node* temp=root;
        for(int i=0;i<s.size();i++){
            char x=s[i];
            if(temp->h.count(x)==0){
                node *t=new node(x);// make the new node
                temp->h[x]=t;// add new node in hash map of temp wali node
            }
            temp=temp->h[x];// update temp to the next node jaha bhi jana hai in both the vases jaha exist karta tha ya nahi bhi karta tha agar
        }
        temp->isEND=true;// for loop ke bahar word ka end agaya hai so ab yaha pe mark is End true
    }

    bool searchWord(const string &s){
        node* temp=root;

        for(int i=0;i<s.size();i++){
            char x=s[i];
            if(temp->h.count(x)==0){
                return false;// matlab ek bhi word match nahi kara
            }
            // agar id fail yani next wala check kaarwao
            temp=temp->h[x];
        }
        return temp->isEND;// yani agar waha word end hota hai to isend true hoga so return true agar nahi end karta to aage badhte raho
    }
};
int main() {

    Tries t;
    t.addWord("Hello");
    t.addWord("He");
    t.addWord("Bat");
    t.addWord("Bam");

    while(1){// we do while true taaki ye ruke na we can keep on doing it
        char word[100];
        cin>>word;
        if(t.searchWord(word)){
            cout<<"Present\n";
        }
        else cout<<"Not Present\n";
    }
    return 0;
}