#include <iostream>
#include <vector>
using namespace std;

const int N = 7;
string path;
int countPaths = 0;
bool visited[7][7];

// Direction vectors
int dx[4] = {1, -1, 0, 0};  // D, U, R, L
int dy[4] = {0, 0, 1, -1};
char dir[4] = {'D', 'U', 'R', 'L'};

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N && !visited[x][y];
}

void dfs(int x, int y, int step) {
    if (x == 6 && y == 0) {
        if (step == 48) countPaths++;
        return;
    }
    if (step >= 48) return;

    visited[x][y] = true;

    char move = path[step];

    for (int d = 0; d < 4; ++d) {
        int nx = x + dx[d], ny = y + dy[d];

        if ((move == '?' || move == dir[d]) && isValid(nx, ny)) {
            dfs(nx, ny, step + 1);
        }
    }

    visited[x][y] = false;
}

int main() {
    cin >> path;
    dfs(0, 0, 0);
    cout << countPaths << endl;
    return 0;
}
