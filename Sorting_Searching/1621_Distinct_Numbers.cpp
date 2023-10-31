#include <iostream>
#include <set>

int main() {
    int n;
    int x;
    std::cin >> n;
    std::set<int> distinct_num;
    while (std::cin >> x) {
        distinct_num.insert(x);
    }
    std::cout << distinct_num.size() << std::endl;
}