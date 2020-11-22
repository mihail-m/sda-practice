#include <bits/stdc++.h>
using namespace std;

vector<int> g[1000000];
int t[1000000][2];

inline bool ancestor(int x, int y) {
    return t[x][0] < t[y][0] && t[y][1] < t[x][1];
}

void dfs(int n, int& d) {
    t[n][0] = d++;
    for (int i : g[n]) {
        dfs(i, d);
    }
    t[n][1] = d++;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    
    int d = 0;
    dfs(0, d);
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        cout << (ancestor(x, y) ? "YES" : "NO") << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
