// グラフ理論とネットワーク
// 演習1
// 課題1-2
// bp20025
// 平岡　立成

// 第１引数：「graph1.txt」（グラフデータ）

#include <stdio.h> // 入出力など printfやscanf
#include <stdlib.h> // ユーティリティ関数メモリ関連など　mallocやfree
#include <string.h> // 文字列操作など　strcpyやstrlenなど

#define N_MAX 100 // 点の個数の最大
#define NAME_MAX 256 // ファイル名の最大

int main( int argc, char *argv[] ) {
  // 実行時引数のとり方の典型的な記述
  // 「int argc」：引数の個数
  // 「char *argv[]」：引数そのものが、文字配列として入っていく
  int i, j; // ループ用の変数
  int N = 0; // 点の個数
  int M = 0; // 辺の個数
  // 配列（宣言）　int adjacent[N_MAX][N_MAX];
  int ** adjacent;
  int n1, n2; // ファイルから一時的に読み込む点番号
  FILE *fp; // ファイルポインタ
  char fn[NAME_MAX]; // ファイル名

  // 引数のチェック
  // 引数の個数「argc」が「２」出なかった場合の処理
  // プログラム自体も「１」としてカウントされる
  if ( argc != 2 ) { // 引数の個数「argc」が「2」でなかった場合の処理
    fprintf( stderr, "Usage: %s graph_file\n", argv[0] );
    // 「argv[0]」＝「1-1-1」
    // 「1-1-1のあとにgraph_fileを引数として渡してくださいよ」という表示。
    exit( 1 );
  }

  // グラフファイル名の取得
  strcpy( fn, argv[1] );
  // 「argv[1]」は引数として渡した「graph_file」となるので、
  // グラフファイルを取得していることになる。
  // 「fn」にコピーせずにそのまま「argv[1]」でファイルを開いてもいいんだけど。

  // ファイルを開く
  if (( fp = fopen( fn, "r" )) == NULL ) {
    fprintf( stderr, "File open error %s\n", fn);
    exit( 1 );
  }

  // ここまできたらファイルは開けているので、
  // データを読み込みます。１行目には点の個数が記述されています。
  fscanf( fp, "%d", &N );
  // 「fp」：ファイルへのポインタ（FILE *fp）
  // これを読み込んで「N」に代入

  // 点の個数（点の番号）を超える整数だったらエラー
  if ( N > N_MAX ) {
    fprintf( stderr, "Adjacent matrix overflow.\n" );
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

  // 1-2 すべての点の次数とグラフの平均次数を算出・表示する
  int sumDegree = 0;
  for ( i=0; i<N; i++) {
    int degree = 0;
    for ( j=0; j<N; j++) {
      degree += adjacent[i][j];
    }
    printf("degree[%d]: %d\n", i, degree);
    sumDegree += degree;
  }
  printf("average degree: %f\n", (double)sumDegree / N);

  // メモリを開放する
  for (i=0; i<N; i++) {
    free(adjacent[i]);
  }
  
  return 0;
}
