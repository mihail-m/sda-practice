#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1000001;

int n, k;
int arr[SIZE];

queue<int> q;
deque<int> minq;
deque<int> maxq;

void input() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void pushq(int val) {
    while (!minq.empty() && minq.back() > val) {
        minq.pop_back();
    }
    minq.push_back(val);

    while (!maxq.empty() && maxq.back() < val) {
        maxq.pop_back();
    }
    maxq.push_back(val);

    q.push(val);
}

void popq() {
    if (minq.front() == q.front()) {
        minq.pop_front();
    }

    if (maxq.front() == q.front()) {
        maxq.pop_front();
    }

    q.pop();
}

void solve() {
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        pushq(arr[i]);

        while (maxq.front() - minq.front() > k) {
            popq();
        }

        ans += (long long)q.size();
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();

    return 0;
}