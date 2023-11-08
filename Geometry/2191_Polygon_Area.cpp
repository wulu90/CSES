#include <iostream>
#include <vector>
using namespace std;

int main() {
    int64_t n, x, y;
    cin >> n;
    vector<pair<int64_t, int64_t>> vertex;

    for (int64_t i = 0; i < n; i++) {
        cin >> x >> y;
        vertex.push_back({x, y});
    }
    vertex.push_back(vertex[0]);
    int64_t area = 0;
    for (int i = 0; i < n; i++) {
        auto& [x1, y1] = vertex[i];
        auto& [x2, y2] = vertex[i + 1];

        area += x1 * y2 - y1 * x2;
    }

    cout << abs(area) << endl;
    return 0;
}