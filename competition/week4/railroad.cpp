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
unordered_set<int> seen;
int counter = 0;

void dfs(int cur, int last) {
    if (last != 0) {
        int a = min(cur, last);
        int b = max(cur, last);
        out[make_pair(a, b)].push_back(++counter); 
    }
    if (seen.find(cur) != seen.end())
        return;
    seen.insert(cur);
    for (int neigh : adj[cur]) {
        int a = min(cur, neigh);
        int b = max(cur, neigh);
        if (used[make_pair(a, b)] <= 0)
            continue;
        used[make_pair(a, b)]--;
        dfs(neigh, cur);
    }
}

int main() {
    cin >> n >> m;
    int start = 1;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (u > v) {
            swap(u, v);
        }
        used[make_pair(u, v)]++;
        edges.push_back(make_pair(u, v));
    }
    int cheat = 0;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1) {
            cheat ++;
            start = i;
        }
    } 
    if (cheat >= 2 && m >= 2) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    dfs(start, 0);
    for (int i = 0; i < edges.size(); i++) {
        cout << out[edges[i]].back() << "\n";
        out[edges[i]].pop_back();
    }
}
