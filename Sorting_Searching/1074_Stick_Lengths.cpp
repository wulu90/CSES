#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int64_t> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    int64_t median = n % 2 == 0 ? (vec[n / 2] + vec[n / 2 - 1]) / 2 : vec[n / 2];

    int64_t total = 0;

    for (auto len : vec) {
        total += abs(len - median);
    }

    cout << total << endl;
    return 0;
}