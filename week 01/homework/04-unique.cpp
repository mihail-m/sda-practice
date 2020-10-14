#include <bits/stdc++.h>
using namespace std;

long long a, b;
long long ans = 0;

bool used[10];

void check(string num) {
    long long number = 0;
    for (char d : num) {
        number = number * 10 + int(d - '0');
    }
    ans += (a <= number && number <= b);
}

void unique(string num, int pos = 0) {    
    check(num);
    
    for (int digit = 0; digit <= 9; digit++) {
        if (num.size() == 0 && digit == 0) {
            continue;
        }
        
        if (!used[digit]) {
            used[digit] = true;
            unique(num + char('0' + digit), pos + 1);
            used[digit] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> a >> b;
    
    unique("");
    
    cout << ans << endl;
    
    return 0;
}