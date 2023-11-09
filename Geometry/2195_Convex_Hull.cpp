#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct vec {
    int64_t a, b;

    int64_t cross_product(const vec& rhs) {
        return a * rhs.b - rhs.a * b;
    }
};

struct point {
    int64_t x, y;

    bool operator<(const point& p) const {
        if (x == p.x) {
            return y < p.y;
        } else {
            return x < p.x;
        }
    }

    vec operator-(const point& rhs) const {
        vec v;
        v.a = x - rhs.x;
        v.b = y - rhs.y;
        return v;
    }
};

int main() {
    int n;
    cin >> n;
    vector<point> points(n);

    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    sort(points.begin(), points.end());

    vector<int> convex(n + 1);    // point index in points vector; first and last point in convex hull is duplicate;

    int num = 0;    // convex.size();
    for (int i = 0; i < n; i++) {
        while (num > 1 && (points[convex[num - 1]] - points[convex[num - 2]]).cross_product(points[i] - points[convex[num - 1]]) < 0) {
            num--;
        }
        convex[num++] = i;
    }
    // first and last point in points vector should in convex hull
    // first, calc the bottom convex
    // then calc the top convex
    // because problem request all points lie on convex hull, so the vector cross product less than zero ,not not greater than zero.
    int tmp = num;
    for (int i = n - 2; i >= 0; i--) {
        while (num > tmp && (points[convex[num - 1]] - points[convex[num - 2]]).cross_product(points[i] - points[convex[num - 1]]) < 0) {
            num--;
        }
        convex[num++] = i;
    }

    // first and last point in convex hull is duplicate;
    cout << num - 1 << endl;
    for (int i = 0; i < num - 1; i++) {
        cout << points[convex[i]].x << " " << points[convex[i]].y << endl;
    }

    return 0;
}