#include <stdio.h>
#include <limits.h>

#define V 7      // グラフの頂点数
#define INFTY 999  // INT_MAX

int d[V];          // 始点から各頂点への最短距離
int S[V];          // 訪問済みの頂点の集合

void dijkstra(int s, int w[V][V]);

int main() {
    int w[7][7] = {
    {0,  2,  -1,  1,  -1,  -1,  -1},
    {2,  0,  3,  2,  -1,  -1,  -1},
    {-1,  3,  0,  -1,  1,  5,  -1},
    {1,  2,  -1,  0,  4,  -1,  -1},
    {-1,  -1,  1,  4,  0,  2,  3},
    {-1,  -1,  5,  -1,  2,  0,  1},
    {-1,  -1,  -1,  -1,  3,  1,  0}
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
    int u;
    d[s] = 0;
    for (int i = 0; i < V; i++) {
        int dmin = INFTY;
        for (int j = 0; j < V; j++) {
            if (S[j] == 1) continue;
            if (d[j] < dmin) {
                dmin = d[j];
                u = j;
            }
        }
        S[u] = 1;
        
        // 最短経路の距離が確定した時点でその点までの距離を表示する
        printf("Distance to vertex %d is %d\n", u, d[u]);
        
        for (int j = 0; j < V; j++) {
            if (S[j] == 1) continue;
            if (w[u][j] == -1) continue;
            if (d[j] > d[u] + w[u][j])
                d[j] = d[u] + w[u][j];
        }
    }
}
