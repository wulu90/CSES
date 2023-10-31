#include <iostream>

int main() {
    int n;
    std::cin >> n;
    if (n < 2 || n > 3) {
        for (int i = 2; i <= n; i += 2) {
            std::cout << i << " ";
        }
        for (int i = 1; i <= n; i += 2) {
            std::cout << i << " ";
        }
    } else {
        std::cout << "NO SOLUTION";
    }

    return 0;
}
