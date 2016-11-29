#ifdef JUDGE
#include <fstream>
std::ifstream cin("brackets.in");
std::ofstream cout("brackets.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif
using namespace std;
#include <stack>
#include <queue>
#include <deque>
  
int main() {
    string line;
    while (cin >> line) {
        stack<char> s;
        for (char i : line) {
            if (i == '(' || i == '[')
                s.push(i);
            else if (i == ')'){
                if (s.empty() || s.top() != '(') {
                    s.push('?');
                    break;
                }
                s.pop();
            }
            else if (i == ']'){
                if (s.empty() || s.top() != '[') {
                    s.push('?');
                    break;
                }
                s.pop();
            }
        }
        cout << (s.empty() ? "YES\n" : "NO\n");
    }
    return 0;
}
