#include <stdio.h>

int main()
	{
	float i = 0.1, s = 0;
	int n = 28;
	for (int j = 1; j <= n; j++)
	{	
	s = s + i; 
	}
	printf("%f", s);
	return 0;
	}
//The stress test fails after 27, after which s returns an incorrect value