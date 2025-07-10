// #include <bits/stdc++.h>
// using namespace std;
// vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
// string ans="";
// pair<bool,int> dfs(vector<vector<char>>&arr,vector<vector<bool>>&visit, int i , int j, int &count){
//         if(arr[i][j]=='B')return true;
//         visit[i][j]=true;
//         for(auto d : dir){
//             int newi=i+d[0];
//             int newj=j+d[1];
//             if(newi>=0 and newi<arr.size()){
//                 if(newj>=0 and newj<arr[0].size()){
//                     if(arr[newi][newj]!='#' and visit[newi][newj]==false){
//                        count+=1;
//                        if(d[0]==-1)ans+="U";
//                        else if(d[0]==1) ans+="D";
//                        else if(d[1]==-1) ans+="L";
//                        else ans+="R";
//                        bool flag= dfs(arr,visit,newi,newj,count);
//                        if(flag)return true;
//                     }
//                 }
//             }
//         }
//         return false;
// }
// int main() {
//     int n,m;cin>>n>>m;
//     vector<vector<char>>arr(n,vector<char>(m));
//     vector<vector<bool>>visit(n, vector<bool>(m, false));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>arr[i][j];
//             visit[i][j]=false;
//         }
//     }
    
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(visit[i][j]==false and arr[i][j]=='A'){
//                 int steps=0;
//                 if(dfs(arr,visit,i,j,steps)){
//                     cout<<"YES\n"<<steps<<endl<<ans;
//                 }
//                 else cout<<"NO";
                
//             }
//         }
//     }
   
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<char> move_dir = {'U', 'D', 'L', 'R'};
// A to B minimum distance needed, walk only on "." and wall is "#"
// so traverse full matrix, if A comes start bfs because we spread equally in all directions via bfs,
// as soon as B comes stop, stop wala path is shortest automatically
// unweighted shortest path ke liye use bfs
// to get back the path store parents 
// retrace parent direction till we reach A
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    pair<int, int> start, end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'A') start = {i, j};
            if (arr[i][j] == 'B') end = {i, j};
        }
    }

    vector<vector<bool>> visit(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> move_taken(n, vector<char>(m, 0));
    queue<pair<int, int>> q;
    q.push(start);
    visit[start.first][start.second] = true;

    bool found = false;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (make_pair(x, y) == end) {
            found = true;
            break;
        }
        for (int d = 0; d < 4; d++) {
            int nx = x + dir[d].first;
            int ny = y + dir[d].second;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && arr[nx][ny] != '#') {
                visit[nx][ny] = true;
                parent[nx][ny] = {x, y};
                move_taken[nx][ny] = move_dir[d];
                q.push({nx, ny});
            }
        }
    }

    if (!found) {
        cout << "NO\n";
    } else {
        // Reconstruct path
        string path;
        pair<int, int> cur = end;
        while (cur != start) {
            char mv = move_taken[cur.first][cur.second];
            path += mv;
            cur = parent[cur.first][cur.second];
        }
        reverse(path.begin(), path.end());
        cout << "YES\n";
        cout << path.size() << "\n";
        cout << path << "\n";
    }
    return 0;
}