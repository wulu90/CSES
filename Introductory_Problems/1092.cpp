#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n * (n + 1) / 2 % 2 == 0) {
        cout << "YES" << endl;
        if (n / 2 % 2 == 0) {
            cout << n / 2 << endl;
            for (int i = 1; i <= n / 4; i++) {
                cout << i << " ";
                cout << n + 1 - i << " ";
            }
            cout << endl;
            cout << n / 2 << endl;
            for (int i = n / 4 + 1; i <= n / 2; i++) {
                cout << i << " ";
                cout << n + 1 - i << " ";
            }
            cout << endl;
        } else {
            cout << n / 2 << endl;
            int k = (n - 1) / 4;
            for (int i = 0; i < k; i++) {
                cout << 2 + i << " ";
                cout << n - i << " ";
            }
            cout << 2 + (n - 1) / 2 << endl;

            cout << n / 2 + 1 << endl;
            cout << 1 << " ";
            for (int i = 0; i < k; i++) {
                cout << 2 + k + i << " ";
                cout << n - k - i << " ";
            }
            cout << 1 + (n - 1) / 2 << endl;
        }
    } else {
        cout << "NO";
    }
}
