#include <bits/stdc++.h>
using namespace std;

struct point_comparator {
    int dimension;

    point_comparator(int dimension = 0) : dimension(dimension) {}

    const bool operator()(const vector<int>& point1, const vector<int>& point2) const {
        return point1[dimension] < point2[dimension];
    } 
};

inline long long square(long long num) {
    return num * num;
}

long long distance_squared(const vector<int>& point1, const vector<int>& point2) {
    long long dist = 0;
    for(size_t i = 0; i < point1.size(); i++) {
        dist += square(point1[i] - point2[i]);
    }
    return dist;
}

class kd_tree {
    private:
        struct kd_node {
            vector<int> point;

            int axis;

            kd_node* left;
            kd_node* right;
            
            kd_node(const vector<int>& point, int axis) : point(point), axis(axis) {}
        };
    
        int k;
        kd_node* root;

        kd_node* build(vector<vector<int>>& points, int from, int to, int axis) {
            if (from > to) {
                return nullptr;
            }

            int mid = (from + to) / 2;
            nth_element(points.begin() + from, 
                        points.begin() + mid, 
                        points.begin() + to + 1, 
                        point_comparator(axis));

            kd_node* node = new kd_node(points[mid], axis);
            node->left = build(points, from, mid - 1, (axis + 1) % k);
            node->right = build(points, mid + 1, to, (axis + 1) % k);

            return node;
        }
    
        long long closest_point_distance(kd_node* node, const vector<int>& point) {
            if (node == nullptr) {
                return LLONG_MAX;
            }

            bool descend_left = point[node->axis] < node->point[node->axis];

            long long dist = distance_squared(node->point, point);
            dist = min(dist, closest_point_distance(descend_left ? node->left : node->right, point));

            if (dist > square(node->point[node->axis] - point[node->axis])) {
                dist = min(dist, closest_point_distance(descend_left ? node->right : node->left, point));
            }

            return dist;
        }
    
    public:
        kd_tree(vector<vector<int>> points, int dimensions) {
            k = dimensions;
            root = build(points, 0, points.size() - 1, 0);
        }
    
        double closest_point(const vector<int>& point) {
            return sqrt(closest_point_distance(root, point));
        }
};

vector<int> read_point(int k) {
    vector<int> point(k);
    for (int i = 0; i < k; i++) {
        cin >> point[i];
    }
    return point;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> points;
    for (int i = 0; i < n; i++) {
        points.push_back(read_point(k));
    }

    kd_tree tree(points, k);

    int q;
    cin >> q;
    cout << fixed << setprecision(3);
    
    for (int i = 0; i < q; i++) {
        cout << tree.closest_point(read_point(k)) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}