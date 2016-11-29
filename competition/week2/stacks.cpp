#ifdef JUDGE
#include <fstream>
std::ifstream cin("stacks.in");
std::ofstream cout("stacks.out");
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
    int cups = 1, max = 1, stacks = 1;
    int n; cin >> n;
    int a; cin >> a;
    while (n-- > 1) {
        cin >> a;
        cups++;
        if (a != 0) {
            stacks++;
        }
        if (max * stacks < cups)
            max++;
    }
    cout << max << '\n';
    return 0;
}
