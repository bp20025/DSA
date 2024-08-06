// 芝浦工業大学システム理工学部電子情報システム学科
// 学籍番号を入力してください
// 神経情報システム研究室

// 電気通信大学 2024
// 無向グラフの隣接リスト表現 基本機能

#include <stdio.h>
#include <stdlib.h>

struct Edge {
  int dest; // 終点
  int weight; // 重み
  struct Edge* next;
};

struct AdjList {
  struct Edge* head;
};

struct Graph {
  int V; // 頂点数
  struct AdjList* array; // 各ノードの隣接リスト
};

struct Graph* newGraph (int V); // 新規グラフを作成する関数

struct Edge* newEdge (int dest, int weight); // 新規エッジを作成する関数
void addEdge (struct Graph* graph, int src, int dest, int weight); // 新規エッジを作成する関数を処理する関数


void printGraph (struct Graph* graph); // グラフの隣接リストを一覧表示する関数

int main() {
  int V = 6; // 頂点数
  struct Graph* graph = newGraph(V);

  // エッジの追加処理
  addEdge(graph,0,3,1);
  addEdge(graph,0,4,3);
  addEdge(graph,1,2,3);
  addEdge(graph,1,4,1);
  addEdge(graph,2,5,1);
  addEdge(graph,2,4,2);
  addEdge(graph,3,5,4);

  printGraph(graph);

  return 0;
}

struct Graph* newGraph (int V) { // 新規グラフを作成する関数
  struct Graph* graph = (struct Graph *)malloc(sizeof(struct Graph));
  graph->V = V;
  graph->array = (struct AdjList *)malloc( V * sizeof(struct AdjList));
  for (int i = 0; i < V; i++) {
    graph->array[i].head = NULL;
  }

  return graph;
}

struct Edge* newEdge (int dest, int weight) { // 新規エッジを作成する関数
  struct Edge* edge = (struct Edge *)malloc(sizeof(struct Edge));
  edge->dest = dest;
  edge->weight = weight;
  edge->next = NULL;

  return edge;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) { // 新規エッジを作成する関数を処理する関数
  struct Edge* edge = newEdge(dest, weight);
  edge->next = graph->array[src].head;
  graph->array[src].head = edge;

  edge = newEdge(src, weight);
  edge->next = graph->array[dest].head;
  graph->array[dest].head = edge;
}

void printGraph(struct Graph* graph) { // グラフの隣接リストを一覧表示する関数
  for (int i = 0; i < graph->V; i++) {
    struct Edge* crawl = graph->array[i].head;

    printf("src:%d / ", i);
    while (crawl != NULL) {
      printf("dest:%d, weight:%d / ", crawl->dest, crawl->weight);
      crawl = crawl->next;
    }
    printf("\n");
  }
}
  
  



  
