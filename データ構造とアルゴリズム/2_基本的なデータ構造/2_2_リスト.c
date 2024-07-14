// 基本的なデータ構造
// 配列とリスト
// リスト

#include <stdlib.h>
#include <stdio.h>

#define TRUE (1)
#define FALSE (0)

// リスト構造を表現する構造体
typedef struct _LIST{
  int data;
  struct _LIST *next; // 自身の方を指すポインタを宣言
} LIST;
LIST *ListTop = NULL; // リスト構造の先頭を示すポインタ変数
LIST *ListEnd = NULL; // リスト構造の終端を示すポインタ変数


// リストの全要素を表示する関数
void printElement(LIST *ListCur) {
  printf("現在のリスト\n");
  for (ListCur=ListTop; ListCur!=NULL; ListCur=ListCur->next) {
    printf("data: %d\n", ListCur->data);
  }
}



// 先頭に要素を追加する関数
_Bool addElement(LIST *data) {
  // エラーチェック
  if(data == NULL) {
    return FALSE;
  }

  if(ListTop == NULL) {
      // 要素数０の場合
      ListTop = malloc(sizeof(LIST));
      if(ListTop == NULL) {
	return FALSE;
      }
      ListEnd = ListTop;
  }else{
    // *nextに要素を追加
    ListEnd->next = malloc(sizeof(LIST));
    if(ListEnd == NULL) {
      return FALSE;
    }
    ListEnd = ListEnd->next;
  }
  *ListEnd = *data;
  ListEnd->next = NULL;
  return TRUE;
}

// リストの全要素を削除する関数

void clearElement() {
  LIST *ListCur = ListTop;

  while (ListCur != NULL) {
    LIST *temp = ListCur;
    ListCur = ListCur->next; // 現在地を次のポインタへ
    free(temp);
  }
  ListTop = NULL;
}


// 指定したインデックスの要素を削除する関数
void deleteElement(int array[], int *size, int index) {

}

int main() {
  int size = 5; // 現在の配列の要素数を保存する

  LIST data, *ListCur;

  // リスト構造にデータを追加
  data.data = 1;
  if(addElement(&data) == FALSE) {
    printf("要素の追加に失敗しました\n");
  }
  data.data = 2;
  if(addElement(&data) == FALSE) {
    printf("要素の追加に失敗しました\n");
  }
  data.data = 3;
  if(addElement(&data) == FALSE) {
    printf("要素の追加に失敗しました\n");
  }

  // リストの全要素を表示する
  printElement(ListCur);

  // リスト構造のデータを全削除
  clearElement();
  printf("リストの全要素を削除しました\n");

  printElement(ListCur);

  return 0;
}
