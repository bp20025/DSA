#include <stdio.h>
#include <stdlib.h>
#include <time.h> // 追加
#include <stdbool.h> // 追加

// （動的確保した）配列の初期化
void initializeArray(int N, int **adjacent);

// 配列の一覧表示
void printArray(int N, int **adjacent);

// 各点の次数を表示
void vertexDegree(int N, int **adjacent);

// ランダムに移動する関数
float moveRandomly(int N, int **adjacent);

int main(void) {
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
    if ((fp = fopen(fn, "r")) == NULL) {
        fprintf(stderr, "ファイル %s が開けません．\n", fn);
        exit(1);
    }

    // 1行目（点の数）の読み込み
    fscanf(fp, "%d", &N);

    // 隣接行列をmalloc
    adjacent = (int **)malloc(sizeof(int *) * N);

    // それぞれ確保したint型のポインタへ更に配列を動的確保
    for (int i = 0; i < N; i++) {
        adjacent[i] = (int *)malloc(sizeof(int) * N);
    }

    // 配列の初期化
    initializeArray(N, adjacent);

    // EOFまでscanf繰り返し
    while (fscanf(fp, "%d %d", &n1, &n2) != EOF) {
        // fscanfにおいて，正常にint２つ読み込むことができていれば「2」がreturnされる
        adjacent[n1][n2] = adjacent[n2][n1] = 1;
    }

    // 配列の一覧表示
    printArray(N, adjacent);

    // 作成した配列（隣接行列）より，各点の次数を一覧表示する
    vertexDegree(N, adjacent);

    // 平均移動回数を算出
    float avgMoves = 0;
    for (int seed = 1; seed <= 10000; seed++) {
        avgMoves += moveRandomly(N, adjacent);
    }
    avgMoves /= 10000;

    printf("Average number of moves: %f\n", avgMoves);

    // 領域解放
    for (i = 0; i < N; i++) {
        free(adjacent[i]);
    }
    free(adjacent);

    // ファイルを閉じる
    fclose(fp);

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

void vertexDegree(int N, int **adjacent) {
    int counter = 0; // 各vertexのdegree
    float average = 0; // その平均

    for (int i = 0; i < N; i++) {
        int counter = 0;
        for (int j = 0; j < N; j++) {
            counter += adjacent[i][j];
        }
        printf("The degree of vertex-%d is %d\n", i, counter);
        average += counter;
    }

    // 次数の平均値を算出する
    average /= N;

    printf("The average of all vertices is %f\n", average);
}

float moveRandomly(int N, int **adjacent) {
    srand48(time(NULL)); // 乱数の初期化

    int pos = 0; // 現在の点
    int next; // 移動後の点

    int moves = 0; // 移動回数

    while (pos != 6) { // 現在の点が6になるまで繰り返す
        int r;
        do {
            r = (int)(drand48() * N); // 0からN-1までのランダムな整数を生成
            next = r;
        } while (adjacent[pos][next] != 1); // 移動先が隣接していない場合は再度乱数生成

        pos = next; // 現在の点を移動先に更新
        moves++; // 移動回数をインクリメント
    }

    return moves; // 移動回数を返
}
