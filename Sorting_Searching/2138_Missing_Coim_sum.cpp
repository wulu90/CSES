#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end());

    if (coins[0] != 1) {
        cout << 1 << endl;
        return 0;
    }

    int64_t currmax = 1;

    for (int i = 1; i < n; i++) {
        if (currmax + 1 >= coins[i]) {
            currmax += coins[i];
        } else {
            break;
        }
    }

    cout << currmax + 1 << endl;

    return 0;
}