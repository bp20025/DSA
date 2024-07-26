// 芝浦工業大学システム理工学部電子情報システム学科
// 電気通信大学　情報ネットワーク専攻2021
// データ構造とアルゴリズム
#include <stdio.h>

#define N 5

// ノード構造体
struct node {
  int nodeid;
  char label[4];
} node[N];

int visited[N] = {0,0,0,0,0}; // 訪問済の判定

int num[N] = {0,0,0,0,0}; // 訪問順の保存

int counter = 0; // ノード順位（ナンバリング済ノード数）

// 隣接行列
int adj[N][N] = {
		 {0,1,0,0,0},
		 {0,0,0,0,1},
		 {0,1,0,1,1},
		 {0,0,0,0,0},
		 {0,0,0,0,0}
};

void func1(int x); // 閉路を持たない有向グラフを探索する関数

void printArray(int a[], int n); // 配列を一覧表示する関数

int main() {
  // func1(0);

  for (int i=0; i<N; i++) {
    if (visited[i] == 0)
      func1(i);
  }

  printArray (num, N);

  return 0;
}

// 有向非巡回グラフへのトポロジカルソートに準じたナンバリング
void func1(int y) {
  printf("%dを探索します\n", y);

  // xへ隣接するノードを探索
  for (int x=0; x<N; x++) {
    if (adj[x][y] == 1) {
      if (visited[x] == 0) func1(x);
    }
  }
  visited[y] = 1;
  counter++;
  num[y] = counter;
}

void printArray(int a[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}
