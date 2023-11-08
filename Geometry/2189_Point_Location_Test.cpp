#include <iostream>

using namespace std;

int main() {
    int64_t n, x1, y1, x2, y2, x3, y3;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        if ((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1) > 0) {
            cout << "LEFT" << endl;
        } else if ((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1) < 0) {
            cout << "RIGHT" << endl;
        } else {
            cout << "TOUCH" << endl;
        }
    }
    return 0;
}