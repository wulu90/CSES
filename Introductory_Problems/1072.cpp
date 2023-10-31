#include <iostream>
#include <vector>
using namespace std;

/**
 * each 3x2 or 2*3 boards has 2 ways that two knights attack each other
 * |---------------
 * |  * |    |  & |
 * |---------------
 * | &  |    |  * |
 * |---------------
 *
 *  (n-1)*(n-2)
 */

int main() {
    int64_t n;
    cin >> n;

    cout << 0 << endl;
    for (int64_t i = 2; i <= n; i++) {
        cout << i * i * (i * i - 1) / 2 - 4 * (i - 2) * (i - 1) << endl;
    }
}
