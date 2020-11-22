#include <bits/stdc++.h>
using namespace std;

struct prefix_node {
    bool is_word;
    map<char, prefix_node*> children;

    prefix_node() {
        is_word = false;
    }
};

prefix_node* root;

void add_word(string word) {
    prefix_node* node = root;
    for (char letter : word) {
        if (!node->children.count(letter)) {
            node->children[letter] = new prefix_node();
        }
        node = node->children[letter];
    }
    node->is_word = true;
}

bool find_word(string word) {
    prefix_node* node = root;
    for (char letter : word) {
        if (!node->children.count(letter)) {
            return false;
        }
        node = node->children[letter];
    }
    return node->is_word;
}

void build() {
    int n;
    cin >> n;

    root = new prefix_node();
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        add_word(word);
    }
}

void solve() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        string word;
        cin >> word;
        cout << (find_word(word) ? "YES" : "NO") << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    build();
    solve();

    return 0;
}