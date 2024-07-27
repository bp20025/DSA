// 電気通信大学 2013
// 二分探索木（2013に従う）

#include <stdio.h>
#include <stdlib.h> // malloc関数の使用

struct n {
  int e;
  struct n* left;
  struct n* right;
};

void insert_node(struct n **p, int val); // 二分探索木にノードを追加する関数（再帰）
void insert_node_2(struct n **p, int val); // 二分探索木にノードを追加する関数（再帰なし）
struct n * deletemax(struct n *T, struct n ** result); // 二分探索木の最大値を削除する関数
struct n * decrease(struct n *T); // 二分探索木の根を変更する関数
void inorderPrint(struct n *s); // 二分探索木を一覧表示する関数

int same(struct n *T, struct n *U); // 二分探索木の一致判定

int main() {
  struct n* root = NULL;

  // 二分探索木へのノード追加
  insert_node_2(&root, 5);
  insert_node_2(&root, 3);
  insert_node_2(&root, 8);
  insert_node_2(&root, 2);
  insert_node_2(&root, 4);
  insert_node_2(&root, 7);

  // 生成した二分探索木を一覧表示
  inorderPrint(root);
  printf("\n");

  /*
  // (2):二分探索木の最大値の削除
  printf("二分探索木の最大値を削除します\n");
  struct n * result = NULL; // 最大値を受け取る変数
  root = deletemax(root, &result);
  printf("最大値: %d\n", result->e);
  printf("更新: ");
  inorderPrint(root);
  printf("\n");
  */

  // (3):二分探索木の根の削除
  printf("二分探索木の根を削除します\n");
  printf("二分探索木の根を変更します．この処理による二分探索木の持つ情報の変化はありません．\n");
  
  root = decrease(root);
  printf("更新: ");
  inorderPrint(root);
  printf("\n");

  // (4)二分探索木の一致判定
  struct n* root2 = NULL;

  // 二分探索木へのノード追加
  insert_node_2(&root2, 5);
  insert_node_2(&root2, 3);
  insert_node_2(&root2, 8);
  insert_node_2(&root2, 2);
  insert_node_2(&root2, 4);
  insert_node_2(&root2, 7);
  inorderPrint(root2);
  printf("\n");  

  printf("二分探索木の根を変更します．この処理による二分探索木の持つ情報の変化はありません．\n");
  root2 = decrease(root2);
  printf("更新: ");
  inorderPrint(root2);
  printf("\n");  
  

  if (same(root, root2))
    printf("同一の構造を持つ二分探索木です．\n");
  else
    printf("異なる構造を持つ二分探索木です．\n");

  insert_node_2(&root, 5);
  insert_node_2(&root2, 10);
  
  if (same(root, root2))
    printf("同一の構造を持つ二分探索木です．\n");
  else
    printf("異なる構造を持つ二分探索木です．\n");
  
  return 0;
}

// 二分探索木にノードを追加する関数（再帰）
void insert_node(struct n **p, int val) {
  if (*p != NULL) {
    if (val < (*p)->e)
      insert_node(&(*p)->left, val);
    else
      insert_node(&(*p)->right, val);
    return;
  }
  // 新規ノードの作成
  *p = (struct n *)malloc(sizeof(struct n));
  (*p)->e = val;
  (*p)->left = NULL;
  (*p)->right = NULL;
}

// 二分探索木にノードを追加する関数２（再帰なし） ***
void insert_node_2(struct n **p, int val) {
  struct n **current = p;
  while (*current != NULL) { // if文からwhileループへの変更
    if (val < (*current)->e)
      current = &(*current)->left;
    else
      current = &(*current)->right;
  }
  // 新規ノードの作成
  *current = (struct n *)malloc(sizeof(struct n));
  (*current)->e = val;
  (*current)->left = NULL;
  (*current)->right = NULL;
}

// 二分探索木の最大値を削除してできた二分探索木を返す関数
struct n *deletemax(struct n *T, struct n **result) {
  struct n *parent = NULL;
  struct n *current = T;
  
  while (current->right != NULL) {
    parent = current;
    current = current->right;
  }
  
  // *result = current; // 誤答: result = &current;
  *result = (struct n *)malloc(sizeof(struct n));
  (*result)->e = current->e;
  (*result)->left = NULL;
  (*result)->right = NULL;  

  // 削除処理
  if (parent == NULL)
    T = current->left; // 最大値が根ノードの場合
  else
    parent->right = current->left;
  // 誤答: current = current->left;

  free(current);//誤答:  free(current); 削除した最大ノードを取得する処理もあるので当然メモリ解放NG
  
  return T; // 削除してできた二分探索木を返す
}

/*
// 二分探索木の根を変更して得られる二分探索木を返す関数
struct n *decrease(struct n *T) {
  struct n *max = NULL; // 新たな根の更新処理
  
  if (T->left != NULL) {
    T->left = deletemax(T->left, &max);
    printf("左子最大ノードを抽出しました: %d\n", max->e);
  }
  else {
    return T;
    // free(T); // メモリ解放
    // return NULL;
  }

  // 新たな根の更新処理
  max->left = T->left;
  max->right = T->right;
  free(T); // メモリ解放
  return max; 
}
*/

// 二分探索木の根を変更して得られる二分探索木を返す関数
struct n *decrease(struct n *T) {
  struct n *max = NULL; // 新たな根の更新処理
  if (T->left == NULL) {
    return T;
  } else {
    T->left = deletemax(T->left, &max);
    printf("左子最大ノードを抽出しました: %d\n", max->e);
    // 新たな根の更新処理
    max->left = T->left;
    max->right = T;
    T->left = NULL;
  }
  return max;
}


// 中順走査 (In-order traversal) で二分木を表示する関数
void inorderPrint(struct n *s) {
    if (s == NULL) return;
    inorderPrint(s->left);
    printf("%d ", s->e);
    inorderPrint(s->right);
}

/*
int same(struct n *T, struct n *U) {
  while(1) {
    if (T==NULL && U==NULL) // T／Uいずれも要素が一致し続けて空集合になった
      return 1;
    else if (T==NULL || U==NULL)
      return 0;
    if (T->e != U->e)
      return 0;
    T = decrease(T);
    U = decrease(U);
  }
}
*/

/*
// 二分探索木の一致判定
int same(struct n *T, struct n *U) {
  while(1) {
    if (T==NULL && U==NULL)
      return 1;
    else if (T==NULL || U==NULL)
      return 0;
    if (T->e != U->e)
      return 0;
    printf("一致してるね%d%d\n", T->e, U->e);
    
    if (T->left != NULL) {
      T = decrease(T);
      U = decrease(U);
    } else {
      if (T->e != U->e)
	return 0;
      printf("一致してるね%d%d\n", T->e, U->e);
      T = T->right;
      U = U->right;
    }
  }
}
*/

// 二分探索木の一致判定
/*
// 二分探索木の一致判定
int same(struct n *T, struct n *U) {
    if (T == NULL && U == NULL)
        return 1; // 両方とも空の木なら同じ構造を持つとみなす
    else if (T == NULL || U == NULL)
        return 0; // どちらか片方が空の場合は異なる構造を持つとみなす
    else if (T->e != U->e)
        return 0; // ノードの値が異なる場合は異なる構造を持つとみなす

    // 左右の部分木を同様に比較
    return same(decrease(T->left), decrease(U->left)) && same(decrease(T->right), decrease(U->right));
}
*/
/*
// 二分探索木の一致判定
int same(struct n* T, struct n* U) {
  struct n* newT = NULL;
  struct n* newU = NULL;
  while(1) {
    newT = decrease(T);
    if (newT->e == T->e) // 左の根にノードが存在しなくなった
      break;
*/

/*
// 二分探索木の一致判定
int same(struct n *T, struct n *U) {
    // 両方ともNULLの場合、同じ構造
    if (T == NULL && U == NULL) return 1;

    // 片方だけNULLの場合、異なる構造
    if (T == NULL || U == NULL) return 0;

    // ノードの値が異なる場合、異なる構造
    if (T->e != U->e) return 0;

    // 次の根を左部分木の最大値に変更して再帰的にチェック
    return same(decrease(T), decrease(U));
}
*/

    
// 二分探索木の一致判定
int same(struct n *T, struct n *U) {
  // Tを右へ一直線に昇順に広がる木に変更
  for (struct n *cT = T; cT != NULL; cT = cT->right) {
    struct n *new_cT = NULL;
    while (1) {
      new_cT = decrease(cT);
      if (new_cT->e == cT->e) // 現在のノードcTにこれ以上，左子孫が存在しない
	break;
      cT = new_cT; // cTを更新後のcTとする
    }
  }
  // Uを右へ一直線に昇順に広がる木に変更
  for (struct n *cU = U; cU != NULL; cU = cU->right) {
    struct n *new_cU = NULL;
    while (1) {
      new_cU = decrease(cU);
      if (new_cU->e == cU->e) // 現在のノードcUにこれ以上，左子孫が存在しない
	break;
      cU = new_cU; // cUを更新後のcUとする
    }
  }
  while (1) {
    // （各元が一致し続けたまま）Tのすべての元への探索が終わった
    if (T == NULL) {
      if (U == NULL)
	return 1; // 同時にUもすべての元への探索が終わったら集合が一致
      else
	return 0; // 終わっていなければ集合は一致しない
    }
    if (T->e != U->e) // 一致しない場合
      return 0;
    // 次の値を探索
    T = T->right;
    U = U->right;
  }
}
