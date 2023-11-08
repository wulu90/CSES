#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int64_t, int64_t>> points(n);

    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    int64_t mindist = 0x7fffffffffffffff;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            auto& [x1, y1] = points[i];
            auto& [x2, y2] = points[j];
            if ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) < mindist) {
                mindist = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
            }
        }
    }
    cout << mindist << endl;
    return 0;
}