#include <iostream>
using namespace std;
int main() {
    char a[]={'A','B','C', (char)NULL};// no error because NULL ko we converted in character form
    char b[]={'A','B','C','D','E', (char)NULL};
    char c[]={'A','B','C','\0'};//\0 is null here
    char d[]={"Hello World"};// automatic string mein \0 ayega and 5+1+5+1=12 space ka 5, 5 words ka and end mein \0 ka 12 
   cout<< a<< '\n';
   cout<< b<< '\n';
   cout<< c << '\n';
   cout<< d<< '\n';// all a b c and d are  pointers to 1st index of each array hence they will print the values aage tak till \0
   cout<< sizeof(d)<<'\n';
    return 0;
}