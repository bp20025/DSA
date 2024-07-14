// データ構造とアルゴリズム
// 基本的なデータ構造
// キュー（待ち行列）

#include <stdio.h>
#include <stdlib.h>

// 配列の最大サイズ
#define MAX_SIZE 100

// キューを表現する構造体
typedef struct {
  int items[MAX_SIZE];
  int front;
  int rear;
} Queue;

// キューを初期化する関数
void initQueue(Queue *queue) {
  queue->front = 0;
  queue->rear = -1;
}

// キューが空か判定する関数
int isEmpty(Queue *queue) {
  return (queue->rear < queue->front);
}

// キューが飽和か判定する関数
int isFull(Queue *queue) {
  return (queue->rear == MAX_SIZE - 1);
}

// enqueue関数
void enqueue(Queue *queue, int data) {
  if (isFull(queue)) {
    printf("待ち行列が飽和しています\n");
    return;
  }
  queue->rear++;
  queue->items[queue->rear] = data;
}

// dequeue関数
int dequeue(Queue *queue) {
  if (isEmpty(queue)) {
    printf("待ち行列が空です\n");
    exit(EXIT_FAILURE);
  }
  int data = queue->items[queue->front];
  queue->front++;
  return data;
}

// キューの要素を一覧表示する関数
void displayQueue(Queue *queue) {
  if (isEmpty(queue)) {
    printf("キューが空です\n");
    return;
  }
  printf("現在のキュー状況: ");
  for (int i = queue->front; i <=queue->rear; i++) {
    printf("%d ", queue->items[i]);
  }
  printf("\n");
}
    
  

int main() {
  Queue queue;
  initQueue(&queue);

  // enqueue処理
  enqueue(&queue, 10);
  enqueue(&queue, 20);
  enqueue(&queue, 30);

  displayQueue(&queue);

  // dequeue処理
  while(1) {
    printf("dequeue:%d\n", dequeue(&queue));
  }

  return 0;
}
  
