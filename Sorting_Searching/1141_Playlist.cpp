#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    int curr = 0;
    int best = 0;

    int lastindex = 0;
    map<int, int> n_i;
    for (int i = 0; i < n; i++) {
        if (n_i.contains(vec[i]) && n_i[vec[i]] >= lastindex) {
            curr      = i - lastindex;
            best      = max(curr, best);
            lastindex = n_i[vec[i]] + 1;
        }
        n_i[vec[i]] = i;
    }

    best = max(n - lastindex, best);
    cout << best << endl;

    return 0;
}