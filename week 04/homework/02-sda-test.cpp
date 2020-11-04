#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* prev;
    Node* next;

    Node(int v, Node* n, Node* p) {
        value = v;
        next = n;
        prev = p;
    }
};

class doubly_linked_list {
    private:
        Node* first = nullptr;
        Node* last = nullptr;
        Node* mid = nullptr;

        int _elements = 0;

    public:
        void add(int num) {
            _elements++;

            if (last == nullptr) {
                first = new Node(num, nullptr, nullptr);
                last = first;
                mid = first;
                return;
            }

            last->next = new Node(num, nullptr, last);
            last = last->next;
            
            if (_elements % 2 == 1 && _elements > 1) {
                mid = mid->next;
            }
        }

        void gun() {
            _elements--;

            if (_elements == 0) {
                delete last;
                last = mid = first = nullptr;
                return;
            }
            
            last = last->prev;
            delete last->next;
            last->next = nullptr;
            
            if (_elements % 2 == 0) {
                mid = mid->prev;
            }
        }
    
        void milen() {
            if (_elements == 1) {
                return;
            }
            
            bool flag = (_elements % 2 == 0);
            Node* newFirst = flag ? mid->next : mid;
            Node* newLast = flag ? mid : mid->prev;
            Node* newMid = last;
            
            first->prev = last;
            last->next = first;
            
            first = newFirst;
            last = newLast;
            mid = newMid;
            
            first->prev = last->next = nullptr;
        }
    
        void print() {
            cout << _elements << "\n";
            Node* cur = first;
            while(cur != nullptr) {
                cout << cur->value << " ";
                cur = cur->next;
            }
            cout << "\n";
        }
};

void solve() {
    int n;
    cin >> n;
    
    doubly_linked_list list;
    
    while (n--) {
        string type;
        cin >> type;
        
        if (type == "add") {
            int num;
            cin >> num;
            list.add(num);
        }
        
        if (type == "gun") {
            list.gun();
        }
        
        if (type == "milen") {
            list.milen();
        }
    }
    
    list.print();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();

    return 0;
}