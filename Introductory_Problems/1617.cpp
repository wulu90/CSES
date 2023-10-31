#include <cmath>
#include <cstdint>
#include <iostream>

using namespace std;

int64_t mod(int64_t n) {
    if (n < 63) {
        return (1LL << n) % 1000000007;
    } else {
        return (((1LL << 62) % 1000000007) * (mod(n - 62))) % 1000000007;
    }
}

int main() {
    int n;
    cin >> n;
    int64_t aa = mod(n);
    cout << aa << endl;
    return 0;
}
