#include <iostream>
#include <vector>

using namespace std;

int64_t findmin(const vector<int64_t>& all, int64_t totalweight, int64_t currweight, int64_t inx) {
    if (inx == 0) {
        return abs((totalweight - currweight) - currweight);
    }

    return min(findmin(all, totalweight, currweight + all[inx], inx - 1), findmin(all, totalweight, currweight, inx - 1));
}

int main() {
    int64_t n, p;
    cin >> n;

    vector<int64_t> all;
    all.reserve(n);

    int64_t totalweight = 0;
    while (cin >> p) {
        all.push_back(p);
        totalweight += p;
    }

    cout << findmin(all, totalweight, 0, n - 1);
    return 0;
}