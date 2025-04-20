#include <stdio.h>

// Binary search function
int binarySearch(int arr[], int low, int high, int x)
{
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Selection sort function
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) 
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Swap the found minimum with the first element
        if (min_idx != i) 
        {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

int main(void)
{
    int number;
    printf("Enter the size of list: ");
    scanf("%d", &number);
    int arr[number];

    printf("Enter the elements: ");
    for (int x = 0; x < number; x++)
    {
        scanf("%d", &arr[x]);
    }

    // Sort the array before binary search
    selectionSort(arr, number);

    printf("Sorted array: ");
    for (int i = 0; i < number; i++)
        printf("%d ", arr[i]);
    printf("\n");

    int x;
    printf("Enter the element to search: ");
    scanf("%d", &x);

    int result = binarySearch(arr, 0, number - 1, x);
    if (result == -1)
        printf("Element is not present in array\n");
    else
        printf("Element is present at index %d\n", result);

    return 0;
}
