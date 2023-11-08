#include <iostream>

using namespace std;

int main() {
    int64_t n, x1, x2, x3, x4, x5, x6;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1 >> x2 >> x3 >> x4 >> x5 >> x6;

        if ((x3 - x1) * (x6 - x2) - (x4 - x2) * (x5 - x1) > 0) {
            cout << "LEFT" << endl;
        } else if ((x3 - x1) * (x6 - x2) - (x4 - x2) * (x5 - x1) < 0) {
            cout << "RIGHT" << endl;
        } else {
            cout << "TOUCH" << endl;
        }
    }
    return 0;
}