// 電気通信大学 2017

#include <stdio.h>

void swap( int *a, int *b ); // swap関数

void Qsort( int a[], int lo, int hi ); // クイックソート関数

void printArray( int a[], int lo, int hi ); // 配列の一覧表示


int main() {
  int A[] = {4,7,6,1,0,3,2,5};

  int N = sizeof(A) / sizeof(A[0]);

  printArray( A, 0, N-1 );

  printf("クイックソートによるソート処理を実行します．\n");

  Qsort( A, 0, N-1 );

  printArray( A, 0, N-1 );

  return 0;
}


void swap( int *a, int *b ) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void Qsort( int a[], int lo, int hi ) {
  if( lo < hi ) {
    int l = lo, r = hi;
    int piv = a[lo]; // 1: 軸要素の選択

    // 2: 配列の分割と並べ替え
    while( 1 ) {
      while( a[l] < piv ) l++;
      while( piv < a[r] ) r--;
      if( l >= r ) break;
      swap( &a[l], &a[r] );
      l++; r--;
    }

    printf("ソート中: ");
    printArray( a, lo, hi );

    // 3: 再帰呼出し
    if( lo < l-1 ) Qsort( a, lo, l-1 );
    if( r+1 < hi ) Qsort( a, r+1, hi );
  }
}

void printArray( int a[], int lo, int hi ) {
  for( int i = lo; i <= hi; i++ ) {
    printf("%d ", a[i]);
  }
  printf("\n");
}
