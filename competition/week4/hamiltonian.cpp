#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <string>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;
int adj_to[26];
int adj_from[26];
int path_to_1[1 << 26];
int path_from_1[1 << 26];
bool seen[26][26];
int complete[26];
int n;
int st[26];
int count1;
FILE *in = fopen("hamiltonian.in", "r+");
FILE *out = fopen("hamiltonian.out", "w+");

int main() {
  path_to_1[0] = 1;
  path_from_1[0] = 1;

  fscanf(in, "%d", &n);
  for (int i = 0; i < n; i++) {
    char temp[n + 1]; fscanf(in, "%s", &temp);
    for (int j = 0; j < n; j++) {
      adj_to[i+1] |= (temp[j] == '1' ? (1 << j) : 0);
      adj_from[j + 1] |= (temp[j] == '1' ? (1 << i) : 0);
    }
  }
  for (int mask = 1; mask < (1 << (n-1)); mask++) {
    for (int v = 2; v <= n; ++v) {
      if (mask & (1 << (v-2))) {
        int prev = mask ^ (1 << (v-2));
        if (path_to_1[prev] & adj_to[v]) {
          path_to_1[mask] |= (1 << (v-1));
        }
        if (path_from_1[prev] & adj_from[v]) {
          path_from_1[mask] |= (1 << (v-1));
        }
      }
    }
  }

  bool hack = true;
  for (int mask = 0; mask < (1 << (n-1)); ++mask) {
    int comp = mask ^ ((1 << n-1) - 1);
    for (int v = 1; v <= n; ++v) {
      if (!(path_to_1[mask] & (1 << (v-1))) || complete[v] == n - 1)
        continue;
      for (int v2 = 1; v2 <=n; ++v2) {
        if (seen[v][v2] || !(path_from_1[comp] & (1 << (v2-1))))
          continue;
        //print(v, v2, mask, comp);
        int s = mask;
        int sprime = comp;
        int a = v;
        int b = v2;
        if (s) {
          fprintf(out, "%d -> ", a);
          s ^= (1 << (a - 2));
        }
        int last = a;
        while (s) {
          for (int i = 1; i <= n; i++) {
            if ((adj_to[last] & (1 << (i-1))) && (path_to_1[s] & (1 << (i-1)))) {
              fprintf(out, "%d -> ", i);
              last = i;
              s ^= (1 << (i - 2));
              break;
            }
          }
        }
        fprintf(out, "1");
        if (sprime) {
          st[count1++] = b;
          sprime ^= (1 << (b-2));
        }
        last = b;
        while(sprime) {
          for (int i = 1; i <= n; i++) {
            if ((adj_to[i] & (1 << (last - 1))) && path_from_1[sprime] & (1 << (i-1))) {
              st[count1++] = i;
              last = i;
              sprime ^= (1 << (i-2));
              break;
            }
          }
        }
        while (count1) {
          fprintf(out, " -> %d", st[--count1]);
        }
        fprintf(out, "\n");
        hack = false;
        seen[v][v2] = true;
        complete[v]++;
      }
    }
  }
  if (hack)
    fprintf(out, "No paths\n");
}
