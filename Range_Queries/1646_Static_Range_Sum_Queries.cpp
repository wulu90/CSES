#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q, a, b;
    cin >> n >> q;
    vector<int> vec(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> vec[i];
    }
    vector<pair<int, int>> queries;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        queries.push_back({a, b});
    }

    for (auto& [x1, x2] : queries) {
        int64_t sum = 0;
        for (int i = x1; i <= x2; i++) {
            sum += vec[i];
        }
        cout << sum << endl;
    }
    return 0;
}