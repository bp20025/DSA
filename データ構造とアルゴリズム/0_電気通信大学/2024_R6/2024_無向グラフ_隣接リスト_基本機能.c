#include <stdio.h>
#include <stdlib.h>

// Edge構造体：各エッジの情報（接続先の頂点とエッジの重み）を保持
struct Edge {
    int dest;        // 接続先の頂点
    int weight;      // エッジの重み
    struct Edge* next; // 次のエッジへのポインタ
};

// AdjList構造体：各頂点の隣接リストの先頭ポインタを保持
struct AdjList {
    struct Edge* head; // 隣接リストの先頭ポインタ
};

// Graph構造体：頂点数と隣接リストの配列を保持
struct Graph {
    int V; // グラフの頂点数
    struct AdjList* array; // 隣接リストの配列
};

// 新しいエッジを作成する関数
struct Edge* newEdge(int dest, int weight) {
    struct Edge* newNode = (struct Edge*)malloc(sizeof(struct Edge));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// グラフを作成する関数
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; i++) {
        graph->array[i].head = NULL;
    }
    return graph;
}

// グラフにエッジを追加する関数（無向グラフなので双方向にエッジを追加）
void addEdge(struct Graph* graph, int src, int dest, int weight) {
    // src -> dest エッジを追加
    struct Edge* newNode = newEdge(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // dest -> src エッジを追加
    newNode = newEdge(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// グラフの隣接リストを表示する関数
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        struct Edge* crawl = graph->array[v].head;
        printf("\n頂点 %d の隣接リスト\n head ", v);
        while (crawl) {
            printf("-> %d(%d) ", crawl->dest, crawl->weight);
            crawl = crawl->next;
        }
        printf("\n");
    }
}

int main() {
    int V = 6; // 頂点数
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 2, 2);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 2);
    addEdge(graph, 1, 4, 4);
    addEdge(graph, 2, 3, 6);
    addEdge(graph, 3, 4, 1);
    addEdge(graph, 3, 5, 2);
    addEdge(graph, 4, 5, 3);

    printGraph(graph);

    return 0;
}
