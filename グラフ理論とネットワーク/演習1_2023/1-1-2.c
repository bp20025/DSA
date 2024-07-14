// グラフ理論とネットワーク
// 1-1-2
// 「graph1.txt」で辺行列で表現されるグラフに対し，
// 隣接行列「adjacent[N_MAX][N_MAX]」を作成するプログラムの作成
// -> 隣接リストへ変更
// 今回のグラフでは隣接行列の7×7の領域のみ使用していた
// 「graph1.txt」の1行目を読み込んでから必要な配列をmallocするようなプログラムを作成する
// 芝浦工業大学

#include <stdio.h>
#include <stdlib.h>


// （動的確保した）配列の初期化
void initializeArray(int N, int **adjacent);

// 配列の一覧表示
void printArray(int N, int **adjacent);

int main( void ) {
  int i, j;
  FILE *fp;
  char *fn = "graph1.txt";

  // 点の数
  int N;

  // 一時変数（点番号の記憶）
  int n1, n2;

  // 隣接行列を格納する2次元ポインタ
  int **adjacent; // <- int adjacent[N_MAX][N_MAX];

  // ファイルを開いて読み込み
  if ( ( fp = fopen( fn, "r" ) ) == NULL ) {
    fprintf( stderr, "ファイル %s が開けません．\n", fn );
    exit( 1 );
  }

  // 1行目（点の数）の読み込み
  fscanf( fp, "%d", &N );

  // 隣接行列をmalloc
  adjacent = ( int ** )malloc( sizeof( int * ) * N);

  // それぞれ確保したint型のポインタへ更に配列を動的確保
  for (int i = 0; i < N; i++) {
    adjacent[i] = ( int * )malloc( sizeof( int ) * N);
  }

  // 配列の初期化
  initializeArray(N, adjacent);

  // EOFまでscanf繰り返し
  while ( fscanf( fp, "%d %d", &n1, &n2 ) != EOF ) {
    // fscanfにおいて，正常にint２つ読み込むことができていれば「2」がreturnされる
    adjacent[n1][n2] = adjacent[n2][n1] = 1;
  }

  // 配列の一覧表示
  printArray(N, adjacent);

  // 領域解法
  for ( i = 0; i < N; i++) {
    free( adjacent[i] );
  }
  free( adjacent );

  // ファイルを閉じる
  fclose( fp );

  return 0;
}

void initializeArray(int N, int **adjacent) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      // 全要素を0で初期化する
      adjacent[i][j] = 0;
    }
  }
}

void printArray(int N, int **adjacent) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", adjacent[i][j]);
      
    }
    printf("\n");
  }
}
