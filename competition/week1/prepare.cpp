#ifdef JUDGE
#include <fstream>
std::ifstream cin("prepare.in");
std::ofstream cout("prepare.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif
using namespace std;
  
int main() {
	int n; cin >> n;	
    int ans = 0;
    bool a = false, b = false;
    int t[n], p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < n; i++) {
        if (p[i] >= t[i]) {
            ans += p[i];
            a = true;
        } else {
            ans += t[i];
            b = true;
        }
    }
    if (!a) {
        int max = -1000;
        for (int i = 0; i < n; i++) {
            max = (p[i] - t[i] > max) ? (p[i] - t[i]) : max;
        }
        ans += max;
    }
    if (!b) {
        int max = -1000;
        for (int i = 0; i < n; i++) {
            max = (t[i] - p[i] > max) ? (t[i] - p[i]) : max;
        }
        ans += max;
    }
    cout << ans << endl;
    return 0;
}
