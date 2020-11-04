#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* link;

    Node(int v, Node* l) {
        value = v;
        link = l;
    }
};

class linked_list {
    private:
        Node* first;
        Node* last;

        int _elements;

    public:
        linked_list() {
            first = nullptr;
            last = nullptr;
            _elements = 0;
        }

        void insert_end(int num) {
            _elements++;

            if (last == nullptr) {
                first = new Node(num, nullptr);
                last = first;
                return;
            }

            last->link = new Node(num, nullptr);
            last = last->link;
        }

        void reverse() {
            if (_elements == 1) {
                return;
            }
            if (_elements == 2) {
                swap(first->value, first->link->value);
                return;
            }

            Node* prev = first;
            Node* cur = first->link;
            Node* next = cur->link;

            while (next != nullptr) {
                cur->link = prev;

                prev = cur;
                cur = next;
                next = next->link;
            }

            cur->link = prev;
            first->link = nullptr;
            swap(first, last);
        }
    
        void print() {
            Node* cur = first;
            while(cur != nullptr) {
                cout << cur->value << "\n";
                cur = cur->link;
            }
        }
};

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    
    for (int i = 0; i < n;) {
        int num;
        linked_list* list = new linked_list();
        
        for (int j = 0; j < x && i < n; i++, j++) {
            cin >> num;
            list->insert_end(num);
        }
        
        list->reverse();
        list->print();
        list = new linked_list();
                      
        for (int j = 0; j < y && i < n; i++, j++) {
            cin >> num;
            list->insert_end(num);
        }
        
        list->print();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();

    return 0;
}