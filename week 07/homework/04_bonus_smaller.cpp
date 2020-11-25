#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        a.push_back({num, i});
    }
    
    sort(a.begin(), a.end(), cmp);
    
    set<int> s;
    vector<int> ans(n);
    
    int l = 0, r = 0;
    while (r < n) {
        while (l < r && a[l].first + k < a[r].first) {
            s.erase(a[l++].second);
        }
        s.insert(a[r].second);
        auto it = s.find(a[r].second);
        ans[a[r++].second] = (it == s.begin()) ? -1 : *(--it);
    }
    
    for (int index : ans) {
        cout << index << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
        
    return 0;
}
