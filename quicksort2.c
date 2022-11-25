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

//finding tail node of linked list
struct node* last(struct node* head)
{
    struct node* current = head;
    while (current != NULL && current->next != NULL) {
        current = current->next;
    }
    return current;
}
 
//setting last node in correct position
struct node* parition(struct node* first, struct node* last)
{

    struct node* pivot = first;
    struct node* front = first;
    int temp = 0;
    while (front != NULL && front != last) {
        if (front->data < last->data) {
            pivot = first;
 
            //swapping values
            temp = first->data;
            first->data = front->data;
            front->data = temp;
 
            //going to the next node
            first = first->next;
        }
 
        //going to the next node
        front = front->next;
    }
 
    //changing last node value to current node
    temp = first->data;
    first->data = last->data;
    last->data = temp;
    return pivot;
}
 
//using quicksort recursively
void quicksort(struct node* first, struct node* last)
{
    if (first == last) {
        return;
    }
    struct node* pivot = parition(first, last);
 
    if (pivot != NULL && pivot->next != NULL) {
        quicksort(pivot->next, last);
    }
 
    if (pivot != NULL && first != pivot) {
        quicksort(first, pivot);
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
    quicksort(head, last(head)); 
    display();
    return 0;  
}  