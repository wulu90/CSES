#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, b;
    cin >> n;

    vector<pair<int, int>> times;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;

        times.push_back({a, 1});
        times.push_back({b, -1});
    }

    sort(times.begin(), times.end());

    int currs = 0;
    int maxcu = 0;

    for (const auto& [t, s] : times) {
        currs += s;
        maxcu = max(maxcu, currs);
    }

    cout << maxcu << endl;

    return 0;
}