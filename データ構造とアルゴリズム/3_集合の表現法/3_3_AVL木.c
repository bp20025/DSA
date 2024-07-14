// データ構造とアルゴリズム
// 集合の表現法
// AVL木
// 芝浦工業大学システム理工学部電子情報システム学科

#include <stdio.h>
#include <stdlib.h>

// ２分探索木を表現する構造体
typedef struct node {
  int object;
  int height; // 各ノードの高さ情報
  struct node *left;
  struct node *right;
} Node;

// 新たに２分探索木を作成する関数
Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Memory allocation failed!\n");
    exit(1);
  }
  newNode->object = data;
  newNode->height = 1; // 新しいノードの高さは１
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// ノードの高さを取得する関数
int height(Node *node) {
  if (node == NULL) return 0;
  return node->height;
}

// 新しい高さを計算する関数
int max(int a, int b) {
  return (a > b) ? a : b;
}

// AVL木のバランスファクターを計算する関数
int getBalanceFactor(Node *node) {
  if (node == NULL) return 0;
  return height(node->left) - height(node->right); // （左の高さ）-（右の高さ）
}


// 右（R）回転を行う関数
Node *rightRotate(Node *node) {
  // 親子関係の更新
  Node *left = node->left;
  node->left = left->right;
  left->right = node;

  // 各ノードの高さの更新（高さが変わりうるのはnodeとleft）
  node->height = max(height(node->left),height(node->right)) + 1;
  left->height = max(height(left->left),height(left->right)) + 1;
  
  return left; // node = left
}

// 左（L）回転を行う関数
Node *leftRotate(Node *node) {
  // 親子関係の更新
  Node *right = node->right;
  node->right = right->left;
  right->left = node;

  // 各ノードの高さの更新（高さが変わりうるのはnodeとright)
  node->height = max(height(node->left),height(node->right));
  right->height = max(height(right->left),height(right->right));

  return right; // node = right;
}
  

// 適当な場所へ新しいノードを挿入する関数
Node *insert(Node *node, int object) {
  if (node == NULL) { // 引数として与えられたアドレス位置にノードが存在しない（適当な場所）
    return createNode(object); // 適当な場所へ新規ノードのアドレスをreturn
  }
  if (object < node->object) {
    node->left = insert(node->left,object); // 左を探索
  } else if (object > node->object) {
    node->right = insert(node->right,object); // 右を探索
  }

  // 高さの更新
  node->height = 1 + max(height(node->left),height(node->right));
  
  // バランスファクターを取得
  int balance = getBalanceFactor(node);
    
  // L過多 && L-Lへ挿入（TypeⅢ-a）
  if (balance > 1 && object < node->left->object) {
    return rightRotate(node); // nodeのR回転
  }
  // L過多 && L-Rへ挿入（TypeⅢ-b）
  if (balance > 1 && object > node->left->object) {
    node->left = leftRotate(node->left); // node->LのL回転
    return rightRotate(node); // nodeのR回転
  }
  
  // R過多 && R-Rへ挿入
  if (balance < -1 && object > node->right->object) {
    return leftRotate(node); // nodeのL回転
  }

  // R過多 && R-Lへ挿入
  if (balance < -1 && object < node->right->object) {
    node->right =  rightRotate(node->right); // node->RのR回転
    return leftRotate(node); // nodeのL回転
  }
    
    
  return node; // 引数として与えられたアドレスをreturn
}

// （右側）最小値を探索・取得する関数
int searchMin(Node *node)
{
  while (node->left != NULL) node = node->left;
  return node->object;
}

// （右側）最小値を探索・削除する関数
Node *deleteMin(Node *node)
{
  if (node->left == NULL) {
    Node *temp = node->right;
    free(node);
    return temp;
  }
  node->left = deleteMin(node->left);
  return node;
}
    
// データの削除
Node *deleteNode(Node *node, int object) {
  // アドレス位置にノードが存在しない場合（削除失敗）
  if (node == NULL) return NULL;
  if (object == node->object) {
    if (node->left == NULL) { // 「右のみ存在」OR「なし」
      Node *temp = node->right;
      free(node);
      return temp;
    }
    if (node->right == NULL) { // 「左のみ存在」OR「なし」
      Node *temp = node->left;
      free(node);
      return temp;
    }
    // 「左右に存在」
    node->object = searchMin(node->right);
    node->right = deleteMin(node->right);
  }
  else if (object < node->object) {
    node->left = deleteNode(node->left, object); // 左を探索
  }
  else
    node->right = deleteNode(node->right, object); // 右を探索

  // AVL木の処理の追加

  // 高さの更新
  if (node == NULL) return node; // 再帰終了条件

  node->height = 1 + max(height(node->left), height(node->right));

  // バランスの調整
  int balance = getBalanceFactor(node);

  // 左過多の場合
  if (balance > 1) {
    if (getBalanceFactor(node->left) >= 0) {
      return rightRotate(node); // LL型
    } else {
      node->left = leftRotate(node->left); // LR型
      return rightRotate(node);
    }
  }
  // 右過多の場合
  if (balance < -1) {
    if (getBalanceFactor(node->right) <= 0) {
      return leftRotate(node); // RR型
    } else {
      node->right = rightRotate(node->right); // RL型
      return leftRotate(node);
    }
  }
  
  return node;
}

// ２分探索木の格納状況を一覧表示する関数
void forEachNode(Node *node)
{
  if (node != NULL) {
    forEachNode(node->left);
    printf("%d\n", node->object);
    forEachNode(node->right);
  }
}
  

int main() {
  // ２分探索木のルートを初期化
  Node *root = NULL;
  /*
  // データを挿入（２分探索木　例題）
  root = insert(root,34);
  root = insert(root,51);
  root = insert(root,72);
  root = insert(root,17);
  root = insert(root,66);  
  root = deleteNode(root,51);
  root = deleteNode(root,34);
  */

  // データを挿入（AVL木　例題）
  root = insert(root,34);
  root = insert(root,51);
  root = insert(root,72);
  root = insert(root,17);
  root = insert(root,44);
  root = insert(root,50);

  // データの削除（AVL木　例題＊）
  root = deleteNode(root,17);
  root = deleteNode(root,34);

  // 結果
  forEachNode(root);
  return 0;
}
