#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int cnt = 1;
    string ans = "";
    
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == s[i + 1]) {
            cnt++;
        } else {
            ans.append(to_string(cnt));
            ans.push_back(s[i]);
            cnt = 1;
        }
    }

    ans.append(to_string(cnt));
    ans.push_back(s[s.size() - 1]);

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}