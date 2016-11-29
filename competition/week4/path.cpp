#ifdef JUDGE
#include <fstream>
std::ifstream cin("path.in");
std::ofstream cout("path.out");
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

struct edge {
    int source;
    int dest;
    long long weight;
};

vector<edge> edges;
long long shortest[2001];
int n, m, s;
long long MIN  = -((long long) 1 << 61);
long long MAX  = ((long long) 1 << 61);

int main() {
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        edge d;
        cin >> d.source >> d.dest >> d.weight;
        edges.push_back(d);
    }    
    for (int i = 1; i <= n; i++)
        shortest[i] = MAX;
    shortest[s] = 0;

    for (int i = 0; i < n; i++) {
        for (edge e : edges) {
            long long new_d = shortest[e.source] == MIN ? MIN 
                : (shortest[e.source] == MAX ? MAX 
                : max(MIN, shortest[e.source] + e.weight));
            if (new_d < shortest[e.dest])
                shortest[e.dest] = new_d;
        }
    }

    for (int i = 0; i < n; i++) {
        for (edge e : edges) {
            long long new_d = shortest[e.source] == MIN ? MIN 
                : (shortest[e.source] == MAX ? MAX 
                : max(MIN, shortest[e.source] + e.weight));
            if (new_d < shortest[e.dest]) {
                shortest[e.dest] = MIN;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (shortest[i] == MIN) {
            cout << "-\n";
        } else if (shortest[i] == MAX) {
            cout << "*\n";
        } else {
            cout << shortest[i] << '\n';
        }
    }
}
