#include <iostream>
#include <queue>
#include <vector>

int main() {
    int n, m, h;
    std::cin >> n >> m;

    std::priority_queue<int> tickets;
    std::vector<int> customer_willings(m);

    for (int i = 0; i < n; i++) {
        std::cin >> h;
        tickets.push(h);
    }

    for (int i = 0; i < m; i++) {
        std::cin >> customer_willings[i];
    }

    std::vector<int> overs;
    for (size_t i = 0; i < customer_willings.size(); i++) {
        bool buyticket = false;
        while (!tickets.empty()) {
            if (tickets.top() > customer_willings[i]) {
                overs.push_back(tickets.top());
                tickets.pop();
            } else {
                std::cout << tickets.top() << std::endl;
                tickets.pop();
                buyticket = true;
                break;
            }
        }
        if (!buyticket) {
            std::cout << -1 << std::endl;
        }
        for (auto t : overs) {
            tickets.push(t);
        }
    }

    return 0;
}