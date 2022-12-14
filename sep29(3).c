#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node *head, *tail = NULL;

void addNode(int data)
{
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;

	//check if list is empty
	if(head == NULL)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
}
void reverse()
{
	struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;
 
        // Reverse current node's pointer
        current->next = prev;
 
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
}
void display()
{
	struct node *current = head;
	if (head == NULL)
	{
		printf("List is empty\n");
		return;
	}
	printf("The reversed linked list is:\n");
	while (current != NULL)
	{
		printf("%d->",current->data);
		current = current->next;
	}
	printf("\n");
}
int main()  
{  
    int n,a;
    printf("Enter the number of nodes\n");
    scanf("%d", &n);
    for (int i = 1; i <=n; i++)
        {printf("Enter value\n");
        scanf("%d", &a);
        addNode(a);  }
    reverse();
    display();  
   
    return 0;  
}  