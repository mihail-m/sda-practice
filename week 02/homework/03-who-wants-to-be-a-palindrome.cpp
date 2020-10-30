#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    
    int cnt[256]{0};
    for (char c : s) {
        cnt[c]++;
    }
    
    int oddNumbers = 0;
    for (int i = 0; i < 256; i++) {
        oddNumbers += (cnt[i] % 2);
    }
    
    cout << (oddNumbers <= 1 ? "TRUE" : "FALSE") << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}