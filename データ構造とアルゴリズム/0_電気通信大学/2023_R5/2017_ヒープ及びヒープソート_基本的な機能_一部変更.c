// 電気通信大学 2023
// ヒープ及びヒープソート
// 2023は，ヒープを表現する配列を「０」始まりとする

#include <stdio.h>

#define MAX_SIZE 100 // ヒープの容量
int size = 0; // 現在のヒープの要素数

void heapSort(int a[], int n); // ヒープソートを実行する関数
void pushdown(int a[], int k, int hi); // 子ノードとの比較
void swap(int *a, int *b); // swap関数
void printArray(int a[], int lo, int hi ); // 配列の一覧表示

void insertnode(); // ヒープへのノードの挿入（2023で使用）
void pushup (int a[], int k); // 親ノードとの比較（2023で使用）

int main() {
  int X[MAX_SIZE] = {15,7,14,3,6,10,13,1,2,4,5,8,9,11,12}; // 0 ~ 14番
  size = 15;

  printf("ソート対象の配列: ");
  printArray(X, 0, size - 1);

  heapSort(X, size - 1); // ソート範囲（引数：配列／右端index）

  return 0;
}


void heapSort (int a[], int hi) { // （1~ヒープソートを実行する関数

  // ヒープを構成する部分
  for (int i = (hi-1)/2; i >= 0; i--) { // ヒープを構成すべく，子を持つノードに関して「親＜子」関係を担保
    pushdown(a, i, hi);
  }

  // ヒープの根（最小値）を順に取り出していく部分
  for (int i = hi; i > 0; i--) {
    swap(&a[0], &a[i]); // 根ノードを最後尾へ掃き出し
    pushdown(a, 0, i - 1); // ヒープ関係を再構築
  }

  // aには降順に数字が並ぶ
  printf("配列を降順に変更する処理が完了しました\n");
  printArray(a, 0, hi);
}

void pushdown (int a[], int k, int hi) { // 子ノードとの比較
  int c = k * 2 + 1; // （存在する場合）左の子
  if ( !(c <= hi) ) return; // 左の子がソート範囲でない場合
  int r = c + 1; // （存在する場合）右の子
  if ( r <= hi && a[r] < a[c] ) c = r; // 右の子がソート範囲　かつ　左の子よりも小さい
  
  if ( a[k] > a[c] ) // 「親＞子」の関係の場合
    swap (&a[k], &a[c]); // 「親＜子」の関係に
  else
    return;
  pushdown(a, c, hi); // 再帰呼出し
}

void insertnode() { // ヒープへのノードの挿入（2023で使用）
}

void pushup (int a[], int k) { // 親ノードとの比較（2023で使用）
  if ( !(k > 0) ) return; // kがソート範囲内，親が存在しない場合
  int p = (k-1) / 2; // 親ノード
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
