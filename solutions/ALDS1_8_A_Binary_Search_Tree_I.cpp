#include <cstdio>
#include <cstdlib>
#include <cstring>
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

struct Node {
  int key;
  Node *parent;
  Node *left;
  Node *right;
};

Node *root = nullptr;

void insertNode(int v) {
  Node *node = new Node;
  node->key = v;
  node->left = nullptr;
  node->right = nullptr;

  if(root == nullptr) {
    root = node;
    return;
  }

  Node *cur = root;
  Node *prev = root;

  while(cur != nullptr) {
    prev = cur;
    if(node->key < cur->key) {
      cur = cur->left;
    }
    else {
      cur = cur->right;
    }
  }

  node->parent = prev;
  if(node->key < prev->key) {
    prev->left = node;
  }
  else {
    prev->right = node;
  }
}

void inorderPrint(Node *node) {
  if(node == nullptr) {
    return;
  }

  inorderPrint(node->left);
  printf(" %d", node->key);
  inorderPrint(node->right);
}

void preorderPrint(Node *node) {
  if(node == nullptr) {
    return;
  }

  printf(" %d", node->key);
  preorderPrint(node->left);
  preorderPrint(node->right);
}

int main() {
  int n;
  scanf(" %d", &n);
  char buff[128];
  int v;

  REP(i, n) {
    scanf(" %s %d", buff, &v);
    if(strcmp(buff, "insert") == 0) {
      insertNode(v);
    }
    else if(strcmp(buff, "print") == 0) {
      inorderPrint(root);
      printf("\n");
      preorderPrint(root);
      printf("\n");
    }
  }


  return 0;
}
