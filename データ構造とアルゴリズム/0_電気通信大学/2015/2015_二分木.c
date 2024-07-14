#include <stdio.h>
#include <stdlib.h>

// 便宜的に最大と最小を与える
#define INT_MAX 85
#define INT_MIN 10


// 二分木のノードの定義 ***
typedef struct node {
    int val;
    struct node *left;
    struct node *right;
} node;

// 関数プロトタイプ宣言

/* 以下の２関数を，再帰呼び出しを用いた１関数へまとめる
struct node* createNode(int value); // 新しいノードを作成する関数
void addNode(struct node **root, int value); // ノードを追加する関数
*/

void insert_node(struct node **p, int val); // ***
void insert_node_2(struct node **p, int val); // ***

// （右側）最小値を探索・取得する関数
// （右側）最小値を探索・削除する関数
//データを削除する関数


void inorderPrint(struct node *s); // 中順走査で表示
int is_bst(struct node *t, int min, int max); // 二分木の成立を判定する関数 ***


// メイン関数
int main() {
    struct node *s = NULL;
    // ２分探索木に要素を追加する関数を呼び出す処理
    insert_node_2(&s, 30);
    insert_node_2(&s, 10);
    insert_node_2(&s, 50);
    insert_node_2(&s, 20);
    insert_node_2(&s, 80);
    insert_node_2(&s, 40);
    insert_node_2(&s, 70);
    insert_node_2(&s, 60);

    /*
    insert_node(&s, 35);
    insert_node(&s, 15);
    insert_node(&s, 55);
    insert_node(&s, 25);
    insert_node(&s, 85);
    insert_node(&s, 45);
    insert_node(&s, 75);
    */

    printf("二分木の中順走査: ");
    inorderPrint(s);
    printf("\n");

    printf("%d\n", is_bst(s, INT_MIN, INT_MAX));
    

    return 0;
}

// 新しいノードを挿入する関数
void insert_node(struct node **p, int val) {
  if (*p != NULL) {
    if (val < (*p)->val)
      insert_node(&(*p)->left, val);
    else
      insert_node(&(*p)->right, val);
    return;
  }
  // 新規ノードの作成
  *p = (struct node *)malloc(sizeof(struct node));
  (*p)->val = val;
  (*p)->left = NULL;
  (*p)->right = NULL;
}


// 中順走査 (In-order traversal) で二分木を表示する関数
void inorderPrint(struct node *s) {
    if (s == NULL) return;
    inorderPrint(s->left);
    printf("%d ", s->val);
    inorderPrint(s->right);
}


// 二分木の成立を判定する関数 ***
int is_bst(struct node *t, int min, int max) {
  if (t == NULL) return 1;
  else if ( t->val < min || t->val > max) return 0;
  else return is_bst(t->left, min, t->val) &&
	 is_bst(t->right, t->val, max);
}



/*
// 二分木を画面表示する関数
print_all_nodes(struct node *p) {
  while(
*/

