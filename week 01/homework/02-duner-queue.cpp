#include <bits/stdc++.h>
using namespace std;

string s;

int solve() {
    bool flag = true;
    
    int maxLen = -1;
    int len = 0;
    
    for (char c : s) {
        if (c == 'x') {
            maxLen = max(maxLen, (flag) ? (len - 1) : (len / 2 - (len % 2 == 0)));
            len = 0;
            flag = false;
        }
        else { 
            len++;
        }
    }
    
    if (s[s.size() - 1] == '-') {
        maxLen = max(maxLen, len - 1);
    }
    
    return maxLen;
}

void input() {
    int n;
    cin >> n;
    cin >> s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    input();
    cout << solve() << endl;
    
    return 0;
}