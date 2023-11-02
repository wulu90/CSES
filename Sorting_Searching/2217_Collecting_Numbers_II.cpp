#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n, m, x, a, b;
    cin >> n >> m;

    unordered_map<int, int> n_i;
    unordered_map<int, int> i_n;

    for (int i = 1; i <= n; i++) {
        cin >> x;
        n_i.insert({x, i});
        i_n.insert({i, x});
    }

    vector<pair<int, int>> exch;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        exch.push_back({a, b});
    }

    int inx    = n_i[1];
    int rounds = 1;

    for (int num = 2; num <= n; num++) {
        if (n_i[num] < inx) {
            rounds++;
        }
        inx = n_i[num];
    }

    n_i.insert({-1, 0});
    n_i.insert({n + 1, n + 1});

    i_n.insert({0, -1});
    i_n.insert({n + 1, n + 1});

    for (int i = 0; i < m; i++) {
        a = exch[i].first;
        b = exch[i].second;

        int x1 = i_n[a];
        int x2 = i_n[b];

        int inx_x1_prev = n_i[x1 - 1];
        int inx_x1_next = n_i[x1 + 1];
        int inx_x2_prev = n_i[x2 - 1];
        int inx_x2_next = n_i[x2 + 1];

        n_i[x1] = b;
        n_i[x2] = a;
        i_n[a]  = x2;
        i_n[b]  = x1;

        // after swap position
        int inx_s_x1_prev = n_i[x1 - 1];
        int inx_s_x1_next = n_i[x1 + 1];
        int inx_s_x2_prev = n_i[x2 - 1];
        int inx_s_x2_next = n_i[x2 + 1];

        if ((inx_x1_prev < a && inx_s_x1_prev > b) || (inx_x2_prev < b && inx_s_x2_prev > a)) {
            rounds++;
        }
        if ((inx_x1_prev > a && inx_s_x1_prev < b) || (inx_x2_prev > b && inx_s_x2_prev < a)) {
            rounds--;
        }

        if ((inx_x1_next > a && inx_s_x1_next < b) || (inx_x2_next > b && inx_s_x2_next < a)) {
            rounds++;
        }
        if ((inx_x1_next < a && inx_s_x1_next > b) || (inx_x2_next < b && inx_s_x2_next > a)) {
            rounds--;
        }

        if (x1 + 1 == x2 && a < b) {
            rounds--;
        }

        if (x1 + 1 == x2 && a > b) {
            rounds++;
        }

        if (x1 - 1 == x2 && a > b) {
            rounds--;
        }
        if (x1 - 1 == x2 && a < b) {
            rounds++;
        }

        cout << rounds << endl;
    }

    return 0;
}