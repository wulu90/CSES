#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n, x;
    cin >> n;
    unordered_map<int, int> n_i;

    for (int i = 1; i <= n; i++) {
        cin >> x;
        n_i.insert({x, i});
    }

    int inx    = n_i[1];
    int rounds = 1;

    for (int num = 2; num <= n; num++) {
        if (n_i[num] < inx) {
            rounds++;
        }
        inx = n_i[num];
    }

    cout << rounds << endl;
    return 0;
}