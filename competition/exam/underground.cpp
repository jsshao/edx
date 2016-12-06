#ifdef JUDGE
#include <fstream>
std::ifstream cin("underground.in");
std::ofstream cout("underground.out");
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

struct pairhash {
 public:
    template <typename T, typename U>
          std::size_t operator()(const std::pair<T, U> &x) const
            {
                  return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
                    }
};

int n, m, k;
vector<int> nodes[100001];
unordered_map<pair<int, int>, vector<int>, pairhash> adj;

unordered_set<int> seen[100001];
int count1;

void dfs(unordered_set<int> &hack, int cur, int k) {
  if (hack.count(cur) == 1)
    return;
  hack.insert(cur);
  for (int v : adj[make_pair(cur, k)])
    dfs(hack, v, k);
}

int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int a, b, c; cin >> a >> b >> c;
    adj[make_pair(a, c)].push_back(b);
    adj[make_pair(b, c)].push_back(a);
    nodes[c].push_back(a);
    nodes[c].push_back(b);
  }
  for (int i = 1; i <= k; ++i) {
    count1 = 0;
    unordered_set<int> hack;
    for (int v : nodes[i]) {
      if (hack.count(v) != 1) {
        count1++;
        dfs(hack, v, i); 
      }
    }
    cout << count1 << '\n';
  }
}
