#include <bits/stdc++.h>
using namespace std;

int n;
int h[100001];

int water(int l, int r) {
    return min(h[l], h[r]) * (r - l);
}

void solve() {
    int l = 0;
    int r = 0;
    
    int best = 0;
    int cur = 0;
    
    while (r < n) {
        cur = water(l, r);

        while (l < r && water(l + 1, r) > cur) {
            l++;
            cur = water(l, r);
        }
        
        best = max(best, cur);
        r++;
    }
    
    cout << best << "\n";
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}