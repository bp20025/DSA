// 電気通信大学 2022
// 有向グラフの接続関係を表現する配列の完成

#include <stdio.h>


// キューに関する定義
#define max 10 // queueの最大の要素数
int queue[max+1];
int head; // 先頭index
int tail; // 末尾index

// 処理に関する定義
#define N 5 // ノード数
#define M 7 // エッジ数
int number[N+M+1]; // シンクノードの保存
int next[N+M+1]; // 次のindex
struct edge { // s -> t の有向辺
  int s;
  int t;
};

// キューに関する関数
void queueinit(); // キューを初期化する関数
int queueempty(); // キューの空を判定する関数
void put(int val); // push関数
int get(); // pop関数

// 処理に関する関数
void edgeinit(struct edge E[M+1]);
void construct(struct edge E[M+1]);  // 有向グラフの接続関係を表現する配列を完成する関数



int main() {
  int result = 0;
  struct edge E[M+1];
  edgeinit(E); // Eの初期化
  
  queueinit(); // キューの初期化

  construct(E); // 有向グラフの接続関係を表現する配列を完成する関数

  for (int i = 1; i <= M+N; i++) {
    printf("%d %d\n", number[i], next[i]);
  }

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

void edgeinit(struct edge E[M+1]) {
    E[1].s = 1; E[1].t = 3;
    E[2].s = 1; E[2].t = 5;
    E[3].s = 2; E[3].t = 1;
    E[4].s = 2; E[4].t = 3;
    E[5].s = 3; E[5].t = 4;
    E[6].s = 4; E[6].t = 1;
    E[7].s = 5; E[7].t = 4;
}

void construct(struct edge E[M+1]) { // 有向グラフの接続関係を表現する配列を完成する関数
  for (int k = 1; k <= N+M; k++) {
    number[k] = 0;
    next[k] = 0;
  }
  for (int k = 1; k <= M; k++) {
    int index = E[k].s;
    while (next[index] != 0) {
      index = next[index];
    }
    next[index] = N + k;
    number[next[index]] = E[k].t;
  }
}
  
  

