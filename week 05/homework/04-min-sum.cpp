#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, d;
    cin >> n >> d;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    deque<int> mins;
    for (int i = 0; i < d; i++) {
        while (mins.empty() == false && mins.back() > a[i]) {
            mins.pop_back();
        }
        mins.push_back(a[i]);
    }
    
    long long sum = mins.front();
    for (int i = d; i < n; i++) {
        if (mins.front() == a[i - d]) {
            mins.pop_front();
        }
        while (mins.empty() == false && mins.back() > a[i]) {
            mins.pop_back();
        }
        mins.push_back(a[i]);
        sum += mins.front();
    }
    
    cout << sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
