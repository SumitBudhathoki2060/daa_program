#include <stdio.h>

void selection_sort(int arr[], int n) 
{
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) 
	{
        min_idx = i;
        for (j = i + 1; j < n; j++) 
		{
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void print_array(int arr[], int n) 
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("\nOriginal array: ");
    print_array(arr, n);
    selection_sort(arr, n);
    printf("Sorted array: ");
    print_array(arr, n);
    return 0;
}
