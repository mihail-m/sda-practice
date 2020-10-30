#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, num;
    cin >> n;
    
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> num;
        
        int index = v.size() - 1;
        while (index >= 0 && v[index] > num) {
            index--;
        }
        
        v.insert(v.begin() + index + 1, num);
        cout << (v[v.size() / 2] + v[v.size() / 2 - (v.size() % 2 == 0)]) / 2.0 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}