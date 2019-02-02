#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <climits>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <complex>
#include <functional>
#include <utility>
#include <iterator>

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (m); i < (int)(n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define INF 2000000000

#ifdef LOCAL
  #define dprintf(...) fprintf(stdout, __VA_ARGS__)
#else
  #define dprintf(...) 0
#endif

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int uint;

vector<int> heap;

void printTreeInfo() {
  int last_idx = heap.size() - 1;
  for(int i = 1; i < heap.size(); ++i) {
    printf("node %d: key = %d, ", i, heap[i]);
    // parent
    if(i / 2 >= 1) {
      printf("parent key = %d, ", heap[i / 2]);
    }
    // left
    if(i * 2 <= last_idx) {
      printf("left key = %d, ", heap[i * 2]);
    }
    // right
    if(i * 2 + 1 <= last_idx) {
      printf("right key = %d, ", heap[i * 2 + 1]);
    }
    printf("\n");
  }
}

int main() {
  int n;
  scanf(" %d", &n);
  heap.resize(n + 1);

  REP(i, n) {
    int t;
    scanf(" %d", &t);
    heap[i + 1] = t;
  }
  printTreeInfo();

  return 0;
}
