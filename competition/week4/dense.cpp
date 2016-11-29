#ifdef JUDGE
#include <fstream>
//std::ifstream cin("dense.in");
//std::ofstream cout("dense.out");
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

int n, s, f;
int weight[2001][2001];
long long shortest[2001];

int main() {
    FILE *in = fopen("dense.in", "r+");
    fscanf(in, "%d %d %d", &n, &s, &f);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fscanf(in, "%d", &(weight[i][j]));
        }
    }
    for (int i = 1; i <= n; i++) {
        shortest[i] = (long long) 1000000000 * 2001;
    }
    shortest[s] = 0;
    for (;;) {
        int MIN = 1;
        long long MIN_VAL = (long long)1000000000 * 2001;
        for (int i = 1; i <= n; i++) {
            if (shortest[i] == -1)
                continue;
            if (shortest[i] < MIN_VAL) {
                MIN = i;
                MIN_VAL = shortest[i];
            }
        }
        if (MIN_VAL == (long long)1000000000 * 2001) {
            FILE *out = fopen("dense.out", "w+");
            fprintf(out, "%d\n", -1);
            break;
        }

        if (MIN == f) {
            FILE *out = fopen("dense.out", "w+");
            fprintf(out, "%lld\n", MIN_VAL);
            break;
        }
        for (int i = 1; i <= n; i++) {
            if (shortest[i] != -1 && weight[MIN][i] != -1)
                shortest[i] = min(shortest[i], MIN_VAL + weight[MIN][i]);
        }
        shortest[MIN] = -1;
    }
}
