#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q, a, b;
    cin >> n >> q;
    vector<int64_t> vec(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> vec[i];
    }

    vector<pair<int, int>> queries;

    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        queries.push_back({a, b});
    }

    vector<int64_t> prefixsum(n + 1);

    for (int i = 1; i <= n; i++) {
        prefixsum[i] = prefixsum[i - 1] + vec[i];
    }

    for (auto& [l, r] : queries) {
        cout << prefixsum[r] - prefixsum[l - 1] << endl;
    }

    return 0;
}