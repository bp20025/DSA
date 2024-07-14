// データ構造とアルゴリズム
// 基本的なデータ構造
// スタック

#include <stdio.h>
#include <stdlib.h>

// 配列の最大サイズ
#define MAX_SIZE 100

// スタックを表現する構造体
typedef struct {
  int array[MAX_SIZE];
  int top;
} Stack;


// スタックを初期化する関数
void initializeStack(Stack* stack) {
  stack->top = -1;
}


// スタックが空か判定する関数
int isEmpty(Stack* stack) {
  return (stack->top == -1);
}

// スタックが飽和か判定する関数
int isFull(Stack* stack) {
  return (stack->top == MAX_SIZE - 1);
}


// push関数
void push(Stack* stack, int data) {
  if (isFull(stack)) { // スタックが飽和である場合
    printf("スタックが飽和しています。");
    return;
  }
  stack->top++;
  stack->array[stack->top] = data;
}

// pop関数
int pop(Stack* stack) {
  if (isEmpty(stack)) { // スタックが空である場合
    printf("スタックが空です\n");
    exit(EXIT_FAILURE);
  }
  
  int data = stack->array[stack->top];
  stack->top--;
  // 位置だけずらせば実体を消さなくとも後に上書きされるし、されなくても参照されないし無いも同然
  return data;
}

// スタックに格納されている全要素を表示する関数
void displayStack(Stack* stack) {
  if (isEmpty(stack)) { // スタックが空である場合
    printf("スタックが空です\n");
    return;
  }
  printf("現在のスタック状況: ");
  for (int i = 0; i <= stack->top; i++) { // 先頭要素まで画面表示
    printf("%d ", stack->array[i]);
  }
  printf("\n");
}

int main() {
  Stack stack;
  initializeStack(&stack);

  // プッシュ処理
  push(&stack, 10);
  push(&stack, 20);
  push(&stack, 30);

  displayStack(&stack); // スタックの要素を表示

  // ポップ処理
  while(1) {
    printf("pop:%d\n", pop(&stack));
  }

  return 0;
}
  
  

  

  
  
  
  
  
