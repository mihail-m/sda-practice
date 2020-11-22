#include <bits/stdc++.h>
using namespace std;

class min_stack {
    private:
        stack<int> _elements;
        int _min;

    public:
        min_stack() {
            _min = INT_MAX;
        }

        void push(int value) {
            if (value < _min) {
                _elements.push(2 * value - _min);
                _min = value;
            } else {
                _elements.push(value);
            }
        }

        void pop() {
            if (_elements.top() < _min) {
                _min = 2 * _min - _elements.top();
            }
            _elements.pop();
        }

        int top() {
            return _elements.top() < _min ? _min : _elements.top();
        }
    
        int get_min() {
            return _min;
        }
};

void solve() {
    min_stack s;

    int q;
    cin >> q;
    
    while (q--) {
        string type;
        cin >> type;
        
        if (type == "push") {
            int num;
            cin >> num;
            s.push(num);
        }
        if (type == "pop") {
            s.pop();
        }
        if (type == "peek") {
            cout << s.top() << "\n";
        }
        if (type == "min") {
            cout << s.get_min() << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();

    return 0;
}