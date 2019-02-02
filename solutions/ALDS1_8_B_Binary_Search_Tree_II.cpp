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

bool findNode(Node *node, int key) {
  bool result = false;

  while(node != nullptr) {
    if(node->key == key) {
      result = true;
      break;
    }
    else if(key < node->key) {
      node = node->left;
    }
    else {
      node = node->right;
    }
  }

  return result;
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
  bool found = false;

  REP(i, n) {
    scanf(" %s", buff);
    if(strcmp(buff, "insert") == 0) {
      scanf(" %d", &v);
      insertNode(v);
    }
    else if(strcmp(buff, "find") == 0) {
      scanf(" %d", &v);
      found = findNode(root, v);
      if(found) {
        printf("yes\n");
      }
      else {
        printf("no\n");
      }
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
