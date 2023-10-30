#include <array>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int pcount{0};
string dir_str{"DULR"};
vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
map<int, char> definedirs;

void findpath(int row, int col, int pathlen, array<array<bool, 7>, 7>& visited) {
    if (row > 0 && row < 6 && col > 0 && col < 6) {
        if (visited[row - 1][col] && visited[row + 1][col] && visited[row][col - 1] && visited[row][col + 1]) {
            return;
        }
    } else {
        if (row == 0) {
            if (col > 0 && col < 6 && visited[0][col - 1] && visited[0][col + 1] && visited[1][col])
                return;

            if (col == 6 && visited[0][5] && visited[1][6])
                return;
        }

        if (row == 6) {
            if (col > 0 && col < 6 && visited[6][col - 1] && visited[6][col + 1] && visited[5][col])
                return;

            if (col == 6 && visited[6][5] && visited[5][6])
                return;
        }

        if (col == 0) {
            if (row > 0 && row < 6 && visited[row - 1][0] && visited[row + 1][0] && visited[row][col + 1])
                return;
        }
        if (col == 6) {
            if (row > 0 && row < 6 && visited[row - 1][6] && visited[row + 1][6] && visited[row][5])
                return;
            if (row == 6 && visited[5][6] && visited[6][5])
                return;
        }
    }

    if (row == 6 && col == 0) {
        if (pathlen == 48) {
            pcount++;
        }
        return;
    } else {
        if (definedirs.contains(pathlen)) {
            char fdir = definedirs[pathlen];

            int index    = dir_str.find(fdir);
            int next_row = row + dirs[index][0];
            int next_col = col + dirs[index][1];
            if (next_row >= 0 && next_row <= 6 && next_col >= 0 && next_col <= 6 && visited[next_row][next_col] == false) {
                pathlen++;
                visited[next_row][next_col] = true;
                findpath(next_row, next_col, pathlen, visited);
                pathlen--;
                visited[next_row][+next_col] = false;
            }
        } else {
            for (int i = 0; i < 4; i++) {
                int next_row = row + dirs[i][0];
                int next_col = col + dirs[i][1];
                if (next_row >= 0 && next_row <= 6 && next_col >= 0 && next_col <= 6 && visited[next_row][next_col] == false) {
                    pathlen++;
                    visited[next_row][next_col] = true;
                    findpath(next_row, next_col, pathlen, visited);
                    pathlen--;
                    visited[next_row][next_col] = false;
                }
            }
        }
    }
}

int main() {
    string str;
    cin >> str;

    for (int i = 0; i < 48; i++) {
        if (str[i] != '?') {
            definedirs.insert({i, str[i]});
        }
    }

    string path;
    array<array<bool, 7>, 7> visited;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++)
            visited[i][j] = false;
    }
    visited[0][0] = true;

    findpath(0, 0, 0, visited);
    cout << pcount << endl;
}