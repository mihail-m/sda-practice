#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n;
    cin >> n;
    
    int prev;
    cin >> prev;
    
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int num;
        cin >> num;
        
        if (prev < num) {
            ans += (num - prev);
        }
        
        prev = num;
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout << solve() << endl;
    
    return 0;
}