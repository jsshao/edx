#ifdef JUDGE
#include <fstream>
std::ifstream cin("railway.in");
std::ofstream cout("railway.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif
#include <stack>
#include <queue>
#include <deque>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string> 

using namespace std;

int mass[100001];
int MAX[100001];
int main() {
  int n, limit;
  cin >> n >> limit;
  unordered_map<int, int> pos;
  vector<int> sorted;
  for (int i = 0; i < n; ++i) {
    cin >> mass[i+1];
    pos[mass[i+1]] = i + 1;
    MAX[i+1] = max(MAX[i], mass[i+1]);
    sorted.push_back(mass[i+1]);
  }
  sort(sorted.begin(), sorted.end());

  for (int i = 0; i < n; i++) {
    if (pos[sorted[i]] <= i + 1)
      continue;
    int t = pos[sorted[i]];
    if (MAX[t-1] + mass[t] > limit) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
}
