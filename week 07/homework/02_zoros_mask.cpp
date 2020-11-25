#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int a[n], ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans += (1 << __builtin_popcount(a[i]));
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans -= (1 << __builtin_popcount(a[i] & a[j]));
            a[j] ^= (a[i] & a[j]); 
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