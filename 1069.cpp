#include <iostream>

int main() {
    char p;
    char n;
    std::cin >> p;
    int count = 1;
    int max   = 0;
    while (std::cin >> n) {
        if (n == p) {
            count += 1;
        } else {
            if (count > max) {
                max = count;
            }
            count = 1;
        }
        p = n;
    }
    if (count > max)
        max = count;
    std::cout << max;
    return 0;
}
