#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100024;

int a[MAX_N];
long long p[MAX_N];

int main() {
    int n;
    scanf("%d", &n);

    scanf("%d", &a[0]);
    p[0] = a[0];
    for (int i = 1; i < n; i++) {
        scanf("%d", &a[i]);
        p[i] = p[i - 1] + a[i];
    }

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        long long q;
        scanf("%lld", &q);

        int l = 0, r = n - 1;
        int ans = n;
        while (l <= r) {
            int m = (l + r) / 2;
            if (p[m] >= q) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        ans++;
        printf("%d\n", ans);
    }

    return 0;
}