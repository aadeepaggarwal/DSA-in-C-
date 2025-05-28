#include <iostream>
using namespace std;
class Person{
    public:
    void operator() (){
        cout<<"Inside Functor Function + operator\n";
    }
};
int main() {
    Person P ;
    P();// now here object calls () as overloaded operator not the normal one
    
    return 0;
}