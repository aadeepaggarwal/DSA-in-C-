#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class Solution{
    public:
    bool comparator(vector<int>a,vector<int>b){
        if(a[0]==b[0]){// start time sort karenge agar same hai to end time pe
            return a[1]<b[1];
        }
        else return a[0]<b[0];
    }
    int minMeetingRooms(vector<vector<int>>& v){
        sort(v.begin(),v.end(),comparator/*for sorting ka criteria */);
        cout<<endl;
        priority_queue<int, vector<int>,greater<int>> h;
       for (int i = 0; i < v.size(); i++)
       {
        if (h.empty())
        {
           h.push(v[i][1]);
        }
        else {
            int nmET=v[i][1];
            int nmST=v[i][0];
            if (h.top()<=nmST)
            {
               h.pop();
            }
            h.push(nmET);
            
        }
        
       }
       return h.size();

    }

};
int main() {
    
    return 0;
}