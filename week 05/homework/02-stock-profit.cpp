#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int sum = 0;
    int ans = n + 1;
    queue<int> q;
    
    for (int profit : a) {
        sum += profit;
        q.push(profit);
        
        while (!q.empty() && sum - q.front() >= k) {
            sum -= q.front();
            q.pop();
        }
        
        if (sum >= k) {
            ans = min(ans, (int) q.size());
        }
    }
    
    cout << (ans == n + 1 ? -1 : ans) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
