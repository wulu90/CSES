#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> vas(n);
    for (int i = 0; i < n; i++) {
        cin >> vas[i];
    }

    map<int, int> va_inx;

    for (int i = 0; i < n; i++) {
        if (va_inx.contains(x - vas[i])) {
            cout << i + 1 << " " << va_inx[x - vas[i]] + 1 << endl;
            return 0;
        } else {
            va_inx.insert({vas[i], i});
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}