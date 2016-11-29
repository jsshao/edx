#ifdef JUDGE
#include <fstream>
std::ifstream cin("scarecrow.in");
std::ofstream cout("scarecrow.out");
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
#include <unordered_map>

int main() {
    int n, k; cin >> n >> k; 
    int a[n];
    vector<int> b[k];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i % k].push_back(a[i]);
    }
    sort(a, a + n);
    for (int i = 0; i < k; i++) {
        sort(b[i].begin(), b[i].end());
    }
    for (int i = 0; i < k; i++) {
        int j = i;
        while (j < n) {
            if (a[j] != b[i][j / k]) {
                cout << "NO\n";
                return 0;
            }
            j += k;
        }
    }
    cout << "YES\n";
    return 0;
}
