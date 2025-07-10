#include <bits/stdc++.h>
using namespace std;
// 2d matrix given with doys as floors and # as walls
// continuos adjacent dots make up one room, find total rooms
// iterate over all the cells, if # move ahead, if "." then call dfs and mark all the adjacent dots visited and increase the counter
// do same for newxt unconnected dot found
vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(vector<vector<char>>&arr,vector<vector<bool>>&visit, int i , int j){
        visit[i][j]=true;
        for(auto d : dir){
            int newi=i+d[0];
            int newj=j+d[1];
            if(newi>=0 and newi<arr.size()){
                if(newj>=0 and newj<arr[0].size()){
                    if(arr[newi][newj]=='.' and visit[newi][newj]==false){
                        dfs(arr,visit,newi,newj);
                    }
                }
            }
        }
        return;
}
int main() {
    int n,m;cin>>n>>m;
    vector<vector<char>>arr(n,vector<char>(m));
    vector<vector<bool>>visit(n, vector<bool>(m, false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            visit[i][j]=false;
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visit[i][j]==false and arr[i][j]=='.'){
                dfs(arr,visit,i,j);
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}