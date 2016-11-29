#ifdef JUDGE
#include <fstream>
std::ifstream cin("kth.in");
std::ofstream cout("kth.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif
using namespace std;
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cstdlib>

int main() {
    int n, k1, k2; cin >> n >> k1 >> k2;
    int A, B, C, a1, a2; cin >> A >> B >> C >> a1 >> a2;
    int *arr = new int[n + 1];
    arr[1] = a1;
    arr[2] = a2;
    for (int i = 3; i <= n ; i++) {
        arr[i] = A*arr[i-2] + B*arr[i-1] + C;
    }
    std::nth_element (arr + 1, arr + k1, arr + n + 1);
    if (k1 == k2) {
        cout << arr[k1] << '\n';
        return 0;
    }
    std::nth_element (arr + k1 + 1, arr + k2, arr + n + 1);
    std::sort(arr + k1, arr + k2 + 1);
    for (int i = k1; i <= k2; i++) {
        cout << arr[i] << " ";
    } cout << '\n';

    return 0;
}
