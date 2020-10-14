#include <bits/stdc++.h>

static const int SIZE = 150000001;

int cnt[30];
char word[SIZE];

void solve(int n, int add) {
    scanf("%s", word);
    for (int i = 0; i < n; i++) {
        cnt[word[i] - 'a'] += add;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    solve(n, 1);
    solve(n, -1);
    
    for (int i = 0; i < 26; i++) {
        if (cnt[i] != 0) {
            printf("no\n");
            return 0;
        }
    }
    printf("yes\n");
    
    return 0;
}