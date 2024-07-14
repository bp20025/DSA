// データ構造とアルゴリズム
// 4:整列（ソート）
// 5:バケットソート
// 芝浦工業大学システム理工学部電子情報システム学科

#include <stdio.h>

#define MAX_SIZE 100

// 配列の初期化を行う関数
void initializeArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    arr[i] = -1;
}

// 配列の要素を一覧表示する関数
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == -1) // 配列にまだ何も格納されていない場合
      continue;
  
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// パワー関数
void power(int arr[], int sortedArr[],  int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      if (arr[i] == j) {
	sortedArr[j] = arr[i];
	break;
      }
    }
  }
}

int main() {
  int arr[] = {12,3,57,32,11,13,9,29,20};
  int sortedArr[MAX_SIZE];

  initializeArray(sortedArr, MAX_SIZE);
  
  int n = sizeof(arr) / sizeof(arr[0]);
  
  printf("整数に関するソートを実行します\n");

  printf("配列の状態: ");
  printArray(arr, n);

  power(arr, sortedArr, n); // バケットソート

  // 芝浦工業大学システム理工学部電子情報システム学科
  // 学籍番号を入力してください

  printf("配列の状態: ");

  printArray(sortedArr, MAX_SIZE);

  return 0;
}
