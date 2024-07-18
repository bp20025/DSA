// 電気通信大学 2013
// 二分探索木（2013に従う）

#include <stdio.h>
#include <stdlib.h> // malloc関数の使用

struct n {
  int e;
  struct n* left;
  struct n* right;
};

void insert_node(struct n **p, int val); // 二分探索木にノードを追加する関数（再帰）
void insert_node_2(struct n **p, int val); // 二分探索木にノードを追加する関数（再帰なし）
struct n * deletemax(struct n *T, struct n ** result); // 二分探索木の最大値を削除する関数
struct n * decrease(struct n *T); // 二分探索木の根を削除する関数
void inorderPrint(struct n *s); // 二分探索木を一覧表示する関数

int main() {
  struct n* root = NULL;

  // 二分探索木へのノード追加
  insert_node_2(&root, 5);
  insert_node_2(&root, 3);
  insert_node_2(&root, 8);
  insert_node_2(&root, 2);
  insert_node_2(&root, 4);
  insert_node_2(&root, 7);
  /*
  // 二分探索木へのノード追加
  insert_node(&root, 5);
  insert_node(&root, 3);
  insert_node(&root, 8);
  insert_node(&root, 2);
  insert_node(&root, 4);
  insert_node(&root, 7);
  */

  // 生成した二分探索木を一覧表示
  inorderPrint(root);
  printf("\n");

  /*
  // (2):二分探索木の最大値の削除
  printf("二分探索木の最大値を削除します\n");
  struct n * result = NULL; // 最大値を受け取る変数
  root = deletemax(root, &result);
  printf("最大値: %d\n", result->e);
  printf("更新: ");
  inorderPrint(root);
  printf("\n");
  */

  // (3):二分探索木の根の削除
  printf("二分探索木の根を削除します\n");
  root = decrease(root);
  printf("更新: ");
  inorderPrint(root);
  printf("\n");

  // (3):二分探索木の根の削除
  printf("二分探索木の根を削除します\n");
  root = decrease(root);
  printf("更新: ");
  inorderPrint(root);
  printf("\n");
  
  return 0;
}

// 二分探索木にノードを追加する関数（再帰）
void insert_node(struct n **p, int val) {
  if (*p != NULL) {
    if (val < (*p)->e)
      insert_node(&(*p)->left, val);
    else
      insert_node(&(*p)->right, val);
    return;
  }
  // 新規ノードの作成
  *p = (struct n *)malloc(sizeof(struct n));
  (*p)->e = val;
  (*p)->left = NULL;
  (*p)->right = NULL;
}

// 二分探索木にノードを追加する関数２（再帰なし） ***
void insert_node_2(struct n **p, int val) {
  struct n **current = p;
  while (*current != NULL) { // if文からwhileループへの変更
    if (val < (*current)->e)
      current = &(*current)->left;
    else
      current = &(*current)->right;
  }
  // 新規ノードの作成
  *current = (struct n *)malloc(sizeof(struct n));
  (*current)->e = val;
  (*current)->left = NULL;
  (*current)->right = NULL;
}

// 二分探索木の最大値を削除してできた二分探索木を返す関数
struct n *deletemax(struct n *T, struct n **result) {
  struct n *parent = NULL;
  struct n *current = T;
  
  while (current->right != NULL) {
    parent = current;
    current = current->right;
  }
  
  *result = current; // 誤答: result = &current;

  // 削除処理
  if (parent == NULL)
    T = current->left; // 最大値が根ノードの場合
  else
    parent->right = current->left;
  // 誤答: current = current->left;

  //誤答:  free(current); 削除した最大ノードを取得する処理もあるので当然メモリ解放NG
  
  return T; // 削除してできた二分探索木を返す
}

// 二分探索木の根を削除してできた二分探索木を返す関数
struct n *decrease(struct n *T) {
  struct n *max = NULL; // 新たな根の更新処理
  if (T->left != NULL) {
    T->left = deletemax(T->left, &max);
    printf("左子最大ノードを抽出しました: %d\n", max->e);
  }
  else {
    free(T); // メモリ解放
    return NULL;
  }

  // 新たな根の更新処理
  max->left = T->left;
  max->right = T->right;
  // free(T); // メモリ解放
  return max; 
}


// 中順走査 (In-order traversal) で二分木を表示する関数
void inorderPrint(struct n *s) {
    if (s == NULL) return;
    inorderPrint(s->left);
    printf("%d ", s->e);
    inorderPrint(s->right);
}
