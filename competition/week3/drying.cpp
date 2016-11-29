#ifdef JUDGE
#include <fstream>
std::ifstream cin("drying.in");
std::ofstream cout("drying.out");
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

/*
int main() {
    int n; cin >> n;
    int temp;
    int min = 0;
    int k;
    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        q.push(temp);
    }
    cin >> k;
    for (;;) {
        if (q.top() - min <= 0) {
            break;
        }
        int top = q.top();
        q.pop();
        q.push(top - (k-1));
        min++;
    }
    cout << min << '\n';
}
*/

int main() {
    int n; cin >> n;
    int a[n], k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    } cin >> k;
    int l = 1, r = 1000000001;
    int best = r;
    while (l <= r) {
        int m = l - (l - r) / 2;
        int used = 0;
        // check if m minutes is doable        
        for (int i = 0; i < n; i++) {
            int remaining = a[i] - m;
            if (remaining > 0) {
                if (k == 1) {
                    used = m + 1;
                    break;
                }
                used += ceil(((double)remaining) / (k - 1.0));
                if (used > m)
                    break;
            }
        }
        if (used > m) {
            l = m + 1;
        } else {
            if (m < best)
                best = m;
            r = m - 1;
        }
    }
    cout << best << '\n';
    return 0;
}
