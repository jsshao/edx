#ifdef JUDGE
#include <fstream>
std::ifstream cin("fence.in");
std::ofstream cout("fence.out");
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

int main() {
    int n, k; cin >> n >> k;
    int limit = k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        limit = min(limit, a[i]);
    }
    int l = 0, r = k;
    sort(a, a + n);
    int best = 0;
    while (l <= r) {
        int m = l - (l - r) / 2;
        if (m > limit) {
            r = m - 1;
            continue;
        }
        int free = 0;
        for (int i = 0; i < n; i++) {
            free = max(a[i], free + m);
            if (free > k) {
                break;
            }
        }
        if (free > k) {
            r = m - 1;
        } else {
            best = max(best, m);
            l = m + 1;
        }
    }
    cout << best << '\n';
    return 0;
}
