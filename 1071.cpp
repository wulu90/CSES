#include <iostream>

int64_t spiral(int64_t y, int64_t x) {
    int64_t res = 0;
    if (y >= x) {
        if (y % 2 == 0) {
            res = y * y - (x - 1);
        } else {
            res = (y - 1) * (y - 1) + 1 + (x - 1);
        }
    } else {
        if (x % 2 == 0) {
            res = (x - 1) * (x - 1) + 1 + (y - 1);
        } else {
            res = x * x - (y - 1);
        }
    }
    return res;
}

int main() {
    int y, x;
    std::cin >> y;
    while (std::cin >> y && std::cin >> x) {
        std::cout << spiral(y, x) << std::endl;
    }
    return 0;
}
