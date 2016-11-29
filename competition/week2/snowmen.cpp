#ifdef JUDGE
#include <fstream>
//std::ifstream cin("snowmen.in");
//std::ofstream cout("snowmen.out");
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
  
int main() {
    FILE *in = fopen("snowmen.in", "r+");
    long long int n; fscanf(in, "%lld", &n);
    long long int mass[n + 1][3];
    mass[0][0] = 0;
    mass[0][1] = 0;
    mass[0][2] = 0;
    long long int count = 0;
    for (long long int i = 1; i < n + 1; i++) {
        long long int a, b; fscanf(in, "%lld %lld", &a, &b);
        if (b == 0) {
            long long int c = mass[a][0];
            mass[i][0] = mass[c][0];
            mass[i][1] = mass[c][1];
            mass[i][2] = mass[c][2];
        } else {
            mass[i][0] = a;
            mass[i][1] = b;
            mass[i][2] = mass[a][2] + b;
        }
        count += mass[i][2];
    }
    fclose(in);
    in = fopen("snowmen.out", "w+");
    fprintf(in, "%lld\n", count);
    return 0;
}
