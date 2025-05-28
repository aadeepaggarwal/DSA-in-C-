#include <iostream>
using namespace std;
#define PI 3.14 // this is a macro we cannot change its value in the program,
// whenever we will use Pi then woh waha 3.14 ko as an itegral value input rakhdega,
// also if we put 31.4 +1 then it will put this in our code there as it is!!
// need to remember BODMAS so yaha woh follow karte hue answers change, similarly answer for (3.14+1) would be different
int main()
{
    // SIZEOF OPERATOR
    cout << "SIZE OF INT" << sizeof(int) << '\n';

    // CONSTANT
    const float pi = 3.14;
    //  pi=pi+1;// gives error as pi cannot be updated
    return 0;
}
