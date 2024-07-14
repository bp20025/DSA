
#include <stdio.h>

#define MAX_SIZE 100

// 2つの要素を交換する関数
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// クイックソート関数
void quickSort(int array[], int left, int right) {

  if (left>=right) // 要素が1以下になったら対象の部分は終了
    return;

  int current = left;
 
  int pivot = array[left];

  //
  for (int i = left + 1; i <= right; i++) {
    if ( array[i] < pivot ) {
      swap(&array[i], &array[++current]);
      printf("交換発生交換したcurrent=%d\n", current);
    }
  }
  swap(&array[left], &array[current]);

  // 再帰呼び出し
  quickSort(array, left, current-1);
  quickSort(array, current+1, right);

  return;

}

// 配列を一覧表示する関数
void printArray(int array[], int N) {
  printf("components of array: ");
  
  for (int i = 0; i < N; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}





int main(void) {
  int array[] = {5,6,3,9,2,8,4,7};
  // int array[] = {4,3,2};
  int N = sizeof(array) / sizeof(array[0]);

  printArray(array, N);

  quickSort(array, 0, N-1); // 配列の先頭アドレス／左端／右端

  printArray(array, N);

  return 0;
}
