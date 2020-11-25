#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, days;
    cin >> n >> days;
    
    vector<pair<int, pair<int ,int>>> people;
    for (int i = 0; i < n; i++) {
        int d, t, s;
        cin >> d >> t >> s;
        people.push_back({d, {t, s}});
    }
    
    sort(people.begin(), people.end());
    
    int index = 0;
    priority_queue<pair<int, int>> heap;
    for (int day = 1; day <= days; day++) {
        while (index < n && people[index].first == day) {
            //            sadness                       lectures
            heap.push({people[index].second.second, people[index].second.first});
            index++;
        }
        
        if (heap.empty()) {
            continue;
        }
        
        auto temp = heap.top();
        heap.pop();
        if (temp.second > 1) {
            heap.push({temp.first, temp.second - 1});
        }
    }
    
    long long ans = 0;
    while (heap.empty() == false) {
        ans += (long long) heap.top().first * heap.top().second;
        heap.pop();
    }
    
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
