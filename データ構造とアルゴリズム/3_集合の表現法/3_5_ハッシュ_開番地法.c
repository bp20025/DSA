// データ構造とアルゴリズム
// 3：集合の表現法
// 5：ハッシュ（開番地法）
// 芝浦工業大学システム理工学部電子情報システム学科

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10
#define DELETED 0

// ハッシュテーブルの要素の構造体
struct HashEntry {
  int data;
  int isOccupied; // エントリの使用の可否を示すフラグ
};

// ハッシュテーブルの構造体
struct HashTable {
  struct HashEntry* table;
  int size;
  
};

// ハッシュテーブルの初期化
struct HashTable* initHashTable() {
  struct HashTable* ht = (struct HashTable*)malloc(sizeof(struct HashTable));
  ht->table = (struct HashEntry*) malloc(TABLE_SIZE * sizeof(struct HashEntry));

  for (int i = 0; i < TABLE_SIZE; i++) {
    ht->table[i].isOccupied = 0;
  }
  return ht;
}

// ハッシュ関数
int HashFunction(int key) {
  return key % TABLE_SIZE;
}


// ハッシュテーブルにデータを挿入する関数
void insert(struct HashTable* ht, int data) {
  int index = HashFunction(data);
  while (ht->table[index].isOccupied && ht->table[index].data != DELETED) {
    index++;
  }
  ht->table[index].data = data;
  ht->table[index].isOccupied = 1;
}

// ハッシュテーブルの要素を検索する関数
int search(struct HashTable* ht, int data) {
  int index = HashFunction(data);
  while (ht->table[index].isOccupied) { // 要素が存在する限り試行
    if (ht->table[index].data == data) {
      return 1;
    }
    index++; // 次候補へ
  }
  return 0;
}

// ハッシュテーブルから要素を削除する関数
int delete(struct HashTable* ht, int data) {
  int index = HashFunction(data);
  while (ht->table[index].isOccupied) { // 要素が存在する限り試行
    if (ht->table[index].data == data) {
      ht->table[index].data = DELETED; // DELETEDを代入（同indexを通過する他の値へのアクセスを保つ為）
      return 1;
    }
    index++;
  }
  return 0;
}

// ハッシュテーブルを一覧表示する関数
void display(struct HashTable* ht) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    printf("%d: ", i);
    printf("%d\n", ht->table[i].data);
  }
}

int main() {
  struct HashTable* ht = initHashTable();

  // データの挿入
  insert(ht, 11);
  insert(ht, 21);

  // ハッシュテーブルの表示
  printf("-- ハッシュテーブルの内容--\n");
  display(ht);

  // データの検索

  // データの削除

  return 0;
}
  


    
    
  
							   
