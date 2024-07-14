// データ構造とアルゴリズム
// 4:整列（ソート）
// 2:クイックソート方法３
// ・配列の分割を仮想的に行う
// ・pivotの選定方法：配列の異なる値の、大きいほう
// left-> <-rightと、左右から大小関係を担保
// 芝浦工業大学システム理工学部電子情報システム学科

#include <stdio.h>

// swap関数
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}


// 配列を一覧表示する関数
void printArray(int array[], int N) {
  printf("components of array: ");
  
  for (int i = 0; i < N; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

// 配列中からpivotを選定する関数
int find_pivot(int array[], int left, int right) {
  int pivot = array[left]; // pivot候補 = left

  int i;
  for (i = left + 1; i <= right; i++) {
    if ( array[i] != pivot ) {
      break;
    }
  }
  return (array[i] > pivot) ? array[i] : pivot; // デカい方を返す
}

// 配列を大小で区分する関数
int partition(int array[], int left, int right, int pivot) {
  while(1) {
    while ( array[left] < pivot )
      left++; // ~ (left - 1)　pivot未満が担保
    while ( array[right] >= pivot )
      right--; // (right + 1) ~ pivot以上が担保

    if ( left > right )
      break;

    swap(&array[left], &array[right]); // -> [~ left],[right ~]で大小関係が担保
  };
  return left; // leftはpivot以上の要素を指して終了
  // -> leftを始点にpivot以上が並ぶ（重要）
}

// クイックソート関数（find_pivot関数、partition関数の呼出、再帰的な挙動の実現）
void quickSort(int array[], int left, int right) {
  if (left >= right)
    return;
  
  int pivot = find_pivot(array, left, right);
  int k = partition(array, left, right, pivot); // kを始点にpivot以上が並ぶ

  printf("中途結果: ");
  printArray(array, right - left + 1); // temp

  // 再帰呼び出し（区分後の配列で同様の処理）（k-1とk以外はNGであることに注意）
  quickSort(array, left, k-1);
  quickSort(array, k, right);
}

int main(void) {
  int array[] = {6,2,8,4,7,3,9};

  int N = sizeof(array) / sizeof(array[0]);

  printArray(array, N);
  
  quickSort(array, 0, N - 1); // クイックソートの実行

  printArray(array, N);
  
  return 0;
}
  
