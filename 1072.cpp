#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> attacks{{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};

    if (n == 1) {
        cout << 0 << endl;
    } else if (n == 2) {
        cout << 0 << endl;
        cout << 6 << endl;

    } else {
        cout << 0 << endl;
        cout << 6 << endl;
        for (int k = 3; k <= n; k++) {
            int64_t qd = 0;

            for (int r = 1; r <= k / 2; r++) {
                for (int c = 1; c <= k / 2; c++) {
                    int ap = 0;
                    for (auto& [a, b] : attacks) {
                        if (r + a >= 1 && r + a <= k && c + b >= 1 && c + b <= k) {
                            ap++;
                        }
                    }
                    qd += k * k - 1 - ap;
                }
            }
            int64_t mid     = 0;
            int64_t mid_mid = 0;
            if (k % 2 != 0) {
                for (int i = 1; i <= k; i++) {
                    int ap = 0;
                    for (auto& [a, b] : attacks) {
                        if (i + a >= 1 && i + a <= k && k / 2 + 1 + b >= 1 && k / 2 + 1 + b <= k) {
                            ap++;
                        }
                    }
                    mid += k * k - 1 - ap;
                    if (i == k / 2 + 1) {
                        mid_mid = k * k - 1 - ap;
                    }
                }
            }

            int64_t all = k % 2 == 0 ? qd * 2 : qd * 2 + mid - mid_mid / 2;
            cout << all << endl;
        }
    }
}
