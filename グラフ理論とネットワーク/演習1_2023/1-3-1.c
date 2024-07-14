// グラフ理論とネットワーク
// 演習1
// 課題1-3
// bp20025
// 平岡　立成

// 第１引数：「graph1.txt」（グラフデータ）// 課題1-3
// 第２引数：「1」（ランダムのシード値）

#include <stdio.h> // 入出力など printfやscanf
#include <stdlib.h> // ユーティリティ関数メモリ関連など　mallocやfree
#include <string.h> // 文字列操作など　strcpyやstrlenなど
#include <time.h>

#define N_MAX 100 // 点の個数の最大
#define NAME_MAX 256 // ファイル名の最大

int moveCounter = -1; // 枝の本数を計測する
// 始点「0」をリストに格納する際に関数を呼び出すので、
// 関数の呼び出し回数+1が枝の本数となる

struct NodeMoveTrace {
  int node;
  struct NodeMoveTrace* next;
};

// ノードのリストを格納していく関数
struct NodeMoveTrace* nodeMoving(struct NodeMoveTrace* head, int node) {
  moveCounter++;
  struct NodeMoveTrace* newNode = (struct NodeMoveTrace*)malloc(sizeof(struct NodeMoveTrace));
  newNode->node = node;
  newNode->next = NULL;

  if ( head == NULL) {
    printf("-> %d ", newNode->node);
    return newNode;
  }

  struct NodeMoveTrace* current = head;
  while ( current->next != NULL) {
    current = current->next;
  }

  current->next = newNode;
  printf("-> %d ", newNode->node);
  return head;
}

// ノードのリストを格納する関数の呼び出し、終了条件の検証をする関数
void nodeMovingJudge(int** adjacent, int seed) {
  struct NodeMoveTrace* head = NULL;
  srand(seed);
  int preNode = 0; // 隣接行列に枝が存在するか否かの判断に用いる
  head = nodeMoving(head, preNode);
  
  while ( 1 ) {
    int randomNode = rand() % 7;

    // 隣接行列に「末尾のノード」と「ランダムノード」の組み合わせが存在する場合のみ
    // リストを追加する関数「nodeMoving」を呼び出す
    if ( adjacent[preNode][randomNode] == 1) {
      head = nodeMoving(head, randomNode);
      preNode = randomNode;
    }

    if (preNode == 6) {
      printf("\n");
      break;
    }
  }
}

  

int main( int argc, char *argv[] ) {
  // 実行時引数のとり方の典型的な記述
  // 「int argc」：引数の個数
  // 「char *argv[]」：引数そのものが、文字配列として入っていく
  
  int i, j; // ループ用の変数
  int N = 0; // 点の個数
  int M = 0; // 辺の個数
  
  int ** adjacent; // 隣接行列（動的確保）
  int n1, n2; // ファイルから一時的に読み込む点番号
  FILE *fp; // ファイルポインタ
  char fn[NAME_MAX]; // ファイル名

  

  // 引数のチェック
  // 引数１：ファイル名
  // 引数２：シード値
  if ( argc != 3 ) { // 引数の個数「argc」が「2」でなかった場合の処理
    fprintf( stderr, "Usage: %s graph_file seed\n", argv[0] );

    exit( 1 );
  }

  int seed = atoi(argv[2]);

  // グラフファイル名の取得
  strcpy( fn, argv[1] );

  // ファイルを開く
  if (( fp = fopen( fn, "r" )) == NULL ) {
    fprintf( stderr, "File open error %s\n", fn);
    exit( 1 );
  }

  // ここまできたらファイルは開けているので、
  // データを読み込みます。１行目には点の個数が記述されています。
  fscanf( fp, "%d", &N );

  // 点の個数（点の番号）を超える整数だったらエラー
  if ( N > N_MAX ) {
    fprintf( stderr, "Adjacent matrix overflow.\n" );
    exit( 1 );
  }

  // 取得した「N」に基づき動的確保
  adjacent = (int**)malloc(N * sizeof(int*));
  for (int k = 0; k < N; k++) {
    adjacent[k] = (int *)malloc(N * sizeof(int));
  }

  // 隣接行列を全部０にクリアする
  for (i=0; i<N; i++ )
    for (j=i; j<N; j++ )
      adjacent[i][j] = adjacent[j][i] = 0;

  // 2行目からファイル末尾まで、点を２個ずつ読み込み、
  // 隣接行列に格納していきます
  while( fscanf( fp, "%d %d", &n1, &n2 ) != EOF ) {
    adjacent[n1][n2]++;
    adjacent[n2][n1]++;
    M++; // 辺の個数を一つずつ増やしていく
  }

  // 最後に、adjacent配列を画面表示する
  for ( i=0; i<N; i++ ) {
    for ( j=0; j<N; j++ )
      printf( "%d ", adjacent[i][j] );
    printf( "\n" );
  }
  printf( "N=%d, M=%d\n", N, M);

  // シード値を画面表示する
  printf("seed: %d\n", seed);

  // ノードの移動の変遷を画面表示する
  nodeMovingJudge(adjacent, seed);

  // ノードを移動した回数を画面表示する
  printf("移動回数：%d\n", moveCounter);
  

  // メモリを開放する
  for (i=0; i<N; i++) {
    free(adjacent[i]);
  }
  
  return 0;
}
