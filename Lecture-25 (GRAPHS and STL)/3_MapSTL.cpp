#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
int main() {
    unordered_map<string, int>h;// automatically key value pair banta hai ye(stores value in pairs by default)
    h["Mango"]=100;// key value pair ban gaya ye
    h["Apple"]=10;
    h["Orange"]=190;
    h["Papaya"]=60;
    h["Banana"]=11;
    h.insert({"pineapple",20});// this insert function uses wahi lamba sa modulo wala formula to get the index of fruits im table
   //// now we use this below wala function to print the hash table jaha jaha value hain
    cout<<"This is only the values filled in hash map as of now\n";
    for(auto p:h){
        cout<<p.first<<", "<<p.second<<endl;
    }
    // now we do the same thing to print full hash map
    cout<<"\nThis full hash table\n";
    for (int i = 0; i < h.bucket_count(); i++)// loop to iterate over each index of hash table, and each table ka cell stores address of head of the list which it contains
    {
       cout<<i<<"-->";
       // unordered_map<string, int>:: iterator it;
       // upar wali line ab khudse pick kar rahi hai it ke liye data type, we can use auto keyword instead of that
       for (auto it = h.begin(i); it !=h.end(i); it++)// ye loop har index of table pe uski poori list pe itearate karwa raha hai
       {
        cout<<"("<<it->first<<", "<<it->second<<") ";
       }
       cout<<endl;
    }
    
    return 0;
}