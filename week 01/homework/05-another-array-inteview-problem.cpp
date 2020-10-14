#include <bits/stdc++.h>
using namespace std;

static const int SIZE = 1e6 + 1;
static const int MOD = 1e9 + 7;

int n;
int arr[SIZE];

long long prefixProduct[SIZE];
long long suffixProduct[SIZE];

int answer[SIZE];

void solve() {
    prefixProduct[0] = 1;
    suffixProduct[n] = 1;
    for (int i = 0; i < n; i++) {
        prefixProduct[i + 1] = (prefixProduct[i] * arr[i]) % MOD;
        suffixProduct[n - i - 1] = (suffixProduct[n - i] * arr[n - i - 1]) % MOD;
    }
    
    for (int i = 0; i < n; i++) {
        answer[i] = (prefixProduct[i] * suffixProduct[i + 1]) % MOD;
    }
}

void print() {
    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    input();
    solve();
    print();
    
    return 0;
}