#include <bits/stdc++.h>
using namespace std;

static const int SIZE = 1 << 18;

struct Node {
    vector<int> val;
    int from, to;

    Node* left;
    Node* right;
};

Node *root;
int arr[SIZE];

void build(Node* node, int from, int to) {
    node->from = from;
    node->to = to;

    if (from == to) {
        node->val.push_back(arr[from]);
        node->left = node->right = nullptr;
        return;
    }

    node->left = new Node;
    node->right = new Node;

    int mid = (from + to) / 2;
    build(node->left, from, mid);
    build(node->right, mid + 1, to);

    int i = 0, j = 0;
    while (i < (int) node->left->val.size() && j < (int) node->right->val.size()) {
        if (node->left->val[i] < node->right->val[j]) {
            node->val.push_back(node->left->val[i++]);
        } else {
            node->val.push_back(node->right->val[j++]);
        }
    }
    for (; i < (int) node->left->val.size(); i++) {
        node->val.push_back(node->left->val[i]);
    }
    for (; j < (int) node->right->val.size(); j++) {
        node->val.push_back(node->right->val[j]);
    }
}

// Find all numbers in the interval arr[from, ..., to] that are in the numeric range [f, t]
int get_sum(Node* node, int from, int to, int f, int t) {
    if (node->from > to || node->to < from) {
        return 0;
    } 

    if (node->from >= from && node->to <= to) {
        if (node->val[0] > t || node->val[node->val.size() - 1] < f) {
            return 0;
        }

        int l = 0;
        int r = node->val.size() - 1;
        int ansl = 0;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (node->val[mid] >= f) {
                ansl = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        l = 0;
        r = node->val.size() - 1;
        int ansr = 0;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (node->val[mid] <= t) {
                ansr = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return (ansr - ansl + 1);
    }

    return get_sum(node->left, from, to, f, t) + get_sum(node->right, from, to, f, t);
}

vector<int> sorted_x;

void input() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    
    sort(points.begin(), points.end());
    
    for (int i = 0; i < (int) points.size(); i++) {
        sorted_x.push_back(points[i].first);
        arr[i] = points[i].second;
    }
    
    root = new Node;
    build(root, 0, n - 1);
}

void solve() {
    int q;
    cin >> q;
    
    for (int i = 0 ; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        int from = lower_bound(sorted_x.begin(), sorted_x.end(), x1) - sorted_x.begin();
        int to = upper_bound(sorted_x.begin(), sorted_x.end(), x2) - 1 - sorted_x.begin();
        
        double area = (x2 - x1) * (y1 - y2);
        double people = get_sum(root, from, to, y2, y1);
        
        cout << people / area << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);
    
    input();
    solve();
  
    return 0;
}
