// データ構造とアルゴリズム
// 集合の表現法
// ヒープ（優先度付き待ち行列）


#include <stdio.h>

// 配列の最大サイズ
#define MAX_SIZE 100

// ヒープを表現する構造体
typedef struct {
  int data[MAX_SIZE];
  int last; // 最後尾の要素番号
} Heap;

// ヒープを初期化する関数
void initHeap(Heap* heap) {
  for (int i = 0; i < MAX_SIZE; i++) {
    heap->data[i] = 9999999;
  }
  heap->last = -1;
}

// swap関数
void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// enheap関数
void enheap(Heap* heap, int data) {
  // 最後尾に要素を挿入
  heap->last++;
  heap->data[heap->last] = data;

  // 親ノードとの比較処理
  int current = heap->last;
  int temp;
  while (current > 0) {
    if (heap->data[current] < heap->data[(current-1)/2]) { // C＜親
      swap(&heap->data[current],&heap->data[(current-1)/2]); // C＞親
      current = (current-1)/2; // 親へ移動　次
    } else {
      return;
    }
  }
}

// deheap関数（最小ノードを取り出す関数）
int deheap(Heap* heap) {
  // 根ノードを取り出す
  int data = heap->data[0];
  // 空いた根ノードへ最後尾ノード追加
  heap->data[0] = heap->data[heap->last];
  heap->last--;

  // 子ノードとの比較処理
  int current = 0;
  int temp;
  while (current*2+1 <= heap->last) { // Cに（左の）子が存在（交換の余地アリ）
    if (heap->data[current] > heap->data[current*2+1]) { // C > 左（交換発生）
      if (heap->data[current*2+1] > heap->data[current*2+2]) { // 左 > 右
	swap(&heap->data[current],&heap->data[current*2+2]); // （右と交換）
	current = current*2+2;
      }
      else {	// 左 < 右
	swap(&heap->data[current],&heap->data[current*2+1]); // （左と交換）
	current = current*2+1;
      }
      
    }
    else if (heap->data[current] > heap->data[current*2+2]) { // （C < 左）C > 右
      swap(&heap->data[current],&heap->data[current*2+2]); // （右と交換）
      current = current*2+2;
    }
    else {
      return data;
    }
  }
  return data;
}

// ヒープの要素を一覧表示する関数
void displayHeap(Heap* heap) {
  printf("-現在の要素一覧-\n");
  for(int i = 0; i <= heap->last; i++) {
    printf("%d\n", heap->data[i]);
  }
}

int main(void) {
  Heap heap;
  initHeap(&heap);

  /*
  // enheap処理
  enheap(&heap, 20);
  enheap(&heap, 30);
  enheap(&heap, 10);
  enheap(&heap, 40);
  enheap(&heap, 5);

  displayHeap(&heap);

  // deheap処理
  deheap(&heap);
  deheap(&heap);
  deheap(&heap);

  displayHeap(&heap);
  */

  enheap(&heap,31);
  enheap(&heap,21);
  enheap(&heap,48);
  enheap(&heap,9);
  deheap(&heap);
  enheap(&heap,26);
  enheap(&heap,13);
  deheap(&heap);

  displayHeap(&heap);
  
  return 0;
}
