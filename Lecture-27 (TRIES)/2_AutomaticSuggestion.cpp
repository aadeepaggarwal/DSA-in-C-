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
    void autoSuggestionHelper(node* root, string ans){
        ans.push_back(root->ch);// add ek to present wala alphabet in the ans bucket
        if(root->isEND) cout<<ans<<endl;// agar waha word end hota tha koi to print it

        for(auto p:root->h){
            autoSuggestionHelper(p.second, ans);// call the print wala  fucntion for other possibilities 
        }
        ans.pop_back();// backtracking because remove bhi to karenge na purana, naya word print karne se pehle
    }
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
    void autosuggestion( const string s){// this consists of ab tab jo likha in search bar woh
        // compare ab tak likha hua part 
        node* temp=root;

        for(int i=0;i<s.size();i++){
            char x=s[i];
            if(temp->h.count(x)==0){
                return ;
            }
            // agar if fail yani next wala check kaarwao
            temp=temp->h[x];
        }
        for(auto p: temp->h){
            autoSuggestionHelper(p.second, s);
        }
    }

   
};
int main() {

    Tries t;

	t.addWord("Hello");
	t.addWord("He");
	t.addWord("Hell");
	t.addWord("Hello World");
	t.addWord("Bat");
	t.addWord("Bam");

	t.autosuggestion("H");


    
    return 0;
}