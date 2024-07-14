// データ構造とアルゴリズム
// 4:整列（ソート）
// 4:ヒープソート
// ＊相違点
// pushdown関数はwhileループにより半順序性を担保
// 芝浦工業大学システム理工学部電子情報システム学科

#include <stdio.h>


// swap関数
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// ヒープを再構築する関数？
void pushdown(int arr[], int root, int last) {
 
  int L; int R; // (index)

  int LR;

  while((L = root * 2 + 1) <= last) {
    R = L + 1;

    LR = (R <= last && arr[L] > arr[R]) ? R : L;

    if (arr[root] > arr[LR]) { // arr[L] OR arr[R]がarr[first]より小さい
      swap(&arr[root], &arr[LR]);

      root = LR;
    } else {
      return; // 変更なし（半順序性担保）
    }
  }

}

// ヒープソートを実行する関数
void heapSort(int arr[], int n) {

  for (int i = n / 2 - 1; i >= 0; i--)
    pushdown(arr, i, n - 1);

  for (int last = n - 1; last > 0; last--) {
    swap(&arr[0], &arr[last]); // rootをlastへ掃き出し

    pushdown(arr, 0, last - 1);
  }
}

// 配列の要素を表示する関数
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main(void) {
  int arr[] = {12,32,24,45,18,11,34};

  int n = sizeof(arr) / sizeof(arr[0]);

  printf("現在の配列の状態: ");
  printArray(arr, n);

  heapSort(arr, n);

  printf("現在の配列の状態: ");
  printArray(arr, n);

  return 0;
}
