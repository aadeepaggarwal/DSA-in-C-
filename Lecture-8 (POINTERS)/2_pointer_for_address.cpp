#include <iostream>
using namespace std;
void UPDATE(int *x){
    *x+=1;
}
void update_2(int &x){
    x+=1;
}
int main() {
    int a=10;

    UPDATE(&a);
    cout<<a<<'\n';// takes 10 updates to 11

    update_2(a);
    cout<<a;// takes 11 updates to 12
    return 0;
}