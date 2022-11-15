#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node *head, *tail = NULL;

void addNode(struct node **head, int data)
{
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;

	newNode->next = (*head);   
 
    /* move the head to point to the new node */
    (*head)    = newNode;
}
struct node *chunkreverse(struct node *head, int k)
{
	if (!head)
        return NULL;

    struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;
    int c = 0;

    while (current != NULL && c<k) {
        // Store next
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
		// Move pointers one position ahead.
        prev = current;
        current = next;
        c++;
    }
    if (next !=  NULL){
    	head->next = chunkreverse(next, k);
    }
    return prev;
}
void display(struct node *current)
{
	if (current == NULL)
	{
		printf("List is empty\n");
		exit(0);
	}
	while (current != NULL)
	{
		printf("%d ",current->data);
		current = current->next;
	}
	printf("\n");
}
int main()  
{  
    int n,a,k;
    struct node *head = NULL;

    printf("Enter the number of nodes\n");
    scanf("%d", &n);

    for (int i = 1; i <=n; i++)
    {
        printf("Enter value\n");
        scanf("%d", &a);
        addNode(&head, a);
    }

    printf("The linked list is:\n");
    display(head);

    printf("Enter length of chunk to reverse\n");
    scanf("%d", &k);
    if (k>n)
    {
    	printf("Invalid input\n");
    	exit(0);
    }
    
    head = chunkreverse(head, k);
    printf("The chunk reversed linked list is:\n");
    display(head);  
    return 0;  
}  