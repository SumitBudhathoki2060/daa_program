#include <stdio.h>

// Function to merge two sub-arrays
void merge(int arr[], int left, int mid, int right) 
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    // Create temporary arrays
    int left_arr[n1], right_arr[n2];
    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        left_arr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        right_arr[j] = arr[mid + 1 + j];
    // Merge the temporary arrays
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) 
	{
        if (left_arr[i] <= right_arr[j]) 
		{
            arr[k] = left_arr[i];
            i++;
        } 
		else
		{
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of left_arr[], if there are any
    while (i < n1) 
	{
        arr[k] = left_arr[i];
        i++;
        k++;
    }
    // Copy the remaining elements of right_arr[], if there are any
    while (j < n2) 
	{
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

// Function to perform merge sort
void merge_sort(int arr[], int left, int right) 
{
    if (left < right) 
	{
        int mid = left + (right - left) / 2;
        // Recursively sort the two halves
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        // Merge the two sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print the array
void print_array(int arr[], int size)
{
	int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() 
{
    int i, size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array: ");
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    printf("\nOriginal array: ");
    print_array(arr, size);
    merge_sort(arr, 0, size - 1);
    printf("Sorted array: ");
    print_array(arr, size);
    return 0;
}
