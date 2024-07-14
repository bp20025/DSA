
// 芝浦工業大学システム理工学部電子情報システム学科
// 学籍番号を入力してください

#include <stdio.h>

// swap関数
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// 配列中からpivotを選定する関数
int find_pivot(int array[], int left, int right) {
  int pivot = array[left];

  for ( int i = left + 1; i <= right; i++) {
    if (pivot != array[i])
      return (pivot > array[i]) ? pivot : array[i];
  }
}

// 配列を大小で区分する関数
int partition(int array[], int left, int right) {
  int pivot = find_pivot(array, left, right);
  
  while ( left < right ) {
    while (array[left] < pivot)
      left++;
    while (array[right] >= pivot)
      right--;
    if (left > right)
      break;
    swap(&array[left], &array[right]);
  }
  return left;
}

// クイックソート関数
void quickSort(int array[], int left, int right) {

  if (left >= right) // 終了条件
    return;

  int k = partition(array, left, right); // 要素番号kを始点にpivot以上が並ぶ
  
  // 再帰呼び出し
  quickSort(array, left, k-1);
  quickSort(array, k, right);
  
  
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
  int array[] = {6,2,8,4,7,15,35,44,5,103,9};

  int N = sizeof(array) / sizeof(array[0]);

  printArray(array, N);
  
  quickSort(array, 0, N - 1); // クイックソートの実行

  printArray(array, N);
  
  return 0;
}
