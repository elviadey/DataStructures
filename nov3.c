#include <stdio.h>
#include <stdlib.h>


//function to build max-heap
void heapify(int a[], int n, int i)
{
	int root = i;
	int left  = 2*i + 1; //left child
	int right = 2*i + 2; //right child

	//for min-heap the signs will be reversed
	if (left<n && a[left]>a[root]) //if left child is larger than root
		root = left;

	if (right<n && a[right]>a[root]) //if right child is larger than root
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

void heapSort(int a[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
 
        heapify(a, n, i);
 
    //sorting heap
    for (int i = n - 1; i >= 0; i--) {
 
        int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
 
        // Heapify root element to get highest element at
        // root again
        heapify(a, i, 0);
    }
}

void printheap(int a[], int n)
{
	for(int i=0 ;i<n; i++)
	{
		printf("%d->", a[i]);
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
	printf("The heap is:\n");
	printheap(a, n);
	heapSort(a, n);
	printf("The sorted heap is:\n");
	printheap(a,n);
	return 0;
}
