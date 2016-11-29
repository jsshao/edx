#ifdef JUDGE
#include <fstream>
std::ifstream cin("bipartite.in");
std::ofstream cout("bipartite.out");
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

vector<int> edges[100001];
bool color[100001];
unordered_set<int> seen;
int n, m;

void dfs(int node, bool col) {
    if (seen.find(node) != seen.end()) {
        if (color[node] != col) {
            cout << "NO\n";
            exit(0);
        }
    } else {
        color[node] = col;
        seen.insert(node);
        for (int neigh : edges[node]) {
            dfs(neigh, col ^ 1);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }    

    for (int i = 1; i <= n; i++) {
        if (seen.find(i) == seen.end()) {
            dfs(i, 0);
        }
    }
    cout << "YES\n";
}
