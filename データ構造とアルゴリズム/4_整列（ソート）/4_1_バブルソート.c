// データ構造とアルゴリズム
// 4:整列（ソート）
// 1:バブルソート
// 芝浦工業大学システム理工学部電子情報システム学科

#include <stdio.h>


// ２つの値を交換する関数
void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

// バブルソート関数 Ver1（昇順／先頭から確定）
void bubbleSort_V1(int array[], int N) {
  for (int i = 0; i < N - 1; i++) {
    for (int j = N - 1; i < j; j--) {
      if (array[j-1] > array[j]) // 小さいやつを先頭に
	swap(&array[j-1],&array[j]);
    }
  }
}

// バブルソート関数 Ver2（昇順／末尾から確定）
void bubbleSort_V2(int array[], int N) {
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N - 1 - i; j++) {
      if (array[j] > array[j+1]) // 大きいやつを末尾に
	swap(&array[j], &array[j+1]);
    }
  }
}


int main() {

  int array[] = {4,5,2,6,3,56,47,3524,32,54,55555,1};
  int N = sizeof(array) / sizeof(array[0]);

  printf("components of array: ");
  for (int i = 0; i < N; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  bubbleSort_V2(array, N);
  
  printf("components of array: ");
  for (int i = 0; i < N; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
      
}
