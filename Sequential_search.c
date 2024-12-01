#include<stdio.h>
int sequentialSearch(int E[], int n, int key)
{
	int i;
    for (i=0; i<n; i++)
	{
        if (E[i]==key)
            return i;
    }
    return -1;
}
int main()
{
	int i, n, E[n], key;
	printf("Enter total number of elements: ");
	scanf("%d", &n);
	printf("Enter %d elements: ", n);
	for(i=0; i<n; i++)
		scanf("%d", &E[i]);
	printf("Enter the key to be searched: ");
	scanf("%d", &key);
	printf("The searched element '%d' is found at index '%d'.",key,  sequentialSearch(E, n, key));
	return 0;
}
