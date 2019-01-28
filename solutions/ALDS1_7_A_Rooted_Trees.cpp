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

// join vector<int> to a string with delimiter
std::string join(const std::vector<int> &v, const std::string delim = "") {
  std::string result;
  for(unsigned int i = 0; i < v.size(); ++i) {
    result += std::to_string(v[i]);
    if(i != v.size() - 1) {
      result += delim;
    }
  }
  return result;
}

// 左子右兄弟表現 left-child, right-sibling representation
struct Node {
  int parent;
  int left;
  int right;
};

int main() {
  int n;
  scanf("%d", &n);
  vector<Node> v(n, {-1, -1, -1});

  REP(i, n) {
    int id, k;
    scanf("%d %d", &id, &k);
    int prev_c = -1;
    REP(j, k) {
      int c;
      scanf("%d", &c);
      if(j == 0) {
        v[id].left = c; // child
      }
      v[c].parent = id;
      if(prev_c != -1) {
        v[prev_c].right = c;
      }
      prev_c = c;
    }
  }


  REP(i, n) {
    Node node = v[i];
    string type = "internal node";
    if(node.parent == -1) {
      type = "root";
    }
    else if(node.left == -1) {
      type = "leaf";
    }

    int depth = 0;
    int t = i;
    while(v[t].parent != -1) {
      depth++;
      t = v[t].parent;
    }

    vector<int> children;
    if(node.left != -1) {
        children.push_back(node.left);
        t = node.left;
        while(v[t].right != -1) {
          children.push_back(v[t].right);
          t = v[t].right;
        }
    }
    string children_str = join(children, ", ");

    printf("node %d: parent = %d, depth = %d, %s, [%s]\n", i, v[i].parent, depth, type.c_str(), children_str.c_str());
  }

  return 0;
}
