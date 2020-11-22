#include <bits/stdc++.h>
using namespace std;

#define ind first
#define x second.first
#define y second.second

void solve() {
    int n;
    cin >> n;
    
    vector<int> tree({0});
    for (int i = 0; i < n; i++) {
        int c1, c2;
        cin >> c1 >> c2;
        tree.push_back(c1);
        tree.push_back(c2);
    }
    
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, 0}});
    
    map<int, int> ans;
    while (!q.empty()) {
        auto node = q.front(); q.pop();
        
        if (!ans.count(node.x)) {
            ans[node.x] = node.ind;
        }
        
        if (tree[2 * node.ind + 1] != -1) {
            q.push({tree[2 * node.ind + 1], {node.x - 1, node.y - 1}});
        }
        if (tree[2 * node.ind + 2] != -1) {
            q.push({tree[2 * node.ind + 2], {node.x + 1, node.y - 1}});
        }
    }
    
    for (auto p : ans) {
        cout << p.second << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}