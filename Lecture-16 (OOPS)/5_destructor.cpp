#include <iostream>
#include <cstring>

using namespace std;

class Car{// this is class: Blueprint ek tarah se
public:
// data objects members
    char name[100];
    int price;
    int seats;
    int model;

Car(){
    cout<<"Inside default constructor"<<endl;
   }

void print(){
cout<< "Name : "<< name<<endl;
cout<< "Price : "<<price<<endl;
cout<< "Model : "<<model<<endl;
cout<< "Seats : "<<seats<<endl;


}
// copy constructor 
Car(Car &X){
    cout<<"Inside copy contructor"<<endl;
    strcpy(name, X.name);
    price=X.price;
    model=X.model;
    seats=X.seats;
}

// copy assignment operator
void operator=(Car X){
    cout<<"Inside copy assignment operator"<<endl;
    strcpy(name, X.name);
    price=X.price;
    model=X.model;
    seats=X.seats;// ab yaha ye X.price se argument mein jo gaya woh lega
    // and normal price ya seat jisne call kara woh lega
}
// operator overloading
bool operator>(Car &X/*call ek karega say E>A mein E ne call kara and A parameter yani X pe gaya*/){
    cout<<"Inside copy assignment operator"<<endl;
    if (/*ab ye deafult se E ka price hai*/price>X.price)
    {
        return true;
    }
    else return false;
    // or seedha likde ki return price>X.price
}

// ab yaha destructor ko bla denge
~Car(){
    cout<<"khatam karo ab "<<name<<endl;
   }
};


int main() {

   Car A;
   strcpy(A.name, "Maruti");
   A.price= 100;
   A.seats=7;
   A.model=1234;

Car B=A; // copy constructor way 1

//Car C(A);

Car D;
D=A;
// A.print();
// B.print();
// C.print();
Car E;// its destructor will cause garbage value name because we did not assign it
if(E>A){
    cout<<"E bada hai A se"<<endl;
}
else cout<<" E chhota hai"<<endl;
D.print();
    return 0;
}