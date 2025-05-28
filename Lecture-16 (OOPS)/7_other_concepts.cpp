#include <iostream>
#include <cstring>
using namespace std;

class Car
{
private:
int price;
public:
    char *name; // yaha name points at garabge right now
    
    int model;
    int seats;

    // default constructor
    Car()
    {
        name = NULL;// garbage point wale ko null pe point karwado
       cout<<"default constructor";
    }
    Car(char *x, int p)
    {
        name = new char[strlen(x) + 1]; // ab name garbage/null pe point kar raha hai so ab make new memory and make name point on it
        // size of this is len of char x and +1 for null
        strcpy(name, x); // made memory pe naam actually copy karne wala step
       set_price (100);
    }
    // copy assignment mein dma
    void operator=(Car X)
    {
        cout << "Inside Copy Assignment \n";
        if (name != NULL)
        { // jo name hai agar purani memory ko point karrha hai to delete it first

            delete[] name;
        }
        name = new char[strlen(X.name) + 1];
        strcpy(name, X.name);
        price = X.price;
    }
    void set_price(int p){ 
        
       price=p;
    }
~Car()
    {
       cout<<"default constructor \n";
       delete []name;
    }
};
int main()
{
    // to avoid str pe naam wala error make an araay and pass that
    // eg. char ch[100]="bmw";
    // pass ch in parameterized constructor naaki "bmw seedha"
    Car A("BMW", 99999);
    cout << A.name;

   // becasue price is private 
   // hence we cannot acces it by A.price outside the class
   // class ke andar A.price likh sakte the but yaha nahi
   // but yaha set_price se access karke set kar sakte hain
    return 0;
}
