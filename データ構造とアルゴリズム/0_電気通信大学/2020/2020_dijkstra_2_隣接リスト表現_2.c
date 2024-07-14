#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5        // グラフの頂点数
#define INFTY 999  // INT_MAX

int d[V];          // 始点から各頂点への最短距離
int S[V];          // 訪問済みの頂点の集合

typedef struct AdjListNode { // 隣接リスト（のノード）
    int dest;
    int weight;
    struct AdjListNode* next;
} AdjListNode;

typedef struct Graph { // グラフ全体
    AdjListNode* array[V];
} Graph;

AdjListNode* newAdjListNode(int dest, int weight) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    for (int i = 0; i < V; ++i)
        graph->array[i] = NULL;
    return graph;
}

void addEdge(Graph* graph, int src, int dest, int weight) {
    AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src];
    graph->array[src] = newNode;
}

void dijkstra(int s, Graph* graph);

int main() {
    Graph* graph = createGraph();
    addEdge(graph, 0, 1, 3);
    addEdge(graph, 0, 3, 7);
    addEdge(graph, 1, 2, 4);
    addEdge(graph, 1, 3, 1);
    addEdge(graph, 2, 1, 3);
    addEdge(graph, 2, 4, 2);
    addEdge(graph, 3, 2, 4);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 1, 1);

    int s = 0; // 始点
    
    // 初期化
    for (int i = 0; i < V; i++) {
        d[i] = INFTY;
        S[i] = 0;
    }
    
    // Dijkstraアルゴリズムを実行
    dijkstra(s, graph);
    
    // 結果を表示
    for (int i = 0; i < V; i++) {
        printf("Distance from vertex %d to vertex %d is %d\n", s, i, d[i]);
    }
    
    return 0;
}

void dijkstra(int s, Graph* graph) {
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
        
        AdjListNode* pCrawl = graph->array[u];
        while (pCrawl != NULL) {
            int v = pCrawl->dest;
            if (S[v] == 1) {
                pCrawl = pCrawl->next;
                continue;
            }
            if (d[v] > d[u] + pCrawl->weight)
                d[v] = d[u] + pCrawl->weight;
            pCrawl = pCrawl->next;
        }
    }
}
