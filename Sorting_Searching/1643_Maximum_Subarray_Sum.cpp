#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int64_t> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    int64_t curr = 0;
    int64_t best = numeric_limits<int>::min();

    for (int i = 0; i < n; i++) {
        curr = max(vec[i], vec[i] + curr);
        best = max(curr, best);
    }

    cout << best << endl;
    return 0;
}