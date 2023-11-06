#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void findroom(int height, int width, int row, int col, vector<vector<char>>& building, vector<vector<bool>>& visited) {
    vector<pair<int, int>> dirs{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = true;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto& [r, c] = q.front();
            for (auto& [a, b] : dirs) {
                if (r + a < 0 || r + a >= height || c + b < 0 || c + b >= width) {
                    continue;
                }

                if (building[r + a][c + b] == '.' && !visited[r + a][c + b]) {
                    q.push({r + a, c + b});
                    visited[r + a][c + b] = true;
                }
            }
            q.pop();
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> building(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> building[i][j];
        }
    }

    int roomcount = 0;
    vector<vector<bool>> visited(n, vector<bool>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (building[i][j] != '#' && !visited[i][j]) {
                findroom(n, m, i, j, building, visited);
                roomcount++;
            }
        }
    }

    cout << roomcount << endl;
    return 0;
}