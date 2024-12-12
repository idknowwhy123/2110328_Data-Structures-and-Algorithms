#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> v(500, vector<int>(500));

void bfs(int startX, int startY, int n, int m, int t, int &cnt) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    chk[startX][startY] = true;
    
    // Directions for moving up, down, left, right
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    int k = 0; // depth limit
    while (!q.empty()) {
        int qSize = q.size();
        while (qSize--) {
            auto [x, y] = q.front();
            q.pop();

            // If it's a '0' and we haven't processed it yet, update and count
            if (v[x][y] == 0) {
                v[x][y] = 1;
                cnt++;
            }

            // Explore neighboring cells
            for (auto [dx, dy] : directions) {
                int newX = x + dx, newY = y + dy;
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && !chk[newX][newY] && v[newX][newY] != 2) {
                    chk[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }
        k++;
        if (k >= t) break; // Stop if depth exceeds t
    }
}

int main() {
    int n, m, t;
    cin >> n >> m >> t;

    vector<pair<int, int>> pos;

    // Input the grid and store the positions of '1's
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            v[i][j] = num;
            if (num == 1) pos.push_back({i, j});
        }
    }

    int cnt = 0;

    // Perform BFS starting from each position of '1'
    for (auto &x : pos) {
        
        bfs(x.first, x.second, n, m, t, cnt);
        
    }

    cout << cnt << endl;

    return 0;
}
