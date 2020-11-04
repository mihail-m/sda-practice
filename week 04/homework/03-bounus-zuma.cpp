#include <bits/stdc++.h>
using namespace std;

static const int MAX_SIZE = 200001;

struct Node {
    int color;
    Node* prev;
    Node* next;

    Node() {
        color = 0;
        prev = nullptr;
        next = nullptr;
    }

    Node(int c, Node* n, Node* p) {
        color = c;
        next = n;
        prev = p;
    }
};

Node* pointers[MAX_SIZE];

class doubly_linked_list {
    private:
        Node* first;
        Node* last;

        int _elements;
    
        void collapse(Node* node) {
            if (node == nullptr) {
                return;
            }
            
            vector<Node*> toDelete;
            toDelete.push_back(node);
            
            Node* left = node->prev;
            while (left != nullptr && left->color == node->color) {
                toDelete.push_back(left);
                left = left->prev;
            }
            
            Node* right = node->next;
            while (right != nullptr && right->color == node->color) {
                toDelete.push_back(right);
                right = right->next;
            }
            
            if (toDelete.size() < 3) {
                return;
            }
            
            for (Node* nd : toDelete) {
                delete nd;
            }
            
            _elements -= toDelete.size();
            
            if (_elements == 0) {
                first = last = nullptr;
                return;
            }
            
            if (!left) {
                right->prev = nullptr;
                first = right;
                return;
            }
            
            if (!right) {
                left->next = nullptr;
                last = left;
                return;
            }
            
            left->next = right;
            right->prev = left;
            
            if (left->color == right->color) {
                collapse(left);
            }
        }

    public:
        doubly_linked_list() {
            first = nullptr;
            last = nullptr;
            _elements = 0;
        }

        void insert_end(int color, int number) {
            _elements++;

            if (last == nullptr) {
                first = new Node(color, nullptr, nullptr);
                last = first;
                return;
            }

            last->next = new Node(color, nullptr, last);
            last = last->next;
            
            pointers[number] = last;
        }

        int insert_at(int color, int pos, int number) {
            if (last == pointers[pos]) {
                insert_end(color, number);
            } else {
                _elements++;
                Node* cur = pointers[pos];            
                cur->next = new Node(color, cur->next, cur);
                cur->next->next->prev = cur->next;

                pointers[number] = cur->next;
            }
            
            int cur_el = _elements;
            
            collapse(pointers[number]);
            
            return (cur_el - _elements);
        }
    
        void print() {
            Node* node = first;
            while (node != nullptr) {
                cout << node->color << " ";
                node = node->next;
            }
            cout << "\n";
        }
    
        bool empty() {
            return _elements == 0;
        }
};

int n, q;
doubly_linked_list zuma;

void solve() {
    cin >> q;
    int num = n;
    for (int i = 0; i < q; i++) {
        int p, c;
        cin >> p >> c;
        
        if (zuma.empty()) {
            cout << "Game Over\n";
        } else {
            cout << zuma.insert_at(c, p, num++) << "\n";
        }
    }
    if (zuma.empty()) {
        cout << "-1\n";
    } else {
        zuma.print();
    }
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int color;
        cin >> color;
        zuma.insert_end(color, i);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    solve();
    
    return 0;