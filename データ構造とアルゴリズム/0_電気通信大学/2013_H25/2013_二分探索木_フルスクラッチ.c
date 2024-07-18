// 電気通信大学 2013
// 二分探索木
// 二分探索木の基本的な復習

#include <stdio.h>
#include <stdlib.h> // malloc関数の使用

struct n {
  int e;
  struct n* left;
  struct n* right;
};

void insertNode (struct n** root, int val); // 二分探索木にノードを追加する関数
void printBST (struct n* root); // 二分探索木を一覧表示する関数

int main() {
  struct n* root = NULL;

  // 二分探索木へのノード追加
  insertNode(&root, 5);
  insertNode(&root, 3);
  insertNode(&root, 8);
  insertNode(&root, 2);
  insertNode(&root, 4);
  insertNode(&root, 7);

  // 生成した二分探索木を一覧表示
  printBST(root);
  printf("\n");

  return 0;
}

void insertNode (struct n** root, int val) {
  if(*root == NULL) {
    *root = (struct n*)malloc(sizeof(struct n));
    (*root)->left = NULL;
    (*root)->right = NULL;
    (*root)->e = val;
  }
  else if (val < (*root)->e)
    insertNode(&(*root)->left, val);
  else
    insertNode(&(*root)->right, val);
}

void printBST(struct n* root) {
  if (root == NULL) return;
  printBST(root->left);
  printf("%d ", root->e);
  printBST(root->right);
}
