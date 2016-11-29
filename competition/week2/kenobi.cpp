#ifdef JUDGE
#include <fstream>
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
#include <cstring>
#include <vector>
  
int main() {
    FILE *in = fopen("kenobi.in", "r+");
    deque<int> first, second;
    deque<int> *a = &first, *b = &second;
    int n; fscanf(in, "%d", &n);
    char s[5];
    int c;
    while (n--) {
        fscanf(in, "%s", &s);
        if (strcmp(s, "add") == 0) {
            fscanf(in, "%d", &c);
            b->push_back(c);
        } else if (strcmp(s, "take") == 0) {
            b->pop_back();
        } else {
            deque<int> *temp = a;
            a = b;
            b = temp;
        }

        if (a->size() > b->size()) {
            b->push_front(a->back());
            a->pop_back();
        } else if (b->size() > a->size() + 1) {
            a->push_back(b->front());
            b->pop_front();
        }
    }
    fclose(in);
    in = fopen("kenobi.out", "w+");
    fprintf(in, "%d\n", a->size() + b->size());
    for (auto i : *a)
        fprintf(in, "%d ", i);
    for (auto i : *b)
        fprintf(in, "%d ", i);
    fprintf(in, "\n");
    return 0;
}
