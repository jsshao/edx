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
int path_to_1[1 << 24];
int path_from_1[1 << 24];
int n;
int st[26];
int count1;
FILE *in = fopen("hamiltonian.in", "r+");
FILE *out = fopen("hamiltonian.out", "w+");

void print(int a, int b, int s, int sprime) {
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
}

int main() {
  path_to_1[0] = 1;
  path_from_1[0] = 1;

  fscanf(in, "%d", &n);
  for (int i = 0; i < n; i++) {
    char temp[n + 1]; fscanf(in, "%s", temp);
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
  int incomplete = (1 << (n)) - 1;
  int incomplete_b[n]; 
  for (int i = 0; i < n; i++) 
    incomplete_b[i] = (1 << (n)) - 1;
  for (int mask = 0; mask < (1 << (n-1)); ++mask) {
    if (incomplete == 0)
      break;
    int comp = mask ^ ((1 << n-1) - 1);
    int bit = (path_to_1[mask] & incomplete);
    int v = 1;
    while (bit) {
      if (bit & 1) {
        int bit2 = (path_from_1[comp] & incomplete_b[v-1]);
        int v2 = 1;
        while (bit2) {
          if (bit2 & 1) {
            print(v, v2, mask, comp);
            hack = false;
            incomplete_b[v-1] ^= (1 << (v2 - 1));
            if (incomplete_b[v-1] == 0)
              incomplete ^= (1 << (v - 1));
          }
          bit2 >>= 1;
          ++v2;
        }
      }
      bit >>= 1;
      ++v;
    }
  }
  if (hack)
    fprintf(out, "No paths\n");
}
