#ifdef JUDGE
#include <fstream>
std::ifstream cin("k.in");
std::ofstream cout("k.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif
using namespace std;
#include <stack>
#include <queue>
#include <deque>
#include <cstdlib>
#include <cmath>
#include <algorithm>

int n, k;
double target;

struct jewel {
    int v, w, i;
    double r;
    bool operator < (const jewel &b) const {
        return v - target * w > b.v - target * b.w;
    }
};

bool doable(jewel *a) {
    partial_sort(a, a + k, a + n);
    double sum = 0;
    for (int i = 0; i < k; i++)
        sum += a[i].v - target * a[i].w;
    return sum >= 0;
}

int main() {
    cin >> n >> k;
    jewel a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].v >> a[i].w;
        a[i].i = i + 1;
    }
    double l = 0, r = 10000001;
    for (int i = 0; i < 50; i++) {
        target = (l + r) / 2.0;
        if (doable(a)) {
            l = target;
        } else {
            r = target;
        }
    }
    for (int i = 0; i < k; i++) {
        cout << a[i].i << " ";
    } cout << '\n';

    return 0;
}
