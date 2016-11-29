#ifdef JUDGE
#include <fstream>
std::ifstream cin("team.in");
std::ofstream cout("team.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif
#include <iomanip>
#include <cmath>
using namespace std;
  
int main() {
    int a[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }
    double max = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (i != j && i != k && j != k) {
                    double e = a[0][i]*a[0][i] + a[1][j]*a[1][j] + a[2][k]*a[2][k];
                    if (e > max) max = e;
                }
            }
        }
    }
    cout << setprecision(11) << sqrt(max) << endl;
}
