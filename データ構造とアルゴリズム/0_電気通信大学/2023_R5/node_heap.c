#include <stdio.h>

#define MAX_SIZE 100 // ヒープの容量
int size = 0; // 現在のヒープの要素数

// ノード構造体の定義
struct node {
    int nodeid;    // ノードの識別子
    int d;  // あるノードからの最短距離
};

void heapSort(struct node a[], int hi); // ヒープソートを実行する関数
void pushdown(struct node a[], int k, int hi); // 子ノードとの比較
void swap(struct node *a, struct node *b); // swap関数
void printArray(struct node a[], int lo, int hi ); // 配列の一覧表示

void insertNode(struct node a[], struct node val); // ヒープへのノードの挿入
void pushup(struct node a[], int k); // 親ノードとの比較

struct node dequeue(struct node a[]); // 根ノードを取り出す関数

struct node dequeue(struct node a[]) { // 根ノードを取り出す関数
  if (size == 0) { // ヒープ画からである場合
    struct node errorNode; errorNode.nodeid = -1; errorNode.d = -1;
    return errorNode;
  }
  struct node root = a[0]; // 根ノード取り出し
  a[0] = a[size-1]; // 最後尾ノードを取り出し
  size--;
  pushdown(a, 0, size - 1); // ヒープの再構成
  return root;
}
  


void heapSort(struct node a[], int hi) {
  for (int i = (hi-1)/2; i >= 0; i--) {
    pushdown(a, i, hi);
  }

  for (int i = hi; i > 0; i--) {
    swap(&a[0], &a[i]);
    pushdown(a, 0, i - 1);
  }

  printf("配列を降順に変更する処理が完了しました\n");
  printArray(a, 0, hi);
}

void pushdown(struct node a[], int k, int hi) {
  int c = k * 2 + 1;
  if (c > hi) return;
  int r = c + 1;
  if (r <= hi && a[r].d < a[c].d) c = r;

  if (a[k].d > a[c].d)
    swap(&a[k], &a[c]);
  else
    return;
  pushdown(a, c, hi);
}

void insertNode(struct node a[], struct node val) {
  a[size] = val;
  size++;

  pushup(a, size - 1);
}

void pushup(struct node a[], int k) {
  if (k <= 0) return;
  int p = (k - 1) / 2;
  if (a[p].d > a[k].d)
    swap(&a[p], &a[k]);
  else
    return;
  pushup(a, p);
}

void swap(struct node *a, struct node *b) {
  struct node temp = *a;
  *a = *b;
  *b = temp;
}

void printArray(struct node a[], int lo, int hi) {
  for (int i = lo; i <= hi; i++) {
    printf("{%d, %d} ", a[i].nodeid, a[i].d);
  }
  printf("\n");
}
