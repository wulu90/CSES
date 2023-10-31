#include <algorithm>
#include <iostream>
#include <unordered_set>
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

    std::unordered_set<int> rms;    // remove index;

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
        if (!rms.contains(i)) {
            gondolas++;
            for (int j = i - 1; j >= 0; j--) {
                if (!rms.contains(j) && weights[j] <= x - weights[i]) {
                    rms.insert(j);
                    break;
                }
            }
        }
    }
    std::cout << gondolas << std::endl;
    return 0;
}
