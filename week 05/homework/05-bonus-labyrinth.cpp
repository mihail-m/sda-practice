#include <bits/stdc++.h>
using namespace std;

static const int SIZE = 1 << 10;

int n, m;
pair<int, int> start;
pair<int, int> finish;

char labyrinth[SIZE][SIZE];
bool visited[SIZE][SIZE];
int dist[SIZE][SIZE];

int obstacle_left[SIZE][SIZE];
int obstacle_right[SIZE][SIZE];
int obstacle_top[SIZE][SIZE];
int obstacle_bottom[SIZE][SIZE];

void input() {
    cin >> n >> m;
    
    for (int row = 0; row < n; row++) {
        cin >> labyrinth[row];
        
        for (int col = 0; col < m; col++) {
            if (labyrinth[row][col] == 'S') {
                start = {row, col};
            }
            if (labyrinth[row][col] == 'F') {
                finish = {row, col};
            }
        }
    }
}

// Find the furthest obstacle in each direction for each cell in O(n * m)
void find_furthest_obstacle() {
    for (int row = 0; row < n; row++) {
        int last_obstacle = 0;
        for (int col = 0; col < m; col++) {
            if (labyrinth[row][col] == '#') {
                last_obstacle = col;
            } else {
                obstacle_left[row][col] = last_obstacle + 1;
            }
        }

        last_obstacle = m - 1;
        for (int col = m - 1; col >= 0; col--) {
            if (labyrinth[row][col] == '#') {
                last_obstacle = col;
            } else {
                obstacle_right[row][col] = last_obstacle - 1;
            }
        }
    }

    for (int col = 0; col < m; col++) {
        int last_obstacle = 0;
        for (int row = 0; row < n; row++) {
            if (labyrinth[row][col] == '#') {
                last_obstacle = row;
            } else {
                obstacle_top[row][col] = last_obstacle + 1;
            }
        }

        last_obstacle = n - 1;
        for (int row = n - 1; row >= 0; row--) {
            if (labyrinth[row][col] == '#') {
                last_obstacle = row;
            } else {
                obstacle_bottom[row][col] = last_obstacle - 1;
            }
        }
    }
}

void add_potential_cell(queue<pair<int, int>>& q, int row, int col, int d) {
    if (row < 0 || row >= n || col < 0 || col >= m) {
        return;
    }

    if (visited[row][col] || labyrinth[row][col] == '#') {
        return;
    }
    
    dist[row][col] = d;
    q.push({row, col});
    visited[row][col] = true;
}

// bfs in O(n * m)
int solve() {
    queue<pair<int, int>> q;
    q.push(start);

    visited[start.first][start.second] = true;

    while (!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();
        
        int row = node.first;
        int col = node.second;
        int d = dist[row][col] + 1;
        
        // close cells
        add_potential_cell(q, row, col + 1, d);
        add_potential_cell(q, row, col - 1, d);
        add_potential_cell(q, row + 1, col, d);
        add_potential_cell(q, row - 1, col, d);
        
        // distant cels
        add_potential_cell(q, row, obstacle_left[row][col], d);
        add_potential_cell(q, row, obstacle_right[row][col], d);
        add_potential_cell(q, obstacle_top[row][col], col, d);
        add_potential_cell(q, obstacle_bottom[row][col], col, d);

        if (visited[finish.first][finish.second]) {
            return dist[finish.first][finish.second];
        }
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    input();
    find_furthest_obstacle();
    
    cout << solve() << "\n";
    
    return 0;
}