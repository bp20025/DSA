#include <stdio.h>
#include <limits.h>

#define V 5        // グラフの頂点数
#define INFTY 999  // INT_MAX

int d[V];          // 始点から各頂点への最短距離
int S[V];          // 訪問済みの頂点の集合

void dijkstra(int s, int w[V][V]);

int main() {
    int w[V][V] = { 
        {0, 3, -1, 7, -1}, // 1 -> (2: 3), (4: 7)
        {-1, 0, 4, 1, -1}, // 2 -> (3: 4), (4: 1)
        {-1, 3, 0, -1, 2}, // 3 -> (2: 3), (5: 2)
        {-1, -1, 4, 0, 2}, // 4 -> (3: 4), (5: 2)
        {-1, 1, -1, -1, 0}  // 5 -> (2: 1)
    };
    
    int s = 0; // 始点
    
    // 初期化
    for (int i = 0; i < V; i++) {
        d[i] = INFTY;
        S[i] = 0;
    }
    
    // Dijkstraアルゴリズムを実行
    dijkstra(s, w);
    
    // 結果を表示
    for (int i = 0; i < V; i++) {
        printf("Distance from vertex %d to vertex %d is %d\n", s, i, d[i]);
    }
    
    return 0;
}

void dijkstra(int s, int w[V][V]) {
  int u; // 現在のノード
  d[s] = 0; // 始点の最短距離 = 0
  for (int i = 0; i < V; i++) {
    int dmin = INFTY;

    // 距離に基づく訪問先uの決定
    for (int j = 0; j < V; j++) {
      // 訪問済
      if (S[j] == 1) continue;
      
      if (d[j] < dmin) {
	dmin = d[j];
	u = j;
      }
    }
    S[u] = 1; // 訪問先uを訪問済に
    printf("Distance to vertex %d is %d\n", u, d[u]);

    // 最短距離の更新
    for (int j = 0; j < V; j++) {
      // 訪問済
      if (S[j] == 1) continue;

      // 有向辺が存在しない
      if (w[u][j] == -1) continue;
      
      if (d[j] > d[u] + w[u][j])
	d[j] = d[u] + w[u][j];
    }
  }
}
