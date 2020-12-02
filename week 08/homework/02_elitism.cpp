#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    
    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<int>> minq;
    
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
    
        minq.push(num);
        maxq.push(minq.top());
        minq.pop();
        
        if(minq.size() < maxq.size()) {
            minq.push(maxq.top());
            maxq.pop();
        }
        
        if(minq.size() != maxq.size()) {
            cout << (double) minq.top() << "\n";
        } else {
            cout << (double) (minq.top() + maxq.top()) / 2 << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(1);
    
    solve();

    return 0;
}
