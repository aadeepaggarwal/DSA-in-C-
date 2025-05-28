#include <iostream>
using namespace std;
int main() {
    int a=10;
    double b=1000;
    char ch='A';
    char ch_2='B';
    cout<<"val of a "<<a<<'\n';
    cout<<"val of b "<<b<<'\n';
    cout<<"& of a  "<<&a<<"  sizeof address bucket  "<<sizeof(&a)<<'\n';
    cout<<"& of b "<< &b<<"  sizeof address bucket  "<<sizeof(&b)<<'\n';
/*  val of a 10
    val of b 1000
    & of a  0x61ff0c  sizeof address bucket  4(becuase 32 bit wala installed hai gcc)
    & of b 0x61ff00  sizeof address bucket  4
*/

    cout<<"address of ch :"<<&ch<<"\n Address of ch_2 :"<<&ch_2;
//     address of ch :A
//  Address of ch_2 :BA (becuase B ke baad A raha hoga memory mein)
    return 0;
}