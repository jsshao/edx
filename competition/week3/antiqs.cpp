#ifdef JUDGE
#include <fstream>
std::ifstream cin("antiqs.in");
std::ofstream cout("antiqs.out");
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

int main() {
    int n; cin >> n;
    int a[n + 1];
    a[1] = 1;
    a[2] = 2;
    for (int i = 3; i <= n; i++) {
        int mid = (i + 1) / 2;
        int temp = a[mid];
        a[i] = temp;
        a[mid] = i;
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << '\n';
    return 0;
}
