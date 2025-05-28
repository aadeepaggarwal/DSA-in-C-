#include <iostream>
#include <cstring>
using namespace std;

class Car
{
public:
    char *name; // yaha name points at garabge right now
    int price;
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
        price = p;
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
    void set_name(char*n){ // yaha we check ki jo strcpy name mein we are copying
    // agar woh name null hai to pehle memory bana le jaha woh point karega 
    // fir copy kar string ko
    // null wale mein kya copy karta tu
        if(name!=NULL){// check null hai ki nahi
            delete[]name;// agar null nahi hai to jaha point karrha hai usey delete kar
        }
        name=new char[strlen(n)+1];// ab finally null pe point karne ke baad make new mwmory
        strcpy(name,n);// copy in the new memory
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

    Car B;
    B.set_name("Maruti");
    return 0;
}
