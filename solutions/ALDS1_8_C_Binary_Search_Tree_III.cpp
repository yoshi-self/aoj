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

Node *getMaximumNode(Node *node) {
  while(node->right != nullptr) {
    node = node->right;
  }
  return node;
}

Node *getMinimumNode(Node *node) {
  while(node->left != nullptr) {
    node = node->left;
  }
  return node;
}

void deleteNode(Node *node) {
  if(node->left == nullptr && node->right == nullptr) {
    // root
    if(node->parent == nullptr) {
      root = nullptr;
    }
    else {
      // parent's left child
      if(node == node->parent->left) {
        node->parent->left = nullptr;
      }
      // parent's right child
      else {
        node->parent->right = nullptr;
      }
    }
    delete node;
  }
  // has only left child
  else if (node->right == nullptr){
    // root
    if(node->parent == nullptr) {
      root = node->left;
      node->parent = nullptr;
    }
    else {
      // parent's left child
      if(node == node->parent->left) {
        node->parent->left = node->left;
        node->left->parent = node->parent;
      }
      // parent's right child
      else {
        node->parent->right = node->left;
        node->left->parent = node->parent;
      }
    }
    delete node;
  } // has only left child
  // has only right child
  else if(node->left == nullptr) {
    //root
    if(node->parent == nullptr) {
      root = node->right;
      node->parent = nullptr;
    }
    else {
      // parent's left child
      if(node == node->parent->left) {
        node->parent->left = node->right;
        node->right->parent = node->parent;
      }
      // parent's right child
      else {
        node->parent->right = node->right;
        node->right->parent = node->parent;
      }
    }
    delete node;
  }
  // has both children
  else {
    // get minimum of right subtree
    Node *rmin = getMinimumNode(node->right);
    node->key = rmin->key;
    // parent's left child
    if(rmin == rmin->parent->left) {
      // NOTE: rmin doesn't have a left child
      //       because it's the minimum of subtree
      rmin->parent->left = rmin->right;
    }
    // parent's right child
    else {
      rmin->parent->right = rmin->right;
    }
    delete rmin;
  }
}

Node *findNode(Node *node, int key) {
  while(node != nullptr) {
    if(node->key == key) {
      break;
    }
    else if(key < node->key) {
      node = node->left;
    }
    else {
      node = node->right;
    }
  }

  return node;
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

void printTreeInfo(Node *node) {
  if(node == nullptr) {
    return;
  }

  printf("key:%d, left:%d, right:%d\n",
      node->key,
      (node->left == nullptr ? -999 : node->left->key),
      (node->right == nullptr ? -999 : node->right->key));
  printTreeInfo(node->left);
  printTreeInfo(node->right);
}

int main() {
  int n;
  scanf(" %d", &n);
  char buff[128];
  int v;
  Node *foundNode = nullptr;

  REP(i, n) {
    scanf(" %s", buff);
    if(strcmp(buff, "insert") == 0) {
      scanf(" %d", &v);
      insertNode(v);
    }
    else if(strcmp(buff, "find") == 0) {
      scanf(" %d", &v);
      foundNode = findNode(root, v);
      if(foundNode != nullptr) {
        printf("yes\n");
      }
      else {
        printf("no\n");
      }
    }
    else if(strcmp(buff, "delete") == 0) {
      scanf(" %d", &v);
      deleteNode(findNode(root, v));
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
