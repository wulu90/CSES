#include <iostream>
#include <map>
using namespace std;

int main() {
    char a;
    map<char, int> ch_count;

    while (cin >> a) {
        ch_count[a] += 1;
    }

    int odds = 0;
    int sum  = 0;
    for (auto& [a, c] : ch_count) {
        if (c % 2 != 0) {
            odds += 1;
        }
        sum += c;
    }

    if (odds > 1) {
        cout << "NO SOLUTION";
    } else {
        if (ch_count.size() == 1) {
            for (int i = 0; i < ch_count.begin()->second; i++) {
                cout << ch_count.begin()->first;
            }
        } else {
            char oddindex = 'Z' + 1;

            for (auto it = ch_count.begin(); it != ch_count.end(); it++) {
                if (it->second % 2 == 0) {
                    for (int i = 0; i < it->second / 2; i++) {
                        cout << it->first;
                    }
                } else {
                    oddindex = it->first;
                }
            }

            if (oddindex != 'Z' + 1) {
                for (int i = 0; i < ch_count[oddindex]; i++) {
                    cout << oddindex;
                }
            }

            for (auto it = ch_count.rbegin(); it != ch_count.rend(); it++) {
                if (it->second % 2 == 0) {
                    for (int i = 0; i < it->second / 2; i++) {
                        cout << it->first;
                    }
                }
            }
        }
    }
    return 0;
}
