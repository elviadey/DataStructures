#include <stdlib.h>
#include <stdio.h>

int main(){
	int n;
	printf("Enter the number of integers\n");
	scanf("%d", &n);
	int *ptr = (int *)malloc(n*sizeof(int));

	if (ptr == NULL){
		printf("Memory not available\n");
		exit(1);
	}
	 for(int i=0;i<n;i++){
	 	printf("Enter an integer\n");
	 	scanf("%d", ptr+i);
	}

	for(int i=0;i<n;i++){
		printf("%d ", *(ptr+i));
	}
	free(ptr);
	ptr = NULL;
	return 0;
}