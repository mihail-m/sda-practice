#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1 << 18;

vector<int> bit[SIZE];

void add(int x, int y) {
    while (x <= SIZE) {
        bit[x].push_back(y);
        x += x & (-x);
    }
}

int get(int x, int y){
    int ans = 0;

    while (x) {
        ans += upper_bound(bit[x].begin(), bit[x].end(), y) - bit[x].begin();
        x -= x & (-x);
    }

    return ans;
}

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].second >> points[i].first;
        points[i].first++;
        points[i].second++;
    }

    sort(points.begin(), points.end());

    for (int i = 0; i < n; i++) {
        add(points[i].second, points[i].first);
    }
    
    int q;
    cin >> q;
    
    while (q--) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1++, y1++, x2++, y2++;

        double area = (x2 - x1) * (y1 - y2);
        
        int total = get(x2, y1)
                  - get(x2, y2 - 1)
                  - get(x1 - 1, y1)
                  + get(x1 - 1, y2 - 1);

        cout << total / area << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    solve();

    return 0;
}