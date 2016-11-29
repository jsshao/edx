#ifdef JUDGE
#include <fstream>
std::ifstream cin("sparse.in");
std::ofstream cout("sparse.out");
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

struct dest {
    int node;
    int weight;
};
class Compare {
    public:
        bool operator ()(dest a, dest b) {
            return a.weight > b.weight;
        }
};

int n, m;
vector<dest> edges[30001];
int shortest[30001];
priority_queue<dest, vector<dest>, Compare> q;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u; int v; int w; dest d;
        cin >> u >> v >> w;
        d.node = v;
        d.weight = w;
        edges[u].push_back(d);
        d.node = u;
        edges[v].push_back(d);
    }
    for (int i = 1; i <= n; i++) {
        shortest[i] = 10000 * 30003;
    }
    
    int count = 0;
    dest temp; temp.node = 1; temp.weight = 0;
    q.push(temp);
    while (count < n) {
        dest d = q.top(); q.pop();
        if (shortest[d.node] != 10000 * 30003) {
            continue;
        }
        shortest[d.node] = d.weight;
        count ++;
        for (dest neigh : edges[d.node]) {
            dest temp; temp.node = neigh.node; temp.weight = d.weight + neigh.weight;
            q.push(temp);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << shortest[i] << " ";
    } cout << '\n';
}
