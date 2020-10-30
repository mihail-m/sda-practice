#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> ranges;
    for (int i = 0; i < n; i++) {
        int f, t;
        cin >> f >> t;
        ranges.push_back({f, t});
    }
    
    sort(ranges.begin(), ranges.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    });
    
    int ans = 0;
    for (int i = 0; i < (int) ranges.size() - 1; i++) {
        if (ranges[i].first <= ranges[i + 1].first && ranges[i + 1].second <= ranges[i].second) {
            ranges[i + 1] = ranges[i];
            ans++;
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}