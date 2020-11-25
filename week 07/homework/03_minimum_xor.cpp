#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q;
    cin >> q;

    set<int> s({0});
    int answer = INT_MAX;
    
    for(int i = 0; i < q; i++) {
        int num;
        cin >> num;
        s.insert(num);

        auto it = s.find(num);
        auto next = it; next++;
        auto prev = it;

        if (prev != s.begin()) {
            prev--;
            answer = min(answer, num ^ (*prev));
        }
        
        if (next != s.end()) {
            answer = min(answer, num ^ (*next));
        }
        
        cout << answer << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
