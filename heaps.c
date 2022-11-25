#include <stdio.h>
#include <stdlib.h>


//function to build min-heap
void heapify(int a[], int n, int i)
{
	int root = i;
	int left  = 2*i + 1; //left child
	int right = 2*i + 2; //right child

	if (left<n && a[left]<a[root]) //if left child is smaller than root
		root = left;

	if (right<n && a[right]<a[root]) //if right child is smaller than root
		root = right;

	if(root!=i)
	{
		int temp = a[root];
		a[root] = a[i];
		a[i] = temp;
		//recursively calling heapfiy on sub-tree
		heapify(a, n, root);
	}
}

void arraytoheap(int a[], int n)
{
	int last = ((n-2)/2); //last non-leaf node

	for(int i=last; i>=0; i--)
	{
		heapify(a, n, i);
	}
}

void printheap(int a[], int n)
{
	printf("The heap is:\n");
	for(int i=0 ;i<n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//driver code
int main()
{
	int n;
	int a[n];
	printf("Enter the number of elements in array:\n");
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		printf("Enter element\n");
		scanf("%d", &a[i]);
	}
	arraytoheap(a, n);
	printheap(a, n);
	return 0;
}
