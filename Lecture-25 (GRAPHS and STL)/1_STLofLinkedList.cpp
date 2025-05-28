#include <iostream>
#include<list>
using namespace std;
int main() {
    list<int> l;// STL usage 

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_front(5);

//FOR EACH
// for every data d that belongs to linked list 
for(auto d: l){
    cout<<d<<"-->";
}
    cout<<"NULL"<<endl;
// iterator
list<int>:: iterator it;// general syntax to make the iterator
for (it=l.begin(); it!=l.end(); it++/*this++ is not +1 it is current=current+size*/)// overloaded the operator in a way(operator overloading)
{
    cout<<*it<<"-->";
}
cout<<"NULL\n";
list<int>:: reverse_iterator it2;// general syntax to make the reverse iterator(yani ulta print)
for (it2=l.rbegin(); it2!=l.rend(); it2++)
{// end=rbegin, begin=rend
    cout<<*it2<<"-->";
}
cout<<"NULL\n";

    return 0;
}