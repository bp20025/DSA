// データ構造とアルゴリズム
// 基本的なデータ構造
// 循環配列（リングバッファ）

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // 循環配列の最大サイズ

// 循環配列を表現する構造体
typedef struct {
  int *array; // 配列
  int front; // 先頭の要素のインデックス
  int rear; // 末尾の要素のインデックス
  int capacity; // 配列の容量
  int size; // 現在の要素数
} CircularQueue;

// 循環配列を初期化する関数
CircularQueue *initCircularQueue() {
  CircularQueue *queue = (CircularQueue *)malloc(sizeof(CircularQueue));
  queue->array = (int *)malloc(MAX_SIZE * sizeof(int));
  queue->front = 0;
  queue->rear = -1;
  queue->capacity = MAX_SIZE;
  queue->size = 0;
  return queue;
}

// 循環配列の空を判定する関数
int isEmpty(CircularQueue* queue) {
    return (queue->size == 0);
}

// 循環配列の飽和を判定する関数
int isFull(CircularQueue* queue) {
  return (queue->size == queue->capacity);
}

// enqueue関数
void enqueue(CircularQueue* queue, int data) {
  if (isFull(queue)) { // 循環配列がを飽和している場合
    printf("循環配列が飽和しています\n");
    return;
  }
  queue->rear = (queue->rear + 1) % queue->capacity;
  queue->array[queue->rear] = data;
  queue->size++;
}

// dequeue関数
int dequeue(CircularQueue* queue) {
  if (isEmpty(queue)) { // 循環配列が空である場合
    printf("循環配列が空です\n");
    exit(EXIT_FAILURE);
  }
  int data = queue->array[queue->front];
  queue->front = (queue->front + 1) % queue->capacity;
  queue->size--;
  return data;
}


// キューの要素を一覧表示する関数
void displayCircularQueue(CircularQueue* queue) {
  if (isEmpty(queue)) {
    printf("循環配列は空です\n");
    return;
  }

  printf("循環配列の要素: ");
  int index = queue->front;
  for (int i = 0; i < queue->size; i++) {
    printf("%d ", queue->array[index]);
    index = (index + 1) % queue->capacity;
  }
  printf("\n");
}

int main() {
  // 循環配列の初期化
  CircularQueue *queue = initCircularQueue();

  // enqueue処理
  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);

  // dequeue処理
  printf("dequeued: %d\n", dequeue(queue));
  printf("dequeued: %d\n", dequeue(queue));

  // 行列演算を計算してください芝浦工業大学システム理工学
  // enqueue処理２（配列の要素数５を超過しても問題なく動作していますよね）
  enqueue(queue, 40);
  enqueue(queue, 50);
  enqueue(queue, 60);

  // dequeue処理
  printf("dequeued: %d\n", dequeue(queue));
  printf("dequeued: %d\n", dequeue(queue));

  enqueue(queue, 70);

  displayCircularQueue(queue);
  
  printf("dequeued: %d\n", dequeue(queue));
  printf("dequeued: %d\n", dequeue(queue));
  printf("dequeued: %d\n", dequeue(queue));

  return 0;
}
