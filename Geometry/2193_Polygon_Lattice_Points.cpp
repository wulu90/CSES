#include <iostream>
#include <vector>

using namespace std;

// https://en.wikipedia.org/wiki/Pick's_theorem

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int lattice_points_onside(int x1, int y1, int x2, int y2) {
    int a = x2 - x1;
    int b = y2 - y1;
    return gcd(a, b);
}

int main() {
    int n;
    cin >> n;
    vector<pair<int64_t, int64_t>> vertex(n);
    for (int i = 0; i < n; i++) {
        cin >> vertex[i].first >> vertex[i].second;
    }
    vertex.push_back(vertex[0]);

    int64_t area            = 0;
    int64_t points_boundary = 0;
    for (int i = 0; i < n; i++) {
        auto& [x1, y1] = vertex[i];
        auto& [x2, y2] = vertex[i + 1];

        area += x1 * y2 - y1 * x2;
        points_boundary += abs(lattice_points_onside(x1, y1, x2, y2));
    }
    area = abs(area) / 2;

    // https://en.wikipedia.org/wiki/Pick's_theorem
    int64_t points_interior = area + 1 - points_boundary / 2;

    cout << points_interior << " " << points_boundary << endl;

    return 0;
}