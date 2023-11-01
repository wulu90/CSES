#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, a, b;
    cin >> n;
    vector<pair<int, int>> movies;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        movies.push_back({b, a});
    }

    sort(movies.begin(), movies.end());

    int curr   = movies[0].first;
    int watchs = 1;

    for (int i = 1; i < n; i++) {
        if (movies[i].second >= curr) {
            watchs++;
            curr = movies[i].first;
        }
    }

    cout << watchs << endl;
}