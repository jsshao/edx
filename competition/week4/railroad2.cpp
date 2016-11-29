#ifdef JUDGE
#include <fstream>
std::ifstream cin("railroad.in");
std::ofstream cout("railroad.out");
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
#include <unordered_set>
#include <unordered_map>
#include <map>

int n, m;
vector<int> adj[50001];
vector<pair<int, int>> edges;
map<pair<int, int>, vector<int>> out;
map<pair<int, int>, int> used;
int counter;

void dfs(int cur, int &last) {
    for (int neigh : adj[cur]) {
        int a = min(cur, neigh);
        int b = max(cur, neigh);
        if (used[make_pair(a, b)] <= 0)
            continue;
        used[make_pair(a, b)]--;
        dfs(neigh, last);
    }
    if (last != 0) {
        int a = min(cur, last);
        int b = max(cur, last);
        out[make_pair(a, b)].push_back(counter--); 
    }
    last = cur;
}

int main() {
    cin >> n >> m;
    counter = m;
    int start = 1;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        start = u;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (u > v) {
            swap(u, v);
        }
        used[make_pair(u, v)]++;
        edges.push_back(make_pair(u, v));
    }
    int cheat = 0;
    int one = -1;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() % 2 == 1) {
            start = i;
            if (adj[i].size() == 1) {
                cheat ++;
                one = i;
            }
        }
    } 
    if (one != -1)
        start = one;
    if (cheat == 2 && m >= 2) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    int t = 0;
    dfs(start, t);
    for (int i = 0; i < edges.size(); i++) {
        cout << out[edges[i]].back() << "\n";
        out[edges[i]].pop_back();
    }
}
