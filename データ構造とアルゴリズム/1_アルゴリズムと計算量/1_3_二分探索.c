// 二分探索を実現するプログラム
#include <stdio.h>

int BinarySearch (int A[], int n, int b) {
  int min = 0;
  int max = n-1;
  int mid; // 中間値を保存する変数
 
  while(min <= max) { // 探索対象の要素が１つだけ残ると「min=max」
    mid = (min + max) / 2;
    printf("%d %d, 比較対象となる配列のインデックスは%dです\n", min,max,mid);
    
    if(A[mid] == b) {
      return 1;
    } else if (A[mid] > b) {
      max = mid - 1; // 最大値を更新
    } else {
      min = mid + 1; // 最小値を更新
    }
    
  }

  return 0; // 探索する整数が存在しなかった場合
  
}
  

int main() {
  int A[] = {1,3,5,7,9,11,13};
  int size = sizeof(A) / sizeof(A[0]); // 配列の要素数
  int b;

  printf("整数値を探索します\n");
  printf("探索する整数値を入力してください->");
  scanf("%d", &b);

  if(BinarySearch(A, size, b)) // 配列Aに整数bが存在するか二分探索
    printf("%dは配列中に存在します\n", b);
  else
    printf("%dは配列中に存在しません\n", b);

  return 0;
}
