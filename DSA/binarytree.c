#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *left, *right;
} BST;

int first = 1;
BST *init() {
  BST *node = (BST *)malloc(sizeof(BST));
  int data;
  if (first)
    printf("Enter root data: ");
  first = 0;
  scanf("%d", &data);
  if (data == -1)
    return NULL;
  node->data = data;
  printf("Enter left data of %d: ", node->data);
  node->left = init();
  printf("Enter right data of %d: ", node->data);
  node->right = init();
  return node;
}

void preorder(BST *root) {
  if (root == NULL)
    return;
  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->right);
}

void inorder(BST *root) {
  if (root == NULL)
    return;
  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

void postorder(BST *root) {
  if (root == NULL)
    return;
  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->data);
}

void insert(BST **root, int item) {
  BST *node = malloc(sizeof(BST));
  node->data = item;
  node->left = node->right = NULL;
  if (*root == NULL) {
    *root = node;
    return;
  }
  BST *curr = *root, *prev = NULL;
  while (curr != NULL) {
    prev = curr;
    if (item < curr->data)
      curr = curr->left;
    else if (item > curr->data)
      curr = curr->right;
    else
      return;
  }
  if (node->data < prev->data)
    prev->left = node;
  else
    prev->right = node;
}

int main() {
  BST *root = NULL;
  insert(&root, 100);
  insert(&root, 38);
  insert(&root, 50);
  insert(&root, 10);
  inorder(root);
  return 0;
}
