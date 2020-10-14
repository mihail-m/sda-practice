#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, x;
    cin >> n >> x;
    
    vector<int> s;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        s.push_back(num);
    }
    
    set<int> temp(s.begin(), s.end());
    s.assign(temp.begin(), temp.end());
    
    int ans = 1;
    int push = x;
    
    for (int i = s.size() - 2; i >= 0; i--) {
        if (s[i] - push < 1) {
            break;
        }
        ans++;
        push += x;
    }
    
    cout << ans << endl;
    return 0;
}
