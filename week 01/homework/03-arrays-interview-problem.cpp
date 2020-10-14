#include <bits/stdc++.h>
using namespace std;

static const int SIZE = 1e6 + 1;

int n;
int arr[SIZE];

int solve() {
    int left = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            swap(arr[left], arr[i]);
            left++;
        }
    }
    
    for (int i = left; i < n; i++) {
        if (abs(arr[i]) - 1 < n - left && arr[abs(arr[i]) + left - 1] > 0) {
            arr[abs(arr[i]) + left - 1] = -arr[abs(arr[i]) + left - 1];
        }
    }
    
    int i = 0;
    for (; left < n; i++, left++) {
        if (arr[left] > 0) {
            return i + 1;
        }
    }
    
    return i + 1;
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
    cout << solve() << endl;
    
    return 0;
}