#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};
typedef struct node * NodeAddress;

NodeAddress newnode(NodeAddress root, int n){
    if(root==NULL){
        root=(struct node* )malloc(sizeof(struct node));
        root->data=n;
        root->left=NULL;
        root->right=NULL;
    }
    return root;
}

NodeAddress BST(NodeAddress root, int n){

    if(root==NULL){
        root = newnode(root,n);
        return root;
    }

    else if(n<=root->data){
        root->left= BST(root->left, n);
    }
    else{
        root->right= BST(root->right, n);
    }
    return root;
}

void prefixprint(NodeAddress root){
    if(root!=NULL){

        prefixprint(root->left);
        printf("%d\t", root->data);
        prefixprint(root->right);
    }

}

int main(){
    struct node* root=NULL;
    int n;
    printf("Enter number of elements:\n" );
    scanf("%d", &n);
    int a[n];
    for (int i=0; i<n;i++)
	{
		printf("Enter element\n");
		scanf("%d", &a[i]);
		root= BST(root,a[i]);
	}
   
    printf("The BST is: \n ");
    prefixprint(root);
    return 0;
}