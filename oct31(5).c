#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int a[], int low, int high)
{
	int p,temp,i;
	p = a[high];
	i = low-1;
	for(int j=low; j<high; j++)
	{
		if (a[j]<p)
		{
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1], &a[high]);
	return (i+1);
}

void quickSort(int a[], int low, int high)
{
	int p;
	if (low<high)
	{
		p = partition(a, low, high);
		quickSort(a, low, p-1);
		quickSort(a, p+1, high);
	}
}

void printArray(int a[], int n)
{
	for (int i=0; i<n;i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int n;
	int a[n];
	printf("Enter number of elements in array\n");
	scanf("%d", &n);
	for (int i=0; i<n;i++)
	{
		printf("Enter element\n");
		scanf("%d", &a[i]);
	}
	printf("The original array is:\n");
	printArray(a,n);
	quickSort(a,0,n);
	printf("The sorted array is:\n");
	printArray(a,n);
	return 0;
}
