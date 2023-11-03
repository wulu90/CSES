#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    const int mod = 1000000007;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> money(x + 1);
    money[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - coins[j] >= 0 && money[i - coins[j]] != 0) {
                money[i] = (money[i] + money[i - coins[j]]) % mod;
            }
        }
    }
    cout << money[x] << endl;
    return 0;
}