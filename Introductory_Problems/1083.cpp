#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    int v;
    cin >> n;

    vector<bool> all(n + 1, false);
    while (cin >> v) {
        all[v] = true;
    }
    for (int i = 1; i < n + 1; i++) {
        if (!all[i]) {
            cout << i;
            break;
        }
    }
    return 0;
}
