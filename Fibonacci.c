#include<stdio.h>
fibonacci(n)
{
	int i, first=0, second=1, temp=1;
	for (i=2; i<=n; i++)
	{
		temp=first+second;
		first=second;
		second=temp;
	}
	return temp;	
}
main()
{
	int n;
	printf("Enter the value for n: ");
	scanf("%d", &n);
	printf("The %dth fibonacci number is %d.", n, fibonacci(n));
	return 0;
}