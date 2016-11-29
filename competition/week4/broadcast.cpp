#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <deque>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;

struct frame {
    int x1;
    int x2;
    int y1;
    int y2;
};
class player {
    public:
        player(int16_t x, int16_t y) : x(x), y(y), parent(NULL) {}
        int16_t x;
        int16_t y;
        player *parent;
};
int16_t seen[301][301];
vector<player*> v1;
vector<player*> v2;
vector<player*> *v1p = &v1;
vector<player*> *v2p = &v2;;
frame thisFrame;
int iter = 0;
int w, h, n; 
FILE *in = fopen("broadcast.in", "r+");
FILE *out = fopen("broadcast.out", "w+");

bool isValidPush(int16_t a, int16_t b, player* parent) {
    if (a < 1 || a > w || b < 1 || b > h)
        return false;
    if (seen[a][b] == iter) {
        return false;
    }
    if (a >= thisFrame.x1 && a <= thisFrame.x2 && b >= thisFrame.y1 && b <= thisFrame.y2) {
        return false;
    }

    player *p = new player(a, b);
    p->parent = parent;
    v2p->push_back(p);
	seen[a][b] = iter;
    return true;
}

bool print16_t(player *p) {
    if (!p)
        return false;
    if (print16_t(p->parent))
        fprintf(out, "%d %d\n", p->x, p->y);
    return true;
}

int main() {
    fscanf(in, "%d %d", &w, &h);
    fscanf(in, "%d", &n);
    for (int16_t i = 1; i <= w; i++) {
        for (int16_t j = 1; j <= h; j++) {
            v1p->push_back(new player(i, j));
        }
    }
    for (int16_t i = 0; i < n; i++) {
        fscanf(in, "%d %d %d %d", &thisFrame.x1, &thisFrame.y1, &thisFrame.x2, &thisFrame.y2);
		++iter;
        for (player *t : *v1p) {
            isValidPush(t->x- 1, t->y, t);
            isValidPush(t->x+ 1, t->y, t);
            isValidPush(t->x, t->y- 1, t);
            isValidPush(t->x, t->y+ 1, t);
        }
        vector<player*> *temp = v1p;
        v1p = v2p;
        v2p = temp;
        v2p->clear();
    }
    if (v1p->empty()) {
        fprintf(out, "Impossible\n");
    } else {
        print16_t(v1p->at(0));
    }
}
