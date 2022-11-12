#include<stdio.h>
#include<stdlib.h>

struct node
{
	int key;
	struct node *left;
	struct node *right;
	int height;
};

// finding height of tree
int height(struct node *n)
{
	if (n == NULL)
		return 0;
	return n->height;
}

int max(int a, int b)
{
	return (a > b)? a : b;
}

/* Helper function that allocates a new node with the given key and
	NULL left and right pointers. */
struct node* newNode(int key)
{
	struct node* newnode = (struct node*)
	newnode->key = key;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->height = 1;
	return(newnode);
}

//rotating right subtree
struct node *rightRotate(struct node *y)
{
	struct node *x = y->left;
	struct node *T2 = x->right;

	x->right = y;
	y->left = T2;

	// Updating heights
	y->height = max(height(y->left),
					height(y->right)) + 1;
	x->height = max(height(x->left),
					height(x->right)) + 1;

	return x;
}

//rotating left subtree
struct node *leftRotate(struct node *x)
{
	struct node *y = x->right;
	struct node *T2 = y->left;

	y->left = x;
	x->right = T2;

	// Updating heights
	x->height = max(height(x->left),
					height(x->right)) + 1;
	y->height = max(height(y->left),
					height(y->right)) + 1;

	return y;
}

// Get Balance factor of node n
int getBalance(struct node *n)
{
	if (n == NULL)
		return 0;
	return height(n->left) - height(n->right);
}


struct node* insert(struct node* newnode, int key)
{

	if (newnode == NULL)
		return(newNode(key));

	if (key < newnode->key)
		newnode->left = insert(newnode->left, key);
	else if (key > newnode->key)
		newnode->right = insert(newnode->right, key);
	else // Equal keys are not allowed in BST
		return newnode;

	newnode->height = 1 + max(height(newnode->left),
						height(newnode->right));

	int balance = getBalance(newnode);

	// Left Left Case
	if (balance > 1 && key < newnode->left->key)
		return rightRotate(newnode);

	// Right Right Case
	if (balance < -1 && key > newnode->right->key)
		return leftRotate(newnode);

	// Left Right Case
	if (balance > 1 && key > newnode->left->key)
	{
		newnode->left = leftRotate(newnode->left);
		return rightRotate(newnode);
	}

	// Right Left Case
	if (balance < -1 && key < newnode->right->key)
	{
		newnode->right = rightRotate(newnode->right);
		return leftRotate(newnode);
	}

	/* return the (unchanged) node pointer */
	return newnode;
}

// print preorder traversal
void preOrder(struct node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

/* Driver program to test above function*/
int main()
{
	struct node *root = NULL;
	int n;
	int a[n];
	printf("Enter the number of elements in array:\n");
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		printf("Enter element\n");
		scanf("%d", &a[i]);
		root = insert(root, a[i]);
	}

	printf("Preorder traversal of the constructed AVL tree is \n");
	preOrder(root);

return 0;
}
