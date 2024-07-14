// 基本的なデータ構造
// 配列とリスト
// 配列


#include <stdio.h>

// 配列の全要素を一覧表示する関数
void printElement(int array[], int *size) {
  printf("現在の配列：-> ");
  for (int i = 0; i < *size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

// 指定のインデックスに要素を追加する関数
void insertElement(int array[], int *size, int index, int element) {
  for (int i = *size-1; i >= index; i--) {
    array[i+1] = array[i]; // 対象の要素番号iに関して、一つずらす
  }
  array[index] = element; // 空いた？要素番号indexに要素elementを追加
  (*size)++; // 配列の要素数をインクリメント
}

// 指定のインデックスの要素を削除する関数
void deleteElement(int array[], int *size, int index) {
  for (int i = index; i < *size - 1; i++) {
    array[i] = array[i+1];
  }
  (*size)--; // 配列の要素数をデクリメント
}

  
  


int main() {
  int array[10] = {1,2,3,4,5};
  int size = 5; // 現在の配列の要素数を保存する
  // int size = sizeof(array) / sizeof(array[0]);

  int index; // インデックスに関する情報を保持する変数
  int element; // 要素に関する情報を保持する関数

  // 配列の全要素を一覧表示
  printElement(array, &size);


  // 指定されたインデックスに要素を追加
  printf("追加先のインデックスを指定してください: ");
  scanf("%d", &index);

  printf("追加する要素を指定してください: ");
  scanf("%d", &element);

  insertElement(array, &size, index, element);

  printf("変更が完了しました\n");
  printElement(array, &size);

  // 指定されたインデックスの要素を削除
  printf("削除する要素のインデックスを指定してください: ");
  scanf("%d", &index);

  deleteElement(array, &size, index);

  printf("変更が完了しました\n");
  printElement(array,&size);

  printf("編集を終了します\n");
  
  return 0;
}
