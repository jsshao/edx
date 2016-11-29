#ifdef JUDGE
#include <fstream>
std::ifstream cin("chairs.in");
std::ofstream cout("chairs.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif
#include <iomanip>
#include <cmath>
using namespace std;
  
int main() {
    int a, b, c; cin >> a >> b >> c;
    double x, y;

    x = ((c*c - b*b)*1.0 - a * a) / -2.0 / a;
    y = sqrt(b*b - x * x);
    double x1 = a / 2.0, y1 = 0;
    double x2 = x / 2.0, y2 = y / 2.0;
    double x3 = (x + a) / 2.0, y3 = y / 2.0;
    cout << setprecision(11) << (sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)) + sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1)) + sqrt((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2))) / 3.0 << endl;
}
