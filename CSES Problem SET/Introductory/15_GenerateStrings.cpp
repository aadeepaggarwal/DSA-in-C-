#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

void solve(set<string>& ans, string s, int i) {
    if (i == s.length()) {
        ans.insert(s);
        return;
    }
    for(int j = i; j < s.length(); j++) {
        swap(s[i], s[j]);
        solve(ans, s, i+1);
        swap(s[i], s[j]);
    }
}

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    set<string> ans;
    solve(ans, s, 0);
    cout << ans.size() << endl;
    for(const string& str : ans) {
        cout << str << endl;
    }
    return 0;
}