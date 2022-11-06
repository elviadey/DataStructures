#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *head, *sorted, *tail = NULL;

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


void insert(struct node* newnode)
{
    if (sorted == NULL || sorted->data >= newnode->data) { //special case for head
        newnode->next = sorted;
        sorted = newnode;
    }
    else {
        struct node* current = sorted;
        while (current->next != NULL
               && current->next->data < newnode->data) {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
   }
}

void insertionsort()
{
 
    struct node* current = head;
 
    // Traverse linked list and insert every sorted node
    while (current != NULL) {
 
        
        struct node* next = current->next;
 
        // insert current in sorted linked list
        insert(current);
 
        // Update current
        current = next;
    }
    head = sorted;
}
 

void display()
{
	struct node *current = head;
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
    printf("The linked list is:\n");
    display(); 
    printf("The sorted linked list is:\n");
    insertionsort(); 
    display();
    return 0;  
}  