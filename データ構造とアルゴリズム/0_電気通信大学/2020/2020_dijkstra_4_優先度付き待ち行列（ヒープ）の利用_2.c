#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 配列の最大サイズ
#define MAX_SIZE 100
#define V 5        // グラフの頂点数
#define INFTY 999  // INT_MAX

// ヒープを表現する構造体
typedef struct {
    int data[MAX_SIZE];
    int last; // 最後尾の要素番号
} Heap;

// ヒープを初期化する関数
void initHeap(Heap* heap) {
    for (int i = 0; i < MAX_SIZE; i++) {
        heap->data[i] = 9999999;
    }
    heap->last = -1;
}

// swap関数
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// enheap関数
void enheap(Heap* heap, int data) {
    // 最後尾に要素を挿入
    heap->last++;
    heap->data[heap->last] = data;

    // 親ノードとの比較処理
    int current = heap->last;
    while (current > 0) {
        if (heap->data[current] < heap->data[(current-1)/2]) { // C < 親
            swap(&heap->data[current], &heap->data[(current-1)/2]); // C > 親
            current = (current-1)/2; // 親へ移動
        } else {
            return;
        }
    }
}

// deheap関数（最小ノードを取り出す関数）
int deheap(Heap* heap) {
    // 根ノードを取り出す
    int data = heap->data[0];
    // 空いた根ノードへ最後尾ノード追加
    heap->data[0] = heap->data[heap->last];
    heap->last--;

    // 子ノードとの比較処理
    int current = 0;
    while (current*2+1 <= heap->last) { // Cノードに（左の）子が存在（交換の余地アリ）
        if (heap->data[current] > heap->data[current*2+1]) { // Cノード > 左ノード（交換発生）
            if (heap->data[current*2+2] < heap->data[current*2+1]) { // 右ノード < 左ノード（右と交換）
                swap(&heap->data[current], &heap->data[current*2+2]); // C < 子
                current = current*2+2;
            } else { // （左と交換）
                swap(&heap->data[current], &heap->data[current*2+1]); // C < 子
                current = current*2+1;
            }
        } else if (heap->data[current] > heap->data[current*2+2]) { // Cノード > 右ノード（右と交換）
            swap(&heap->data[current], &heap->data[current*2+2]); // C < 子
            current = current*2+2;
        } else {
            return data;
        }
    }
    return data;
}

// ヒープの要素を一覧表示する関数
void displayHeap(Heap* heap) {
    printf("-現在の要素一覧-\n");
    for(int i = 0; i <= heap->last; i++) {
        printf("%d\n", heap->data[i]);
    }
}

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

void dijkstra(int s, Graph* graph) {
    Heap heap;
    initHeap(&heap);

    d[s] = 0;
    enheap(&heap, s);

    while (heap.last != -1) {
        int u = deheap(&heap);
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
            if (d[v] > d[u] + pCrawl->weight) {
                d[v] = d[u] + pCrawl->weight;
                enheap(&heap, v);
            }
            pCrawl = pCrawl->next;
        }
    }
}

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
