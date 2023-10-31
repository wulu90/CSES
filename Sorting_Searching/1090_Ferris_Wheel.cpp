#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n, x, p;
    std::cin >> n;
    std::cin >> x;

    std::vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> weights[i];
    }
    int gondolas = 0;
    std::sort(weights.begin(), weights.end());

    if (weights[0] >= x) {
        gondolas = n;
        std::cout << gondolas << std::endl;
        return 0;
    }
    int overindex = n - 1;

    for (int i = n - 1; i >= 0; i--) {
        if (weights[i] < x) {
            overindex = i;
            break;
        }
    }
    gondolas += n - 1 - overindex;
    for (int i = overindex; i >= 0; i--) {
        if (weights[i] != 0) {
            gondolas++;
            for (int j = i - 1; j >= 0; j--) {
                if (weights[j] != 0 && weights[j] <= x - weights[i]) {
                    weights[j] = 0;
                    break;
                }
            }
        }
    }
    std::cout << gondolas << std::endl;
    return 0;
}
