#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    set<pair<int, int>> power;
    set<pair<int, int>> index;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        power.insert({num, i});
        index.insert({i, num});
    }

    int team = 0;
    vector<int> ans(n);

    while (power.empty() == false) {
        auto player = *(--power.end());
        power.erase(player);

        auto it = index.find({player.second, player.first});
        
        vector<set<pair<int, int>>::iterator> to_remove;

        it++;
        for (int i = 1; i <= k && it != index.end(); i++) {
            power.erase({(*it).second, (*it).first});
            to_remove.push_back(it);
            ans[(*it).first] = team + 1;
            it++;
        }

        it = index.find({player.second, player.first});
        for (int i = 0; i <= k; i++) {
            power.erase({(*it).second, (*it).first});
            to_remove.push_back(it);
            ans[(*it).first] = team + 1;
            
            if (it == index.begin()) {
                break;
            }
            it--;
        }

        for (auto iter : to_remove) {
            index.erase(iter);
        }

        team = (team + 1) % 2;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i];
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}