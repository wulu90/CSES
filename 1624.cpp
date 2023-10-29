#include <array>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool check_attack(int r, int c, const array<int, 8>& solus) {
    for (int i = 0; i < r; i++) {
        if (solus[i] == c) {
            return true;
        }
    }

    for (int i = 0; i < r; i++) {
        if (r - i == c - solus[i] || r - i == solus[i] - c) {
            return true;
        }
    }

    return false;
}

void queens(array<int, 8> solus, int row, vector<array<int, 8>>& res) {
    if (row == 8) {
        res.push_back(solus);
    } else {
        for (int col = 0; col < 8; col++) {
            if (!check_attack(row, col, solus)) {
                solus[row] = col;
                queens(solus, row + 1, res);
            }
        }
    }
}

int main() {
    set<pair<int, int>> reserved;
    char c;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> c;
            if (c == '*') {
                reserved.insert({i, j});
            }
        }
    }

    vector<array<int, 8>> res;
    array<int, 8> sols{0, 0, 0, 0, 0, 0, 0, 0};
    queens(sols, 0, res);

    int count = res.size();
    for (auto& sol : res) {
        for (int i = 0; i < 8; i++) {
            if (reserved.contains({i, sol[i]})) {
                count -= 1;
                break;
            }
        }
    }

    cout << count << endl;
}