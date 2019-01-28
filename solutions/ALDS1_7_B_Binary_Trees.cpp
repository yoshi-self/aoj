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

//const double PI = 3.1415926535897932384626433832795;

// 二分木 Binary Tree
struct Node {
  int parent;
  int left;
  int right;
};

vector<Node> tree;
vector<int> depth;
vector<int> height;

string getNodeType(int n) {
    string type = "internal node";
    if(tree[n].parent == -1) {
      type = "root";
    }
    else if(tree[n].left == -1 && tree[n].right == -1) {
      type = "leaf";
    }
    return type;
}

int getNodeDegree(int n) {
  int degree = 0;
  degree += (tree[n].left == -1 ? 0 : 1);
  degree += (tree[n].right == -1 ? 0 : 1);
  return degree;
}

int getNodeSibling(int n) {
  int sibling = -1;
  if(tree[n].parent != -1) {
    int p = tree[n].parent;
    sibling = tree[p].left == n ? tree[p].right : tree[p].left;
  }
  return sibling;
}

void setTreeDepth(int n=0, int d=0) {
  depth[n] = d;
  if(tree[n].left != -1) {
    setTreeDepth(tree[n].left, d + 1);
  }
  if(tree[n].right != -1) {
    setTreeDepth(tree[n].right, d + 1);
  }
}

int setTreeHeight(int n=0) {
  int hl = 0;
  int hr = 0;

  if(tree[n].left != -1) {
    hl = setTreeHeight(tree[n].left) + 1;
  }
  if(tree[n].right != -1) {
    hr = setTreeHeight(tree[n].right) + 1;
  }

  height[n] = max(hl, hr);
  return height[n];
}

int getRootNode() {
  int t = 0;
  while(tree[t].parent != -1) {
    t = tree[t].parent;
  }
  return t;
}

int main() {
  int n;
  scanf("%d", &n);
  tree.resize(n, {-1, -1, -1});
  depth.resize(n);
  height.resize(n);

  int id, l, r;
  REP(i, n) {
    scanf("%d %d %d", &id, &l, &r);
    tree[id].left = l;
    tree[id].right = r;
    tree[l].parent = id;
    tree[r].parent = id;
  }


  int root = getRootNode();
  setTreeDepth(root);
  setTreeHeight(root);

  REP(i, n) {
    int sibling = getNodeSibling(i);
    int degree = getNodeDegree(i);
    string type = getNodeType(i);

    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n",
        i, tree[i].parent, sibling, degree, depth[i], height[i], type.c_str());
  }

  return 0;
}
