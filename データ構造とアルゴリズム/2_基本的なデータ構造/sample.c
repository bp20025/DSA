#include <stdlib.h>
#include <stdio.h>

#define TRUE	(1)
#define FALSE	(0)

typedef struct _LIST{
	int data1;
	int data2;
	struct _LIST *next;
}LIST;
LIST *ListTop = NULL;	// リスト構造の先頭を示す変数をポインタで宣言
LIST *ListEnd = NULL;	// リスト構造の終端を示す変数をポインタで宣言

// リスト構造に要素を追加する
_Bool ListPush(LIST *data)
{
	// エラーチェック
	if(data == NULL){
		return FALSE;
	}
	
	if(ListTop == NULL){
		// リストに登録されている要素数が0の場合
		ListTop = malloc(sizeof(LIST));
		if(ListTop == NULL){
			return FALSE;
		}
		ListEnd = ListTop;
	}else{
		// *nextに要素を追加
		ListEnd->next = malloc(sizeof(LIST));
		if(ListEnd == NULL){
			return FALSE;
		}
		ListEnd = ListEnd->next;
	}
	*ListEnd = *data;
	ListEnd->next = NULL;

	return TRUE;
}

// リスト構造の全要素を削除する
void ListClear(void)
{
	LIST *ListCur = ListTop;

	while(ListCur != NULL){
		LIST *temp = ListCur;
		ListCur = ListCur->next;
		free(temp);
	}
	ListTop = NULL;
}

int main(void)
{
	LIST data, *ListCur;

	// リスト構造にデータを追加
	data.data1 = 1;
	if(ListPush(&data) == FALSE){
		printf("要素の追加に失敗しました。\n");
	}

	data.data1 = 2;
	if(ListPush(&data) == FALSE){
		printf("要素の追加に失敗しました。\n");
	}

	data.data1 = 3;
	if(ListPush(&data) == FALSE){
		printf("要素の追加に失敗しました。\n");
	}

	// リスト構造のデータを表示
	printf("=== リスト構造のデータを表示 ===\n");
	for(ListCur=ListTop; ListCur!=NULL; ListCur=ListCur->next){
		printf("data1 = %d\n", ListCur->data1);
	}

	// リスト構造のデータを全削除
	ListClear();

	// リスト構造のデータを表示
	printf("=== リスト構造のデータを表示 ===\n");
	for (ListCur = ListTop; ListCur != NULL; ListCur = ListCur->next) {
		printf("data1 = %d\n", ListCur->data1);
	}

	return 0;
}
