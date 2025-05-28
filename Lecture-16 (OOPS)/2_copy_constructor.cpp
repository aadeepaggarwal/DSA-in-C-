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
    cout<<"Inside copy contructor";
    strcpy(name, X.name);
    price=X.price;
    model=X.model;
    seats=X.seats;
}
};


int main() {

   Car A;
   strcpy(A.name, "Maruti");
   A.price= 100;
   A.seats=7;
   A.model=1234;

Car B=A; // copy constructor way 1

Car C(A);
A.print();
B.print();
C.print();
    return 0;
}