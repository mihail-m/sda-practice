#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000005;

int arr[MAX];

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    stack<int> s;

    pair<int, int> ans = {0, n};
    for(int i = n - 1; i >= 0; i--) {
        while(!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        s.push(arr[i]);
        if (ans.first <= s.size()) {
            ans = {s.size(), i};
        }
    }

    cout << ans.second << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}