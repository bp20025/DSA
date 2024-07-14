#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// 配列を結合を行う関数
int* merge(int array0[], int array1[], int N0, int N1 ) {
  int * mergedArray = (int *)malloc(sizeof(int) * (N0 + N1));
  int index = 0;

  int i = 0, j = 0;
  
  // 結合処理（whileループ）
  while(1) {
    if(i < N0 && (array0[i] < array1[j] || j == N1)) { // array0から要素を取り出す場合
      mergedArray[index] = array0[i];
      index++; i++;
    }

    if(j < N1 && (array0[i] > array1[j] || i == N0)) { // array1から要素を取り出す場合
      mergedArray[index] = array1[j];
      index++; j++;
    }

    if (i == N0 && j == N1)
      break;
  }
  

  return mergedArray; // 結合した配列の先頭アドレスをreturn 
}

// 配列の分割を行う関数
int * mergeSort(int array[], int N) {
  // 終了条件
  if (N <= 1)
    return array;

  // 分割時の要素数の決定
  int half_N = N / 2;

  // 分割配列の動的確保
  int *array0 = (int *)malloc(sizeof(int) * half_N);
  int *array1 = (int *)malloc(sizeof(int) * (N - half_N));

  for (int i = 0; i < half_N; i++) {
    array0[i] = array[i];
  }

  for (int i = half_N; i < N; i++) {
    array1[i - half_N] = array[i];
  }

  // 再帰呼び出し
  array0 = mergeSort(array0, half_N);
  array1 = mergeSort(array1, N - half_N);

  // 結合処理（merge）（merge後の配列の先頭アドレスをreturn）
  return merge(array0, array1, half_N, N - half_N);
}


int main(void) {
  int array[] = {5,7,9,4,6,8,3,2};
  int N = sizeof(array) / sizeof(array[0]); // 配列サイズの取得

  // 配列要素を一覧表示
  printf("現在の配列の格納状況: ");
  for (int i = 0; i < N; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  int *sortedArray = mergeSort(array, N); // マージソートの実行

  // ソートされた配列要素を一覧表示
  printf("ソート後の配列の格納状況: ");
  for (int i = 0; i < N; i++) {
    printf("%d ", sortedArray[i]);
  }
  printf("\n");

  // メモリの解放
  free(sortedArray);

  return 0;
}
  

