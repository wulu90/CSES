#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a;

    while (cin >> a && cin >> b) {
        if (max(a, b) > 2 * min(a, b)) {
            cout << "NO" << endl;
            continue;
        }

        if ((a + b) % 3 == 0) {
            cout << "YES" << endl;

        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
