#include <stdio.h>
#include <stdlib.h>

// 便宜的に最大と最小を与える
#define INT_MAX 801
#define INT_MIN 20

// 二分木のノードの定義 ***
typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
    struct Node *parent; // 親ポインタを追加
} Node;

// 関数プロトタイプ宣言
Node* createNode(int value, Node* parent); // 新しいノードを作成する関数
void addNode(Node **root, int value); // ノードを追加する関数
void inorderPrint(Node *root); // 中順走査で表示
int is_bst(Node *t, int min, int max); // 二分木の成立を判定する関数 ***
Node* findMin(Node *node); // 最小値を探索・取得する関数
Node* deleteNode(Node* root, int value); // データを削除する関数

// メイン関数
int main() {
    Node *root = NULL;
    addNode(&root, 50);
    addNode(&root, 30);
    addNode(&root, 70);
    addNode(&root, 20);
    addNode(&root, 40);
    addNode(&root, 60);
    addNode(&root, 80);

    addNode(&root, 510);
    addNode(&root, 301);
    addNode(&root, 701);
    addNode(&root, 201);
    addNode(&root, 401);
    addNode(&root, 601);
    addNode(&root, 801);

    printf("二分木の中順走査: ");
    inorderPrint(root);
    printf("\n");

    printf("%d\n", is_bst(root, INT_MIN, INT_MAX));

    root = deleteNode(root, 50);
    printf("二分木の中順走査 (50削除後): ");
    inorderPrint(root);
    printf("\n");

    return 0;
}

// 新しいノードを作成する関数
Node* createNode(int value, Node* parent) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("メモリの割り当てに失敗しました\n");
        exit(1);
    }
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = parent; // 親ポインタを設定
    return newNode;
}

// 二分木にノードを追加する関数
void addNode(Node **root, int value) {
    if (*root == NULL) {
        *root = createNode(value, NULL);
        return;
    }

    Node *current = *root;
    Node *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (value < current->value) {
            if (current->left == NULL) {
                current->left = createNode(value, parent);
                return;
            } else {
                current = current->left;
            }
        } else {
            if (current->right == NULL) {
                current->right = createNode(value, parent);
                return;
            } else {
                current = current->right;
            }
        }
    }
}

// 中順走査 (In-order traversal) で二分木を表示する関数
void inorderPrint(Node *root) {
    if (root == NULL) return;
    inorderPrint(root->left);
    printf("%d ", root->value);
    inorderPrint(root->right);
}

// 二分木の成立を判定する関数 ***
int is_bst(Node *t, int min, int max) {
    if (t == NULL) return 1;
    else if (t->value < min || t->value > max) return 0;
    else return is_bst(t->left, min, t->value) &&
                is_bst(t->right, t->value, max);
}

// 最小値を探索・取得する関数
Node* findMin(Node *node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// ノードを削除する関数
Node* deleteNode(Node* root, int value) {
    if (root == NULL) return root;

    if (value < root->value) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->value) {
        root->right = deleteNode(root->right, value);
    } else {
        // ノードを発見
        if (root->left == NULL) {
            Node* temp = root->right;
            if (temp != NULL) temp->parent = root->parent;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            if (temp != NULL) temp->parent = root->parent;
            free(root);
            return temp;
        }

        // 左右の子を持つ場合
        Node* temp = findMin(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}
