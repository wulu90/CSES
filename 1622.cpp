#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    char c;
    string str;
    while (cin >> c) {
        str.push_back(c);
    }

    sort(str.begin(), str.end());
    vector<string> strvec;
    do {
        strvec.push_back(str);
    } while (next_permutation(str.begin(), str.end()));

    cout << strvec.size() << endl;
    for (auto& s : strvec) {
        cout << s << endl;
    }
    return 0;
}
