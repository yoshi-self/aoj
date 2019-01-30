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

struct Node {
  int parent;
  int left;
  int right;
};

vector<Node> tree;

int getRootNode() {
  int i = 0;
  while(tree[i].parent != -1) {
    i = tree[i].parent;
  }
  return i;
}

void preorderPrint(int n) {
  printf(" %d", n);

  if(tree[n].left != -1) {
    preorderPrint(tree[n].left);
  }
  if(tree[n].right != -1) {
    preorderPrint(tree[n].right);
  }
}

void inorderPrint(int n) {
  if(tree[n].left != -1) {
    inorderPrint(tree[n].left);
  }

  printf(" %d", n);

  if(tree[n].right != -1) {
    inorderPrint(tree[n].right);
  }
}

void postorderPrint(int n) {
  if(tree[n].left != -1) {
    postorderPrint(tree[n].left);
  }
  if(tree[n].right != -1) {
    postorderPrint(tree[n].right);
  }

  printf(" %d", n);
}

int main() {
  int n;
  scanf("%d", &n);

  tree.resize(n, {-1, -1, -1});

  REP(i, n) {
    int id, l, r;
    scanf("%d %d %d", &id, &l, &r);
    tree[id].left = l;
    tree[id].right = r;
    tree[l].parent = id;
    tree[r].parent = id;
  }

  int root = getRootNode();
  printf("Preorder\n");
  preorderPrint(root);
  printf("\n");
  printf("Inorder\n");
  inorderPrint(root);
  printf("\n");
  printf("Postorder\n");
  postorderPrint(root);
  printf("\n");

  return 0;
}
