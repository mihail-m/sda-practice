#include <bits/stdc++.h>
using namespace std;

vector<int> g[1000000];
int presents[1000000];

void dfs(int n) {
    presents[n] = 0;
    for (int i : g[n]) {
        dfs(i);
        presents[n] += presents[i] + 1;
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    
    dfs(0);
    for (int i = 0; i < n; i++) {
        cout << presents[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
