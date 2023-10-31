#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, x;
    std::cin >> n;
    std::cin >> x;

    std::vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> weights[i];
    }
    std::sort(weights.begin(), weights.end());

    int gondolas = n;

    int i = 0;
    int j = n - 1;

    while (i < j) {
        if (weights[i] + weights[j] > x) {
            j--;

        } else {
            i++;
            j--;
            gondolas--;
        }
    }

    std::cout << gondolas << std::endl;
    return 0;
}
