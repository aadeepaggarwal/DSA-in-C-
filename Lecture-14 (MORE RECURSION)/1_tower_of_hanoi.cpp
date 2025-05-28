#include <iostream>
using namespace std;

void tower_of_hanoi(int n, char src, char helper, char dest){
    // base case
    if (n==0)
    {
        return;
    }

    // recursion
    tower_of_hanoi(n-1,src, dest, helper);
    cout<<" Take "<< n<<" from "<< src<<" to "<<dest<<'\n';
    tower_of_hanoi(n-1, helper,src,dest);
    
}
int main() {
    int n;
    cin>>n;

    tower_of_hanoi(n,'A','B','C');
    return 0;
}