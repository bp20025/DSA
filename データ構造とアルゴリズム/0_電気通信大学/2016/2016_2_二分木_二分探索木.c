// 芝浦工業大学システム理工学部電子情報システム学科
// 学籍番号を入力してください
// 二分探索木の基本的な実装と2016
#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 6
#define INT_MIN 1

struct node {
  int value;
  struct node *left;
  struct node *right;
};

void add_node(struct node **t, int value); // 二分探索木に節点を追加する関数
void inorder_print(struct node *t); // 中順走査で画面表示する関数
void postorder_print(struct node *t); // 後順走査で画面表示する関数
int is_bst(struct node *t, int min, int max); // 二分探索木の成立判定

int main() {
  struct node *root = NULL;

  // 二分探索木に節点を追加
  add_node(&root, 4);
  add_node(&root, 2);
  add_node(&root, 6);
  add_node(&root, 1);
  add_node(&root, 3);
  add_node(&root, 5);

  inorder_print(root); // 中順走査で画面表示
  printf("\n");
  
  int bool = is_bst(root, INT_MIN, INT_MAX); // 二分探索木の成立判定
  printf("%d\n", bool);
  
}

void add_node(struct node **t, int value) { // 二分探索木（BST）に接点を追加する関数
  if (*t != NULL) {
    if (value < (*t)->value)
      add_node (&(*t)->left, value);
    else
      add_node (&(*t)->right, value);
    return;
  }

  (*t) = (struct node *)malloc(sizeof(struct node));
  (*t)->value = value;
  (*t)->left = NULL;
  
  (*t)->right = NULL;
}

void inorder_print(struct node *t) { // 中順走査で画面表示する関数
  if (t == NULL)
    return;
  inorder_print(t->left); // 左の子孫へ
  printf("%d ", t->value);
  inorder_print(t->right); // 右の子孫へ
}

void postorder_print(struct node *t) { // 後順走査で画面表示する関数
  if (t == NULL)
    return;
  postorder_print(t->left); // 左の子孫へ
  postorder_print(t->right); // 右の子孫へ
  printf("%d ", t->value);
}
  


int is_bst(struct node *t, int min, int max) { // 二分探索木の一致判定
  if (t == NULL) return 1;
  else if (min > t->value || t->value > max) return 0;
  else return is_bst(t->left, min, t->value) &&
	 is_bst(t->right, t->value, max);
}
  
   
