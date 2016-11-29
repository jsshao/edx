#ifdef JUDGE
#include <fstream>
std::ifstream cin("stack.in");
std::ofstream cout("stack.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif
using namespace std;
#include <stack>
  
int main() {
    int n; cin >> n;
    char a;
    int b;
    stack<int> s;
	for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == '-') {
            cout << s.top() << '\n';
            s.pop();
        } else {
            cin >> b;
            s.push(b);
        }
	}
    return 0;
}
