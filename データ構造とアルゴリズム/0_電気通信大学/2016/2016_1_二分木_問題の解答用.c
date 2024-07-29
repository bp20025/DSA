#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

struct node* create_node(int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void add_node(struct node* parent, int value, char side) {
    struct node* new_node = create_node(value);
    if (side == 'L') {
        if (parent->left == NULL) {
            parent->left = new_node;
        } else {
            printf("Left child already exists\n");
            free(new_node); // Free the newly allocated node
        }
    } else if (side == 'R') {
        if (parent->right == NULL) {
            parent->right = new_node;
        } else {
            printf("Right child already exists\n");
            free(new_node); // Free the newly allocated node
        }
    } else {
        printf("Invalid side. Use 'L' for left and 'R' for right.\n");
        free(new_node); // Free the newly allocated node
    }
}

void postorder_print(struct node *t) { // 後順走査で画面表示する関数
  if (t == NULL)
    return;
  postorder_print(t->left); // 左の子孫へ
  postorder_print(t->right); // 右の子孫へ
  printf("%d ", t->value);
}

// Sample main function for testing
int main() {
    struct node* root1 = create_node(1);
    add_node(root1, 2, 'L');
    add_node(root1, 3, 'R'); 
    add_node(root1->right, 4, 'L');

    struct node* root2 = create_node(1);
    add_node(root2, 2, 'L');  
    add_node(root2, 3, 'R');  
    add_node(root2->left, 4, 'R'); 
    add_node(root2->right, 5, 'L'); 
    add_node(root2->right->left, 6, 'L');
    add_node(root2->right->left, 7, 'R');

    postorder_print(root1);
    printf("\n");
    postorder_print(root2);
    printf("\n");
    
    return 0;
}
