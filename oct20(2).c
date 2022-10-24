#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left, *right;
};

// Create a node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Inorder Traversal
void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d -> ", root->key);
    inorder(root->right);
  }
}

// Insert a node
struct node *insert(struct node *node, int key) {
 
  if (node == NULL) return newNode(key);

  
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

// To find the inorder successor
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  
  if (root == NULL) return root;

  
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // If the node has two children
    struct node *temp = minValueNode(root->right);
    root->key = temp->key;
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;
  int n, k, d;
  printf("Enter number of nodes\n");
  scanf("%d", &n);
  for (int i=0; i<n;i++)
  {
    printf("Enter node\n");
    scanf("%d", &k);
    root = insert(root, k);
  }
 
  printf("Enter value of node to be deleted\n");
  scanf("%d", &d);
  printf("Inorder traversal:\n");
  inorder(root);

  printf("\nAfter deleting\n");
  root = deleteNode(root, d);
  printf("Inorder traversal: ");
  inorder(root);
}