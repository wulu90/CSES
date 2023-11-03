#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

struct range {
    int l, r, i;

    bool operator<(const range& rhs) const {
        if (l == rhs.l) {
            return r > rhs.r;
        }
        return l < rhs.l;
    }
};

int main() {
    int n;
    cin >> n;

    vector<range> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i].l >> vec[i].r;
        vec[i].i = i;
    }

    sort(vec.begin(), vec.end());

    vector<bool> contains(n);
    vector<bool> contained(n);

    int max_r = 0;

    for (auto& r : vec) {
        if (r.r > max_r) {
            max_r = r.r;
        } else {
            contained[r.i] = true;
        }
    }

    int min_r = numeric_limits<int>::max();

    for (auto it = vec.rbegin(); it != vec.rend(); it++) {
        if (it->r < min_r) {
            min_r = it->r;
        } else {
            contains[it->i] = true;
        }
    }

    for (auto b : contains) {
        cout << b << " ";
    }
    cout << endl;

    for (auto b : contained) {
        cout << b << " ";
    }
    cout << endl;
    return 0;
}