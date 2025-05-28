#include <iostream>
using namespace std;
void permutations(char *a, int i){
    // base case jab we reach null
    if (a[i]=='\0')
    {
        cout<<a;
        cout<<'\n';
        return;
    }
    // recursive call 
    for (int j = i; a[j]!='\0'; j++) // ye loop mein j shuru hoga i se and swap karega har position pe ith element ko 
    {
        swap(a[i],a[j]);
        permutations(a, i+1);// swap karke ab i+1 pe call it

        // BACKTRACKING
        swap(a[i],a[j]); // array workflow mein upar jaate hue swap kara tha 
        // ab call by reference tha, usey undo karne ke liye we want swap back wapas aate hue 
        // danger! ab har baar array swap karke by refernce call kara toh arraya bhi khud change ho gaya 
        // we dont want ki array change ho
    }
    
    

}
int main() {
    char a[]= "abc";
    permutations(a,0);
    return 0;
}