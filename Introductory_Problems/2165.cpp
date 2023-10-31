#include <cmath>
#include <iostream>

using namespace std;

void hanoi(int disks, int src, int tmp, int dest) {
    if (disks > 0) {
        hanoi(disks - 1, src, dest, tmp);
        cout << src << " " << dest << endl;
        hanoi(disks - 1, tmp, src, dest);
    }
}

int main() {
    int n;
    cin >> n;
    cout << pow(2, n) - 1 << endl;
    hanoi(n, 1, 2, 3);
    return 0;
}
