#ifdef JUDGE
#include <fstream>
std::ifstream cin("sort.in");
std::ofstream cout("sort.out");
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

unordered_map<int, int> pos;
int l[101];

int main() {
  int n; cin >> n;
  stringstream convert; 
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    pos[t] = i + 1;
    l[i+1] = t;
  }

  int count = 0;
  for (int i = 1; i <= n; i++) {
    while (pos[i] != i) {
      ++ count;
      int bad = l[i];
      // swap bad with bad - 1
      int temp = pos[bad-1];
      //buffer += itoa(i) + " " + itoa(temp) + '\n';
      convert << i << " " << temp << '\n';
      pos[bad-1] = i;
      pos[bad] = temp;
      l[i] = bad - 1;
      l[temp] = bad;
    }
  }
  cout << count << endl << convert.str();
}
