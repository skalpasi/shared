#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *left, *right;
} * root;
int first = 1;
struct Node *init() {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
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
void preorder(struct Node *root) {
  if (root == NULL)
    return;
  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->right);
}
int main() {
  root = init();
  preorder(root);
  return 0;
}
