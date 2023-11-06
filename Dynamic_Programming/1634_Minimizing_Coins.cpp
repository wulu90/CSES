#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> money(x + 1, numeric_limits<int>::max());
    money[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - coins[j] >= 0 && money[i - coins[j]] != numeric_limits<int>::max()) {
                // if money[i - coins[j]] == numeric_limits<int>::max(), you can not make money at (i-coins[j])
                money[i] = min(money[i], money[i - coins[j]] + 1);
            }
        }
    }

    cout << (money[x] == numeric_limits<int>::max() ? -1 : money[x]) << endl;
    return 0;
}