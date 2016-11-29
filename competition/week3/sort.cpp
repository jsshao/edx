#ifdef JUDGE
#include <fstream>
std::ifstream cin("sort.in");
std::ofstream cout("sort.out");
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

void mergesort(int *a, int l, int k) {
    if (l == k) {
        cout << l+1 << " " << k+1 << " ";
        cout << a[l] << " " << a[l] << '\n';
        return;
    }
    int b[k - l + 1];
    int m = l - (l - k) / 2;
    mergesort(a, l, m);
    mergesort(a, m + 1, k);
    int i = l, j = m + 1, t = 0;
    while (i <= m && j <= k) {
        if (a[i] < a[j])
            b[t++] = a[i++];
        else
            b[t++] = a[j++];
    }
    while (i <= m)
        b[t++] = a[i++];
    while (j <= k)
        b[t++] = a[j++];
    for (int i = l; i <= k; i++) {
        a[i] = b[i-l];
    }
    cout << l+1 << " " << k+1 << " ";
    cout << a[l] << " " << a[k] << '\n';
}
  
int main() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    mergesort(a, 0, n-1); 
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << '\n';
    return 0;
}
