#include <stdio.h>

int binary_search(int arr[], int target, int low, int high) 
{
    if (low > high)
        return -1; // not found
    int mid = (low + high) / 2;
    if (arr[mid] == target) 
	{
        return mid; // found
    } 
	else if (arr[mid] < target) 
	{
        return binary_search(arr, target, mid + 1, high);
    } 
	else 
	{
        return binary_search(arr, target, low, mid - 1);
    }
}

int main() 
{
    int i, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements in sorted order: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int target;
    printf("Enter the target element: ");
    scanf("%d", &target);
    int result = binary_search(arr, target, 0, n - 1);
    if (result != -1) 
	{
        printf("The searched element '%d' is found at index '%d'.", target, result);
    } 
	else 
	{
        printf("Element not found!!!\n");
    }
    return 0;
}
