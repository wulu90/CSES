#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n, x;
    cin >> n;
    unordered_map<int, int> n_i;

    for (int i = 0; i < n; i++) {
        cin >> x;
        n_i.insert({x, i});
    }

    int num    = 1;
    int inx    = n_i[num];
    int rounds = 1;
    for (int i = 2; i <= n; i++) {
        if (n_i[i] < inx) {
            rounds++;
        }
        num = i;
        inx = n_i[i];
    }

    cout << rounds << endl;
    return 0;
}