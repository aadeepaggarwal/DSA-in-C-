#include <iostream>
using namespace std;
int main() {
    char ch;
    cin>>ch;

    switch (ch)
    {
    case 'N':
        cout<<"NORTH \n";
        break;// using break is important because if we do not use break to neeche tak saare print ho jayenge
    case 'S':
        cout<<"SOUTH \n";
        break;
    case 'E':
        cout<<"EAST \n";
        break;
     case 'W':
     case 'w':// can add 2 or more conditions as well for same command
        cout<<"WEST\n";
        break;
    default:// har bar dalna zaruri nahi
        cout<<" Incorrect output \n";
        break;
    }
    return 0;
}
