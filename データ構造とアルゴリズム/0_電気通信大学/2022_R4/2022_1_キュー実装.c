// 電気通信大学 2022
// スタック実装

#include <stdio.h>

#define max 10 // queueの最大の要素数

int queue[max+1];
int head; // 先頭index
int tail; // 末尾index

void queueinit(); // キューを初期化する関数
int queueempty(); // キューの空を判定する関数
void put(int val); // enqueue関数
int get(); // dequeue関数

int main() {
  int result = 0;

  queueinit();
  
  put(4);
  put(5);
  put(3);

  result = get() + get() - get();

  printf("-> %d\n", result);

  return 0;
}

void queueinit() { // キューを初期化する関数
  head = 0;
  tail = 0;
}

int queueempty() { // キューの空を判定する関数
  return head == tail;
}

void put(int val) { // push関数
  tail++;
  queue[tail] = val;
}

int get() { // pop関数
  head++;
  int val = queue[head];
  return val;
}

