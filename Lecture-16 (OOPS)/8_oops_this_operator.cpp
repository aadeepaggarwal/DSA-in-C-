#include <iostream>
#include<cstring>
using namespace std;
class Car{
public:
char name[100];
int price;

Car(char name[100], int price){
    strcpy(this->name, name);// yaha name and name same variable name hai ab kaise pata kaunsa argument ka hai kaunsa call karne wale ka hai
     this->price=price;
}  
};
int main() {
    Car A("BMW",100);// ab A call karega bmw and 100 arguments mein jayenge
    return 0;
}