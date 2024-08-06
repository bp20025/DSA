// 芝浦工業大学システム理工学部電子情報システム学科
// 学籍番号を入力してください
// データ構造とアルゴリズム

#include <stdio.h>

#define MAX 100 // ヒープの容量

void heapSort(int a[], int n); // ヒープソートを実行する関数
void pushdown(int a[], int first, int last); // 子ノードとの比較
void swap(int *a, int *b); // swap関数
void printArray(int a[], int lo, int hi ); // 配列の一覧表示

void insertnode(); // ヒープへのノードの挿入（2023で使用）
void pushup (int a[], int k); // 親ノードとの比較（2023で使用）

int main() {
  int X[MAX] = {0, 15,7,14,3,6,10,13,1,2,4,5,8,9,11,12}; // 0 ~ 15番目
  // 1 ~ 15を配列の範囲とする

  int N = sizeof(X) / sizeof(X[0]); // 16

  printf("ソート対象の配列: ");
  printArray(X, 1, 15);

  heapSort(X, N-1); // ソート範囲（引数：配列／要素数）

  return 0;
}


void heapSort (int a[], int n) { // （1~ヒープソートを実行する関数

  // ヒープを構成する部分
  for (int i = n/2; i >= 1; i--) { // ヒープを構成すべく，子を持つノードに関して「親＜子」関係を担保
    pushdown(a, i, n);
  }

  // ヒープの根（最小値）を順に取り出していく部分
  for (int i = n; i > 1; i--) {
    swap(&a[1], &a[i]); // 根ノードを最後尾へ掃き出し
    pushdown(a, 1, i - 1); // ヒープ関係を再構築
  }

  // aには降順に数字が並ぶ
  printf("配列を降順に変更する処理が完了しました\n");
  printArray(a, 1, n);
}

void pushdown (int a[], int k, int last) { // 子ノードとの比較
  int c = k * 2; // （存在する場合）左の子
  if ( !(c <= last) ) return; // 左の子がソート範囲でない場合
  int r = c + 1; // （存在する場合）右の子
  if ( r <= last && a[r] < a[c] ) c = r; // 右の子がソート範囲　かつ　左の子よりも小さい
  
  if ( a[k] > a[c] ) // 「親＞子」の関係の場合
    swap (&a[k], &a[c]); // 「親＜子」の関係に
  else
    return;
  pushdown(a, c, last); // 再帰呼出し
}

void insertnode() { // ヒープへのノードの挿入（2023で使用）
}

void pushup (int a[], int k) { // 親ノードとの比較（2023で使用）
  if ( !(k > 1) ) return; // kがソート範囲内，親が存在しない場合
  int p = k / 2; // 親ノード
  if (a[p] > a[k]) // 「親＞子」である場合
    swap (&a[p], &a[k]); // 『親＜子」の関係に
  else
    return;
  pushup (a, p); // 再帰呼出し
}
  

void swap (int *a, int *b) { // swap関数
  int temp = *a;
  *a = *b;
  *b = temp;
}

void printArray (int a[], int lo, int hi) { // 配列を一覧表示する関数
  for (int i = lo; i <= hi; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  
}
