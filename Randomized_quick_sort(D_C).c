#include <stdio.h>
#include <stdlib.h>
#include<time.h>

// Function to swap two elements
void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array
int partition(int arr[], int low, int high) 
{
    // Choose a random pivot index
    int pivot_index = low + rand() % (high - low + 1);
    int pivot = arr[pivot_index];
    // Move the pivot element to the end of the array
    swap(&arr[pivot_index], &arr[high]);
    int i = low - 1, j;
    for (j = low; j < high; j++) 
	{
        if (arr[j] < pivot) 
		{
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // Move the pivot element to its final sorted position
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Function to perform randomized quick sort
void randomized_quick_sort(int arr[], int low, int high) 
{
    if (low < high) 
	{
        int pivot = partition(arr, low, high);
        // Recursively sort the two sub-arrays
        randomized_quick_sort(arr, low, pivot - 1);
        randomized_quick_sort(arr, pivot + 1, high);
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
    int* arr = (int*)malloc(size * sizeof(int));
    printf("Enter the elements of the array: ");
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    // Seed the random number generator
    srand(time(NULL));
    printf("\nOriginal array: ");
    print_array(arr, size);
    randomized_quick_sort(arr, 0, size - 1);
    printf("Sorted array: ");
    print_array(arr, size);
    free(arr);
    return 0;
}
