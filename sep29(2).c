#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
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
int countmid()
{
	struct node *current = head;
	int c=0;
	while(current != NULL)
	{
		c++;
		current = current->next;
	}
	c = c/2;
	return c;
}
void display(int c)
{
	struct node *current = head;
	if (head == NULL)
	{
		printf("List is empty\n");
		return;
	}
	printf("The first half of the linked list is:\n");
	for (int i=0; i<c; i++)
	{
		printf("%d->",current->data);
		current = current->next;
	}
	printf("\n");
}
int main()  
{  
    int n,a,c;
    printf("Enter the number of nodes\n");
    scanf("%d", &n);
    for (int i = 1; i <=n; i++)
        {printf("Enter value\n");
        scanf("%d", &a);
        addNode(a);  }
    c = countmid();
    display(c);  
   
    return 0;  
}  