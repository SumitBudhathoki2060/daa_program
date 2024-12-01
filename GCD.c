#include<stdio.h>
void GCD(int a, int b)
{
	if(a==0)
	printf("GCD(%d, %d) = %d",a, b, b);
	
	else if(b==0)
	printf("GCD(%d, %d) = %d",a, b, a);
	
	else{
		printf("GCD(%d, %d) = ",a, b);
		while(b!=0)
		{
			int r=a%b;
			a=b;
			b=r;
		}
		printf("%d",a);
	}
}

main()
{
	int a, b;
	printf("Enter a and b: ");
	scanf("%d %d", &a, &b);
	GCD(a, b);
	return 0;
}
