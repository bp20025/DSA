// 電気通信大学 2023
// 5: ダイクストラ法による無向グラフの最短経路の算出／ヒープの利用

#include <stdio.h>
#include <limits.h>

// about 無向グラフ，dijkstra
#define V 5        // グラフの頂点数
#define INFTY 999  // INT_MAX

int d[V];          // 始点から各頂点への最短距離
int S[V];          // 訪問済みの頂点の集合

void dijkstra(int s, int w[V][V]);

// about ヒープ
#define MAX_SIZE 100 // ヒープの容量
int size = 0; // 現在のヒープの要素数

// node構造体
struct node {
  int nodeid; // ノード識別子
  int d; // あるノードからの最短距離
};
void insert(struct node a[], struct node val); // ヒープへ要素を挿入する関数
struct node deletemin(struct node a[]); // ヒープの根を削除する関数（取り出し）
int edit(struct node a[], int id, int new_d, int k); // ヒープの要素の最短距離を更新する関数

void pushdown(struct node a[], int k, int hi); // 子ノードと比較する関数
void pushup(struct node a[], int k); // 親ノードと比較する関数

void swap(struct node *a, struct node *b); // swap関数
void printArray(struct node a[], int lo, int hi ); // 配列

int main() {
  int w[V][V] = { // 隣接行列（無向グラフ）
		 {0, 4, 2, -1, -1}, // 0
		 {4, 0, 3, 2, 4},   // 1
		 {2, 3, 0, 6, -1},  // 2
		 {-1, 2, 6, 0, 1},  // 3
		 {-1, 4, -1, 1, 0}  // 4
  };
    
    int s = 0; // 始点
    
    // 初期化
    for (int i = 0; i < V; i++) {
      d[i] = INFTY;
      S[i] = 0;
    }
    
    // Dijkstraアルゴリズムを実行
    dijkstra(s, w);

    
    return 0;
}

void dijkstra(int s, int w[V][V]) {
  struct node Q[V]; // ヒープを表現する配列
  
  struct node u; // 現在のノード
  d[s] = 0; // 始点の最短距離 = 0

  // Qに全ノードを追加
  for (int i = 0; i <V; i++) {
    insert(Q, (struct node){i, d[i]});
  }

  while(size != 0) {
    u = deletemin(Q);
    S[u.nodeid] = 1; // 訪問先uを訪問済に
    printf("ノード%dの最短経路が確定しました: %d\n", u.nodeid, u.d);

    // 最短距離の更新
    for (int j = 0; j < V; j++) {
      // 訪問済
      if (S[j] == 1) continue;
      
      // 無向辺が存在しない
      if (w[u.nodeid][j] == -1) continue;

      if ( d[j] > d[u.nodeid] + w[u.nodeid][j] ) {
	d[j] = d[u.nodeid] + w[u.nodeid][j];
	edit (Q, j, d[j], 0);
      }
    }
  }
}

void insert(struct node a[], struct node val) { // ヒープへ要素を挿入する関数
  a[size] = val;
  size++;

  pushup(a, size - 1);
}

struct node deletemin(struct node a[]) { // ヒープの根を削除する関数（取り出し）
  if (size == 0) { // ヒープが空である場合
    struct node errorNode; errorNode.nodeid = -1; errorNode.d = -1;
    return errorNode;
  }
  struct node root = a[0]; // 根ノード取り出し
  a[0] = a[size-1]; // 最後尾ノードを取り出し
  size--;
  pushdown(a, 0, size - 1); // ヒープの再構成
  return root;
}

int edit(struct node a[], int id, int new_d, int k) { // ヒープの要素の最短距離を更新する関数
  if ( k <= size - 1 ) {
    if ( a[k].nodeid == id ) {
      int old_d = a[k].d;
      a[k].d = new_d;

      if (new_d < old_d) // 小さくなったら親ノードと比較
	pushup(a, k);
      else // 大きくなったら子ノードと比較
	pushdown(a, k, size - 1);
      return 1;
    } else {
      return ( edit(a, id, new_d, 2*k+1) || edit(a, id, new_d, 2*k+2) );
    }
  } else {
    return 0;
  }
}

void pushdown(struct node a[], int k, int hi) { // 子ノードと比較する関数
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


void pushup(struct node a[], int k) { // 親ノードと比較する関数
  if (k <= 0) return;
  int p = (k - 1) / 2;
  if (a[p].d > a[k].d)
    swap(&a[p], &a[k]);
  else
    return;
  pushup(a, p);
}


void swap(struct node *a, struct node *b) { // swap関数
  struct node temp = *a;
  *a = *b;
  *b = temp;
}

void printArray(struct node a[], int lo, int hi) { // 配列を一覧表示する関数
  for (int i = lo; i <= hi; i++) {
    printf("{%d, %d} ", a[i].nodeid, a[i].d);
  }
  printf("\n");
}
