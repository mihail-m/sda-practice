#include <bits/stdc++.h>
using namespace std;

void remove(vector<int>& tree, int node) {
    int cur = node * 2 + 2;
    while (cur < (int) tree.size()) {
        cur = cur * 2 + 1;
    }
    cur = (cur - 1) / 2;
    swap(tree[node], tree[cur]);
    tree[cur] = -1;
}

int removeKth(vector<int>& tree, int node, int bigger, int k) {
    if (node >= (int) tree.size()) {
        return 0;
    }
    
    int elRight = removeKth(tree, node * 2 + 2, bigger, k) + 1;
    
    if (elRight + bigger == k) {
        remove(tree, node);
        return INT_MIN;
    }
    
    return elRight + removeKth(tree, node * 2 + 1, bigger + elRight, k);
}

void print(vector<int>& tree) {
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int node = q.front(); q.pop();
        if (tree[node] != -1) {
            cout << tree[node] << " ";
        }
        if (node * 2 + 1 < (int) tree.size()) {
            q.push(node * 2 + 1);
        }
        if (node * 2 + 2 < (int) tree.size()) {
            q.push(node * 2 + 2);
        }
    }
    cout << "\n";
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> tree;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        tree.push_back(num);
    }
    
    removeKth(tree, 0, 0, k);
    print(tree);

    return 0;
}