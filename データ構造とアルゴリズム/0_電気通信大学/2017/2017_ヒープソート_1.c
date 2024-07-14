// 芝浦工業大学システム理工学部電子情報システム学科
// 学籍番号を入力してください

#include <stdio.h>
#include "fill_array.h"

void swap( int *a, int *b); // swap関数

int lch( int k ) { return 2 * k; } // 左の子の要素番号

int par( int k ) { return k / 2; } // 親の要素番号

void tdown( int T[], int k, int m ); // k番目のノードに関する子関係を担保

void tup( int T[], int c ); // 目的不明関数

void printArray( int a[], int lo, int hi ); // 配列の一覧表示

int main() {
  int X[SIZE] = {0};
  fill_array(X, SIZE);

  printArray( X, 1, 20 );

  printf( "tdown処理を実行します\n" );

  tdown( X, 7, 15 ); // 7 ~ 15の順序関係を担保?
  tdown( X, 6, 15 ); // 7 ~ 15の順序関係を担保?
  tdown( X, 5, 15 ); // 7 ~ 15の順序関係を担保?
  tdown( X, 4, 15 ); // 7 ~ 15の順序関係を担保?
  tdown( X, 3, 15 ); // 7 ~ 15の順序関係を担保?
  tdown( X, 2, 15 ); // 7 ~ 15の順序関係を担保?
  tdown( X, 1, 15 ); // 7 ~ 15の順序関係を担保?

  printArray( X, 1, 20 );

  // 配列の残りの要素を処理
  int n = 15;
  for (int i = 16; i < 1024; i++) {
    if (X[i] > X[1]) {
    X[1] = X[i];
    tdown(X, 1, n);
    }
  }
    // 15番目に大きい数は最小ヒープのルート
    printf("15番目に大きな数: %d\n", X[1]);

  return 0;
}





void swap( int *a, int *b ) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void printArray( int a[], int lo, int hi ) {
  for( int i = lo; i <= hi; i++ ) {
    printf( "%d ", a[i] );
  }
  printf( "\n" );
}


void tdown( int T[], int k, int m ) {
  /* T[1]...T[m}がヒープの領域 */
  int c = lch( k ); // 左の子のindex取得
  if( c > m ) return; // 左の子存在？
  int r = c+1; // 右の子
  if( r <= m && T[r] < T[c] ) c = r; // 右の子存在? -> T -> 小さい方を採用
  if( T[k] <= T[c] ) return; // ノード <= 子（正しい関係）
  swap( &T[k], &T[c] ); // ノード > 子 -> ノード <= 子（正しい関係）
  tdown( T, c, m ); // 再帰呼出し
}

void tup( int T[], int c ){
  if( c <= 1 ) return;
  int p = par( c ); // 親のindex取得
  if( T[p] <= T[c] ) return; // 親 <= ノード（正しい関係）
  swap( &T[p], &T[c] ); // 親 > ノード -> 親 <= ノード（正しい関係）
  tup( T, p ); // 再帰呼出し
}
  
  

