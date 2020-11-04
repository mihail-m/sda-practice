#include <bits/stdc++.h>
using namespace std;

int op[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool used[1000][1000];

void solve() {
    int n, m, t;
    cin >> n >> m >> t;

    int ans = n * m;
    int x, y;

    queue<pair<int, int>> q;
    while (cin >> x >> y) {
        q.push({--x, --y});
        used[x][y] = true;
        ans--;
    }

    for (int i = 0; i < t; i++) {
        int sz = q.size();
        while (sz--) {
            pair<int, int> cell = q.front(); q.pop();

            for (int x = 0; x < 4; x++) {
                int newX = cell.first + op[x][0];
                int newY = cell.second + op[x][1];

                if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                    if (!used[newX][newY]) {
                        used[newX][newY] = true;
                        q.push({newX, newY});
                        ans--;
                    }
                }
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}