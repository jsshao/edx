#ifdef JUDGE
#include <fstream>
std::ifstream cin("cars.in");
std::ofstream cout("cars.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif
#include <stack>
#include <queue>
#include <deque>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
  int n; cin >> n;
  queue<long long> q;
  unordered_map<long long, int> tree;
  long long sum = 0;
  int len = 0;
  for (int i = 0; i < n; i++) {
    char c; cin >> c;
    if (c == '+') {
      ++len;
      long long t; cin >> t;
      tree[t]++;
      sum += t;
      q.push(t);
    } else if (c == '-') {
      --len;
      long long t = q.front();
      tree[t]--;
      sum -= t;
      q.pop();
    } else {
      if (sum / q.size() * q.size() == sum)
        cout << tree[sum/q.size()] << '\n';
      else 
        cout << 0 << '\n';
    }
  }
}
