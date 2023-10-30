#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> attacks{{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};

    if (n == 1) {
        cout << 0 << endl;
    } else {
        cout << 0 << endl;
        for (int k = 2; k <= n; k++) {
            int64_t all = 0;
            for (int r = 1; r <= k; r++) {
                for (int c = 1; c <= k; c++) {
                    int ap = 0;
                    for (auto& [a, b] : attacks) {
                        if (r + a >= 1 && r + a <= k && c + b >= 1 && c + b <= k) {
                            ap++;
                        }
                    }
                    all += k * k - 1 - ap;
                }
            }
            cout << k << " " << all / 2 << endl;
        }
    }
}
