#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> l, r;
    
    while (n--) {
        int truck;
        cin >> truck;
        
        if (truck > 0) {
            r.push_back(truck);
            continue;
        }
        
        while (!r.empty() && -truck > r.back()) {
            r.pop_back();
        }
        
        if (r.empty()) {
            l.push_back(truck);
        } else if (r.back() == -truck) {
            r.pop_back();
        }
    }
    
    for (int truck : l) {
        cout << truck << " ";
    }
    for (int truck : r) {
        cout << truck << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
