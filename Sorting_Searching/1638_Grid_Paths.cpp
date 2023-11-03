#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    char c;
    cin >> n;

    vector<vector<int>> vec;
    vector<int> row(n + 1, 0);
    vec.push_back(row);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c;
            if (c == '.') {
                row[j] = 1;
            } else {    // *
                row[j] = 0;
            }
        }
        vec.push_back(row);
    }

    if (vec[1][1] == 0 || vec[n][n] == 0) {
        cout << 0 << endl;
        return 0;
    }

    const int mod = 1000000007;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) {
                vec[i][j] = 1;
            } else {
                if (vec[i][j] != 0) {
                    vec[i][j] = (vec[i][j - 1] + vec[i - 1][j]) % mod;
                }
            }
        }
    }
    cout << vec[n][n] << endl;
    return 0;
}