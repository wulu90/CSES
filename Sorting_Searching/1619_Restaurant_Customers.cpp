#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

int main() {
    u_int64_t n, a, b;
    std::cin >> n;
    std::vector<int> times;
    std::vector<std::pair<int, int>> customers(n);
    u_int64_t mintime = std::numeric_limits<u_int64_t>::max();
    u_int64_t maxtime = 0;
    for (size_t i = 0; i < n; i++) {
        std::cin >> a >> b;
        customers[i].first  = a;
        customers[i].second = b;
        if (a < mintime) {
            mintime = a;
        }
        if (b > maxtime) {
            maxtime = b;
        }
    }

    times.resize(maxtime - mintime + 1);

    for (auto& [a, b] : customers) {
        for (size_t i = a - mintime; i <= b - mintime; i++) {
            times[i]++;
        }
    }

    auto it = std::max_element(times.begin(), times.end());
    std::cout << *it << std::endl;
    return 0;
}