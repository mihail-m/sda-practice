#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> axis;
    for (int i = 0; i < n; i++) {
        int f, t;
        cin >> f >> t;
        axis.push_back({f, -1});
        axis.push_back({t, 1});
    }
    
    sort(axis.begin(), axis.end());
    
    int cur = 0;
    vector<int> ans;
    for (int i = 0; i < (int) axis.size(); i++) {
        if (cur == 0) {
            ans.push_back(axis[i].first);
        }
        int temp = axis[i].first;
        while (i < (int) axis.size() && axis[i].first == temp) {
            cur -= axis[i].second;
            i++;
        }
        i--;
        if (cur == 0) {
            ans.push_back(axis[i].first);
        }
    }

    for (int i = 0; i < (int) ans.size() - 1; i += 2) {
        cout << ans[i] << " " << ans[i + 1] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}