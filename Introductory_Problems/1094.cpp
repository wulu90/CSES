#include <iostream>

int main() {
    int n, p;
    std::cin >> p;
    std::cin >> p;
    int64_t res = 0;
    while (std::cin >> n) {
        if (n < p) {
            res += (p - n);
        } else {
            p = n;
        }
    }
    std::cout << res;
    return 0;
}
