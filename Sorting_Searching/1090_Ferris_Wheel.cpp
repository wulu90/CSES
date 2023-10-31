#include <iostream>
#include <map>
#include <vector>

int main() {
    int n, x, p;
    std::cin >> n;
    std::cin >> x;
    std::map<int, int> weight_num;
    while (std::cin >> p) {
        weight_num[p] += 1;
    }

    int gondolas = 0;

    for (auto it = weight_num.rbegin(); it != weight_num.rend(); it++) {
        for (int i = 0; i < it->second;) {
            gondolas++;
            it->second--;
            int dist = 0;

            if (x - it->first >= weight_num.begin()->first) {
                auto lb = weight_num.lower_bound(x - it->first);
                if (lb != weight_num.end()) {
                    dist = std::distance(weight_num.begin(), lb);
                } else {
                    dist = std::distance(it, weight_num.rend());
                }

                for (int j = dist; j >= 0; j--) {
                    auto it_s = std::next(weight_num.begin(), j);
                    if (it_s->first <= x - it->first && it_s->second != 0) {
                        it_s->second--;
                        break;
                    }
                }
            }
        }
    }
    std::cout << gondolas << std::endl;
    return 0;
}
