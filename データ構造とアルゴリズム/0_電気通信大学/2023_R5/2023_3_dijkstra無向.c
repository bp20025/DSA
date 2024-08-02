#include <stdio.h>
#include <limits.h>
#include "node_heap.h" // 構造体nodeをヒープ処理する関数群



#define V 5        // グラフの頂点数
#define INFTY 999  // INT_MAX

struct node node[V]; // node[].nodeid: 識別子，node[].d: あるノードからの最短距離

int w[V][V] = { // 隣接行列（無向グラフ）
	       {0, 4, 2, -1, -1}, // 1 -> 
	       {4, 0, 3, 2, 4}, // 2 -> 
	       {2, 3, 0, 6, -1}, // 3 -> 
	       {-1, 2, 6, 0, 1}, // 4 -> 
	       {-1, 4, -1, 1, 0}  // 5 -> 
};


void dijkstra(int s, int w[V][V]); // ダイクストラ法で無向グラフを探索する関数

int main() {
    int s = 0; // 始点
    
    // Dijkstraアルゴリズムを実行
    dijkstra(s, w);
    
    // 結果を表示
    for (int i = 0; i < V; i++) {
        printf("Distance from vertex %d to vertex %d is %d\n", s, i, d[i]);
    }
    
    return 0;
}

void dijkstra(int s) {
  struct node X[V]; // ヒープを表現する配列
  
    // int u;
  struct node u; // 対象のノード
    struct node X[V]; // ヒープを表現する配列
    d[s] = 0;
    // 全ノードの最短距離の初期化，ヒープへ格納
    for (int i = 0; i < V; i++) {
      if (i == s)
	node[i].d = 0; // 始点の最短距離=0
      else
	node[i].d = INFTY;
      insertNode(X, node[i]);
    }
    // ヒープが空になるまでwhile
    while (size != 0) {
      // 最短距離のノードを取り出す
      u = dequeue(X);
      for (int j = 0; j < V; j++) {
	if ( w[u.nodeid][j] != -1) { // jがu-j辺を持つ場合
	  if ( node[j].d > u.d + w[u.nodeid][j] ) {
	    node[j].d = u.d + w[u.ndoeid][j]; // 現在の最短距離より小さければ更新
	    // ヒープに格納されている方のノードの距離を更新スべきだが（てか両方すべきだが）どうすればいいかわからん
	  }
	}
      }
    
    
 
}
