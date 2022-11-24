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


void selectionSort()
{
	struct node *current = head;
	while(current!= NULL)
	{
		struct node *min = current;
		struct node *new = current->next;
		while (new!= NULL)
		{
			if (new->data<min->data)
			{
				min = new;
			}
			new = new->next;
		}
		// Swap Data
        int temp = current->data;
        current->data = min->data;
        min->data = temp;

        current = current->next;
	}
}

void display()
{
	struct node *current = head;
	while (current != NULL)
	{
		printf("%d ",current->data);
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
    printf("The linked list is:\n");
    display(); 
    printf("The sorted linked list is:\n");
    selectionSort(); 
    display();
    return 0;  
}  