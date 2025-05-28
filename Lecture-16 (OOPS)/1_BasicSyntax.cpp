#include <iostream>
#include<cstring>
using namespace std;
/////////////////////////////////  CLASS    ////////////////////////////
class Car{// this is class: Blueprint ek tarah se
public:
// data objects members
    char name[100];
    int price;
    int seats;
    int model;

///////////////////////// Constructor function-> it has no return type/////////////////////////////

// Default constructor
Car(){
    cout<<"Inside default constructor"<<endl;
   }
// parameterized constructor
Car(char*a/*yaha passing a pointer neeche warning ayegi value pass karte hue*/, int p, int n, int m){

    cout<<"Inside parametrized constructor"<<endl;
    strcpy(name,a );
    price=p;
    seats=n;
    model=m;
}

// can have multiple parameterized constructors bas usme parameters change karde
        // eg. maruti ki har gaadi has 5 seats so...
Car(char*a, int p,int m/*yaha ek argument kam daala seats ka*/){

    cout<<"Inside another parametrized constructor maruti wala"<<endl;
    strcpy(name,a );
    price=p;
    seats=5;// maruti ki 5 seat bula di neeche call karte hue jab call karenge to 3 pass karengebas
    model=m;
}
// can even add functions here
void print(){
cout<< "Name : "<< name<<endl;
cout<< "Price : "<<price<<endl;
cout<< "Model : "<<model<<endl;
cout<< "Seats : "<<seats<<endl;


}

}/* A, B,C  aise karke yaha bhi objects assign kar sakte hain*/;

int main() {
    Car A;
    // A.name=" MARUTI"// wrong way because strcpy hoga ye kaam initialze karte hue chalta hai yaha nahi
   strcpy(A.name, "Maruti");
   A.price= 100;
   A.seats=7;
   A.model=1234;
// making new object now
   Car B;// automatically calls the constructor function too
   strcpy(B.name, "Honda");
   B.price= 107;
   B.seats=4;
   B.model=129994;


// output cout se

cout<< "Name : "<< A.name<<endl;
cout<< "Price : "<< A.price<<endl;
cout<< "Model : "<< A.model<<endl;
cout<< "Seats : "<< A.seats<<endl;

cout<< "Name : "<< B.name<<endl;
cout<< "Price : "<< B.price<<endl;
cout<< "Model : "<< B.model<<endl;
cout<< "Seats : "<< B.seats<<endl;

// access function for an object
cout<<"Access by function of Class"<<endl;
A.print();
cout<<'\n';
B.print();

// parameter wale se  input

Car C("BMW",700,7,20204);
C.print();

Car D("Maruti",700,20204);// yaha warning ayegi kyonki bmw name we pass in pointer array ke naam pe jaha address jana tha waha value bhej rahe hain
D.print();

    return 0;
}