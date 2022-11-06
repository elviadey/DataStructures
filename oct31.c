#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *a, int n)
{
	int i,j,min,temp;
	for (i=0; i<n-1; i++)
	{
		min = i;
		for (j=i+1; j<n; j++)
		{
			if (a[j]<a[min])
			{
				min = j;
			}
		}
		if (min!=i)
		{
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
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
	selectionSort(a,n);
	printf("The sorted array is:\n");
	printArray(a,n);
	return 0;
}
