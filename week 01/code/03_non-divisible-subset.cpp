#include <bits/stdc++.h>
using namespace std;

int nonDivisibleSubset(int k, vector<int> s) {
    vector<int> rem(k, 0);

    for (int num : s) {
        rem[num % k]++;
    }

    int result = (rem[0] > 0);
    for (int i = 1; i < k / 2 + k % 2; i++) {
        result += max(rem[i], rem[k - i]);
    }

    if (k % 2 == 0) {
        result += (rem[k / 2] > 0);
    }

    return result;
}

void test() {
    assert(3 == nonDivisibleSubset(3, {1, 7, 2, 4}));
    assert(3 == nonDivisibleSubset(4, {19, 10, 12, 10, 24, 25, 22}));
    assert(11 == nonDivisibleSubset(7, {278, 576, 496, 727, 410, 124, 338, 149, 209, 702, 282, 718, 771, 575, 436}));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    test();

    return 0;
}