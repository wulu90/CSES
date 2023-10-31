#include <cmath>
#include <iostream>
using namespace std;

int digit_query(int64_t n) {
    int64_t digits     = 1;
    int64_t digits_sum = 0;

    while (n > digits_sum + 9 * digits * static_cast<int64_t>(pow(10, digits - 1))) {
        digits_sum += 9 * digits * static_cast<int64_t>(pow(10, digits - 1));
        digits++;
    }

    int64_t mod      = (n - digits_sum) % digits;
    int64_t innumber = (n - digits_sum) / digits + static_cast<int64_t>(pow(10, digits - 1)) - (mod == 0 ? 1 : 0);

    int res = 0;

    int index = mod == 0 ? 0 : digits - mod;
    while (index >= 0) {
        res = innumber % 10;
        innumber /= 10;
        index--;
    }

    return res;
}

int main() {
    int q;
    int64_t k;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> k;
        cout << digit_query(k) << endl;
    }

    return 0;
}