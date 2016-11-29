#ifdef JUDGE
#include <fstream>
std::ifstream cin("inversions.in");
std::ofstream cout("inversions.out");
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

void mergesort(int *a, int l, int k, long long int& ans) {
    if (l == k) {
        return;
    }
    int b[k - l + 1];
    int m = l - (l - k) / 2;
    mergesort(a, l, m, ans);
    mergesort(a, m + 1, k, ans);
    int i = l, j = m + 1, t = 0;
    while (i <= m && j <= k) {
        if (a[i] <= a[j])
            b[t++] = a[i++];
        else {
            ans += m - i + 1;
            b[t++] = a[j++];
        }
    }
    while (i <= m)
        b[t++] = a[i++];
    while (j <= k)
        b[t++] = a[j++];
    for (int i = l; i <= k; i++) {
        a[i] = b[i-l];
    }
}
  
int main() {
    int n; cin >> n;
    int a[n];
    long long int ans = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    mergesort(a, 0, n-1, ans); 
    cout << ans << '\n';
    return 0;
}
