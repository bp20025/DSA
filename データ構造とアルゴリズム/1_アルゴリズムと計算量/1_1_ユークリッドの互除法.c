// ユークリッドの互除法を実現する関数

#include <stdio.h>

int Euclid(int m, int n) { // 整数mとnの最大公約数をreturn
  int r; // 剰余

  if (m < n) {
    int temp = m;
    m = n;
    n = temp;
  }
  
  while(n != 0) { // n=0（剰余0）なら終了
    r = m % n;
    m = n;
    n = r;
  }
  return m;
}

int main() {
  int m, n; // ２数
  int ans; // 最大公約数
  
  printf("最大公約数を導出します\n");
  printf("2つの数を入力してください->");
  scanf("%d %d", &m, &n);

  // 最大公約数を導出
  ans = Euclid(m, n);

  printf("最大公約数: %d\n", ans);

  return 0;
}
  
