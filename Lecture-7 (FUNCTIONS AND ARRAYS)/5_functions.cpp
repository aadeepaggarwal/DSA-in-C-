#include <iostream>
using namespace std;
/*
    syntax: return_type function_name(arguments) ----> this 1st line is the function declaration
    {
        // definition of the function
        }
*/

void /* because in hello world we don't need any return thing so return type void*/ helloworld()
{
    cout << "Hello World \n";
}

void sum_of_two(int x, int y)
{ // parameters are recieved in the arguments
    int sum = x + y;
    cout << sum << '\n';
    // I again dont need any return type because I just wanted to print the sum, hence type was taken as void
}

// taking function of return type
// we need the sum as output return hence return type is integer
int sum(int a, int b)
{
    int ans = a + b;
    return ans; // jo return chaaiye tha woh lelia yahan
    /*please note that return se print nahi hoga bas woh value lelega so to print we need to store the function in some variable*/
}
int subtract(int a, int b)
{
    return a - b;
}
int main()
{
    helloworld(); // call the function here
    sum_of_two(10, 20);
    int a = 10, b = 20;
    sum_of_two(a, b);
    /*we need not keep the brackets wale arguments same...
    upar x and y the yaha a and b hai woh chalega*/
    /*taking function stored in a variable*/ int ans = sum(a, b);
    if (ans % 2 == 0)
    {
        cout << "even \n";
    }
    else
        cout << "Odd";

    cout << "difference is" << subtract(a, b); // yaha aise cout bhi karwa sakte hai retun wale function se, we will get desired output
    return 0;
}

// i can declare function at top and define it here again pura return_type.... wala likh ke to bhi code chal jayega