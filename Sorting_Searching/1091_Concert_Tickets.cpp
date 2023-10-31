#include <iostream>
#include <set>
#include <vector>

int main() {
    int n, m, h;
    std::cin >> n >> m;

    std::multiset<int> tickets;

    std::vector<int> customer_willings(m);

    for (int i = 0; i < n; i++) {
        std::cin >> h;
        tickets.insert(h);
    }

    for (int i = 0; i < m; i++) {
        std::cin >> customer_willings[i];
    }

    for (int i = 0; i < m; i++) {
        auto it = tickets.upper_bound(customer_willings[i]);
        if (it == tickets.begin()) {
            std::cout << -1 << std::endl;
        } else {
            std::cout << *(--it) << std::endl;
            tickets.erase(it);
        }
    }

    return 0;
}