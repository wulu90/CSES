#include <algorithm>
#include <iostream>
#include <vector>
 
int main() {
    u_int64_t n, a, b;
    std::cin >> n;
    std::vector<int> times;
    for (size_t i = 0; i < n; i++) {
        std::cin >> a >> b;
 
        if (b > times.size()) {
            times.resize(b);
        }
 
        for (u_int64_t j = a; j <= b; j++) {
            times[j]++;
        }
    }
 
    auto it = std::max_element(times.begin(), times.end());
    std::cout << *it << std::endl;
    return 0;
}