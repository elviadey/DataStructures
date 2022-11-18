#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *a, int n)
{
	int i,j,key;
	for (i=1;i<n;i++)
	{
		j = i-1;
		key = a[i];

		while(j>=0 && a[j]>key)
		{
			a[j+1] = a[j];
			j = j-1;
		}
		a[j+1] = key;
	}
}

void printArray(int *a, int n)
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
	insertionSort(a,n);
	printf("The sorted array is:\n");
	printArray(a,n);
	return 0;
}
