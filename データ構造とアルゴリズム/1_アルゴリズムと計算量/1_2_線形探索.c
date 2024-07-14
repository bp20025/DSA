// 線形探索を実現するプログラム

#include <stdio.h>

int LinearSearch (int A[], int size, int b) {
  for (int i = 0; i < size; i++) {
    if (A[i] == b) {
      return 1; // 真
    }
  }
  return 0;
}

int main() {
  int A[] = {1,3,5,7,9,11,13};
  int size = sizeof(A) / sizeof(A[0]); // 配列の要素数
  int b;

  printf("整数値を探索します\n");
  printf("探索する整数値を入力してください->");
  scanf("%d", &b);

  if(LinearSearch(A, size, b))  // 配列Aに整数bが存在するか線形探索
    printf("%dは配列中に存在します\n", b);
  else
    printf("%dは配列中に存在しません\n", b);

  return 0;
}
