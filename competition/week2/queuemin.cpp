#ifdef JUDGE
#include <fstream>
std::ifstream cin("queuemin.in");
std::ofstream cout("queuemin.out");
#else
#include <iostream>
using std::cin;
using std::cout;
#endif
using namespace std;
#include <queue>
#include <deque>
  
int main() {
    int n; cin >> n;
    char a;
    int b;
    queue<int> s;
    deque<int> d;
	for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == '-') {
            if (d.front() == s.front())
                d.pop_front();
            s.pop();
        } else if (a == '?') {
            cout << d.front() << '\n';
        } else {
            cin >> b;
            s.push(b);
            while (!d.empty() && d.back() > b)
                d.pop_back();
            d.push_back(b);
        }
	}
    return 0;
}
