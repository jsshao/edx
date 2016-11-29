#ifdef JUDGE
#include <fstream>
std::ifstream cin("cycle.in");
std::ofstream cout("cycle.out");
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
vector<int> hack;
unordered_set<int> seen;
unordered_set<int> exited;
int n, m;

int dfs(int node) {
    if (exited.find(node) != exited.end()) {
        return 0;
    }
    if (seen.find(node) != seen.end()) {
        cout << "YES\n";
        return node;
    }
    seen.insert(node);
    for (int neigh : edges[node]) {
        int val = dfs(neigh);
        if (val > 0) {
            hack.push_back(node);
            if (val == node) {
                for (int i = hack.size() - 1; i >= 0; i--)
                    cout << hack[i] << " ";
                cout << "\n";
                exit(0);
            }
            return val;
        }
    }

    exited.insert(node);
    return 0;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        edges[u].push_back(v);
    }    

    for (int i = 1; i <= n; i++) {
        dfs(i);
    }
    cout << "NO\n";
}
