#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10
#define DELETED 0

// ハッシュテーブルの要素を表す構造体
struct HashEntry {
    int data;
    int isOccupied; // エントリが使用されているかどうかを示すフラグ
};

// ハッシュテーブルを表す構造体
struct HashTable {
    struct HashEntry *table;
};

// ハッシュテーブルの初期化
struct HashTable *initHashTable() {
    struct HashTable *ht = (struct HashTable *)malloc(sizeof(struct HashTable));
    ht->table = (struct HashEntry *)malloc(TABLE_SIZE * sizeof(struct HashEntry));
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i].isOccupied = 0;
    }
    return ht;
}

// ハッシュ関数（簡単なモジュロ法を使用）
int hashFunction(int data) {
  return data % TABLE_SIZE;
}

// キーを使用してハッシュテーブルにデータを挿入
void insert(struct HashTable *ht, int data) {
  int index = hashFunction(data);
  while (ht->table[index].isOccupied || ht->table[index].data == DELETED) {
        index++; // 次候補へ
    }
    ht->table[index].data = data;
    ht->table[index].isOccupied = 1;
}

// ハッシュテーブルから要素を検索
int search(struct HashTable *ht, int data) {
  int index = hashFunction(data);
  while (ht->table[index].isOccupied) {
    if (ht->table[index].data == data) { // 成功
            return 1;
        }
	index++; // 次候補へ
    }
  return 0; // 失敗
}

// ハッシュテーブルを一覧表示する関数
void display(struct HashTable* ht) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    printf("%d: ", i);
    printf("%d\n", ht->table[i].data);
  }
}

int main() {
    struct HashTable *ht = initHashTable();

    // ハッシュテーブルにデータを挿入
    insert(ht, 5);
    insert(ht, 2);
    insert(ht, 15);
    insert(ht, 7);

  // ハッシュテーブルの表示
  printf("-- ハッシュテーブルの内容--\n");
  display(ht);
    free(ht->table);
    free(ht);

    return 0;
}

