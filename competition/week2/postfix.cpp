#ifdef JUDGE
#include <fstream>
std::ifstream cin("postfix.in");
std::ofstream cout("postfix.out");
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
    stack<int> s;
    string a;
    while (cin >> a) {
        if (a == "+") {
            int b = s.top(); s.pop();
            int c = s.top(); s.pop();
            s.push(b + c);
        } else if (a == "-") {
            int b = s.top(); s.pop();
            int c = s.top(); s.pop();
            s.push(c - b);
        } else if (a == "*") {
            int b = s.top(); s.pop();
            int c = s.top(); s.pop();
            s.push(b * c);
        } else {
            s.push(atoi(a.c_str()));
        }
    }
    cout << s.top() << '\n';
    return 0;
}
