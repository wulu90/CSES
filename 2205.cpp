#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> graycode(int n) {
    if (n == 1) {
        return {"0", "1"};
    } else {
        auto tmp = graycode(n - 1);
        int sum  = pow(2, n);
        vector<string> res(sum);
        for (int i = 0; i < tmp.size(); i++) {
            res[i]           = "0" + tmp[i];
            res[sum - 1 - i] = "1" + tmp[i];
        }
        return res;
    }
}

int main() {
    int n;
    cin >> n;

    for (auto& s : graycode(n)) {
        cout << s << endl;
    }

    return 0;
}
