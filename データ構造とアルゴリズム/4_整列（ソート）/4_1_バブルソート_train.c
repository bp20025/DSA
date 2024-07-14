// バブルソート

#include <stdio.h>

// 2つの値を交換する関数
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// バブルソート関数 Ver1
void bubbleSort_V1(int array[], int N) {
  for (int i = 0; i < N - 1; i++) { // 始点（始点から順に値が確定）
    for (int j = N - 1; j > i; j--) {
      if ( array[j - 1] > array[j])
	swap(&array[j - 1], &array[j]);
    }
  }
}

// バブルソート関数 Ver2

// 配列の要素を一覧表示する関数
void printArray(int array[], int N) {
  printf("components of array: ");
  for (int i = 0; i < N; i++)
    printf("%d ", array[i]);
  printf("\n");
}

int main() {
  int array[] = {4,5,2,6,3,56,3524,32,54,55555,1};
  int N = sizeof(array) / sizeof(array[0]);

  printArray(array, N);

  bubbleSort_V1(array, N);

  printArray(array, N);

  return 0;
}
