#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> tickets(n);

    std::vector<int> customer_willings(m);

    for (int i = 0; i < n; i++) {
        std::cin >> tickets[i];
    }
    std::sort(tickets.begin(), tickets.end());

    for (int i = 0; i < m; i++) {
        std::cin >> customer_willings[i];
    }

    std::unordered_set<int> sold;

    int min_price = tickets[0];
    int min_index = 0;

    for (size_t i = 0; i < customer_willings.size(); i++) {
        if (sold.size() == static_cast<size_t>(n) || customer_willings[i] < min_price) {
            std::cout << -1 << std::endl;
            continue;
        } else {
            auto lb  = std::upper_bound(tickets.begin(), tickets.end(), customer_willings[i]);
            int dist = lb - tickets.begin();
            for (int j = dist - 1; j >= 0; j--) {
                if (!sold.contains(j) && tickets[j] <= customer_willings[i]) {
                    std::cout << tickets[j] << std::endl;
                    sold.insert(j);

                    if (tickets[j] == min_price) {
                        for (int k = min_index; k < n; k++) {
                            if (!sold.contains(k)) {
                                min_price = tickets[k];
                                min_index = k;
                                break;
                            }
                        }
                    }

                    break;
                }
            }
        }
    }

    return 0;
}