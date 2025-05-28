#include <iostream>
using namespace std;
int main() {///// pair datatype - stores joda of value
    pair<string ,int> p;// or second way to initialize 
    // pair<string ,int> p({"Mango", 100});
    // 3rd way to initialize
    // pair<string ,int> p(make_pair("Mango",100));
    
    p.first="Mango";
    p.second=100;

    cout<<p.first<<", "<<p.second<<endl;
    return 0;
}