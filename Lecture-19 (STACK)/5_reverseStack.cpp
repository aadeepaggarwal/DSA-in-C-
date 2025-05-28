#include <iostream>
#include <stack>
using namespace std;
void pushbottom(stack<int> &s, int TopElement ){
    // base case
    if (s.empty())
    {
        s.push(TopElement);
        return;
    }
    
    // recursive case
    int top=s.top();
    s.pop();/* yaha hamne kya kara ki reverse karna hai push bottom mein to abhi top wale ko temp mein store karle filhal*/

    // ab upar ja aur dekh ki kahin empty hai to nahi
    // agar empty hua to top element ko push karde and wapas neeche aake temp wale ko push karde
    pushbottom(s, TopElement);
    s.push(top);
}
void reverse_stack(stack<int> &s){
    // base case
    if (s.empty())
    {
        return;
    }
    
    // recursive case
    int TopElement=s.top();
    s.pop();
    reverse_stack(s);
    // reverse karne ke baad now we call push bottm 
    pushbottom(s,TopElement);
}
void print(stack <int>s){
    while (!s.empty())
    {
        cout<< s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
int main() {
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    print(s);
    reverse_stack(s);
    print(s);
    return 0;
}