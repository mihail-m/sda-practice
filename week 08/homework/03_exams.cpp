#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    
    long long ans = 0;
    long long cur_time = 0;
    multiset<pair<int, int>> heap;
    
    for (pair<int, int> p : v) {
        while (!heap.empty() && p.first > cur_time) {
            cur_time += (*heap.begin()).first;
            ans += (cur_time - (*heap.begin()).second);
            heap.erase(heap.begin());
        }
        
        if (p.first > cur_time) {
            cur_time = p.first;
        }

        heap.insert({p.second, p.first});
    }
    
    while (!heap.empty()) {
        cur_time += (*heap.begin()).first;
        ans += (cur_time - (*heap.begin()).second);
        heap.erase(heap.begin());
    }
    
    cout << ans / n << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
