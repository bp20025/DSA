#include <stdio.h>
#include <limits.h>
#include "node_heap.h" // 構造体nodeをヒープ処理する関数群

#define V 5        // グラフの頂点数
#define INFTY 999  // INT_MAX

struct node nodes[V]; // node[].nodeid: 識別子，node[].d: あるノードからの最短距離

int w[V][V] = { // 隣接行列（無向グラフ）
    {0, 4, 2, -1, -1}, // 1 -> 
    {4, 0, 3, 2, 4},   // 2 -> 
    {2, 3, 0, 6, -1},  // 3 -> 
    {-1, 2, 6, 0, 1},  // 4 -> 
    {-1, 4, -1, 1, 0}  // 5 -> 
};

void dijkstra(int s, int w[V][V]); // ダイクストラ法で無向グラフを探索する関数

int main() {
    int s = 0; // 始点
    
    // Dijkstraアルゴリズムを実行
    dijkstra(s, w);
    
    // 結果を表示
    for (int i = 0; i < V; i++) {
        printf("D from vertex %d to vertex %d is %d\n", s, i, nodes[i].d);
    }
    
    return 0;
}

void dijkstra(int s, int w[V][V]) {
    struct node heap[V]; // ヒープを表現する配列
    size = 0; // ヒープのサイズを初期化
    
    // 全ノードの最短距離の初期化，ヒープへ格納
    for (int i = 0; i < V; i++) {
        nodes[i].nodeid = i;
        nodes[i].d = (i == s) ? 0 : INFTY; // 始点の最短距離=0
        insertNode(heap, nodes[i]);
    }
    
    // ヒープが空になるまで探索
    while (size != 0) {
        // 最短距離のノードを取り出す
        struct node u = dequeue(heap);
        
        // 取り出したノードの隣接ノードを調べる
        for (int j = 0; j < V; j++) {
            if (w[u.nodeid][j] != -1) { // 辺が存在する場合
                int newDist = u.d + w[u.nodeid][j];
                if (nodes[j].d > newDist) {
                    nodes[j].d = newDist; // 距離を更新
                    // ヒープ中の対応するノードの距離も更新
                    insertNode(heap, nodes[j]);
                }
            }
        }
    }
}
