#include <iostream>

using namespace std;

bool line_segment_intersection(int64_t x1, int64_t y1, int64_t x2, int64_t y2, int64_t x3, int64_t y3, int64_t x4, int64_t y4) {
    bool intersection = false;
    const int64_t mod = 1000000007;
    if (min(x1, x2) > max(x3, x4) || max(x1, x2) < min(x3, x4) || (min(y1, y2) > max(y3, y4) || (max(y1, y2) < min(y3, y4)))) {
        intersection = false;
    } else {
        if ((((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)) % mod) * (((x2 - x1) * (y4 - y1) - (y2 - y1) * (x4 - x1)) % mod) <= 0 &&
            (((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) % mod) * (((x4 - x3) * (y2 - y3) - (y4 - y3) * (x2 - x3)) % mod) <= 0) {
            intersection = true;
        }
    }

    return intersection;
}

int main() {
    int64_t n, x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if (line_segment_intersection(x1, y1, x2, y2, x3, y3, x4, y4)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}