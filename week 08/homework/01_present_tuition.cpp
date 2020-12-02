#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> timeline;
    
    for (int i = 0; i < n; i++) {
        int f, t;
        cin >> f >> t;
        timeline.push_back({f, +1});
        timeline.push_back({t, -1});
    }
    
    sort(timeline.begin(), timeline.end());
    
    int cur_rooms = 0;
    int rooms = 0;
    
    for (pair<int, int> point : timeline) {
        cur_rooms += point.second;
        rooms = max(rooms, cur_rooms);
    }
    
    cout << rooms << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
