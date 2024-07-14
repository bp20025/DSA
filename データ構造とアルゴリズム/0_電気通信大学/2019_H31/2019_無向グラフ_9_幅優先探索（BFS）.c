// 芝浦工業大学システム理工学部電子情報システム学科
// データ構造とアルゴリズム
// 電気通信大学　情報ネットワーク工学専攻

#include <stdio.h>

#define N 7

struct node{
  int adj[N]; // このnodeにおける隣接行列
  int visited; // 訪問済を判定
} G[N];

void initGraph(); // （struct node）型配列Gの初期化

void visit(int i); // 無向グラフを探索する関数

int main(){
  initGraph(); // 探索判定変数，隣接行列の設定
  visit(0);

  printf("\n");

  // 連結性（連結グラフ）の判定
  int numOfVisited = 0; // 探索済のノード数
  for(int i=0;i<N;i++){
    if(G[i].visited==1)
      numOfVisited++;
  }
  if(numOfVisited == N) // 全ノードが探索済
    printf("このグラフは連結グラフです\n");
  else
    printf("このグラフは連結グラフではありません\n");
  
    
    

  // ここに連結性を判定する処理を追加してください

  return 0;
}

/*
void visit(int i){
  // 訪問処理
  G[i].visited = 1;
  printf("%d -> ", i);
  
  for(int j=0;j<N;j++){
    if(G[i].adj[j]==1){ // G[j]が，G[i]と隣接
      if(G[j].visited==0) visit(j); // G[j]が，未探索なら探索
    }
  }
}
*/


// visit関数の変更->幅優先探索（BFS）
void visit(int start) {
    int queue[N];
    int front = 0, rear = 0;

    // スタートノードを訪問し、キューに追加
    G[start].visited = 1;
    printf("%d -> ", start);
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        
        for (int j = 0; j < N; j++) {
            if (G[current].adj[j] == 1 && G[j].visited == 0) {
                G[j].visited = 1;
                printf("%d -> ", j);
                queue[rear++] = j;
            }
        }
    }
}


void initGraph() {
    // 各ノードの隣接行列と訪問済みフラグを初期化
    G[0] = (struct node){ .adj = {0, 1, 0, 0, 0, 1, 0}, .visited = 0 };
    G[1] = (struct node){ .adj = {1, 0, 0, 0, 0, 0, 1}, .visited = 0 };
    G[2] = (struct node){ .adj = {0, 0, 0, 0, 0, 0, 1}, .visited = 0 };
    G[3] = (struct node){ .adj = {0, 0, 0, 0, 0, 0, 1}, .visited = 0 };
    G[4] = (struct node){ .adj = {0, 0, 0, 0, 0, 1, 0}, .visited = 0 };
    G[5] = (struct node){ .adj = {1, 0, 0, 0, 1, 0, 1}, .visited = 0 };
    G[6] = (struct node){ .adj = {0, 1, 1, 1, 0, 1, 0}, .visited = 0 };
}
