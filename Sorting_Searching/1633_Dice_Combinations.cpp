#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int64_t> vec(n + 1);
    const int64_t mod = 1000000007;
    vec[0]            = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i >= j) {
                vec[i] = (vec[i] + vec[i - j]) % mod;
            }
        }
    }

    cout << vec[n] << endl;
    return 0;
}