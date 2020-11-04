#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100024;

queue<pair<string, int>> groups[MAX_N];
queue<int> currentGroup;

void solve() {
    int n, m;
    cin >> n >> m;

    int i;
    for (i = 0; i < n; i++) {
        string name;
        int group;
        cin >> name >> group;

        if (groups[group].empty()) {
            currentGroup.push(group);
        }
        groups[group].push({name, i});

        if (i > 0 && i % 2 == 0) {
            cout << groups[currentGroup.front()].front().first << " "
                 << groups[currentGroup.front()].front().second << " " 
                 << i << endl;

            groups[currentGroup.front()].pop();
            if (groups[currentGroup.front()].empty()) {
                currentGroup.pop();
            }
        }
    }

    if (i % 2 == 1) {
        i++;
    }

    while (!currentGroup.empty()) {
        while (!groups[currentGroup.front()].empty()) {
            cout << groups[currentGroup.front()].front().first << " "
                 << groups[currentGroup.front()].front().second 
                 << " " << i << endl;

            groups[currentGroup.front()].pop();
            i += 2;
        }
        currentGroup.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}