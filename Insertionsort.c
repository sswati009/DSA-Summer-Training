#include <stdio.h>

int main()
{
    int n, i, j, key;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Insertion Sort starts
    for(i = 1; i < n; i++)
    {
        // Store the current element
        key = arr[i];

        // Compare with the previous elements
        j = i - 1;

        // Shift elements that are greater than key
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert the key at its correct position
        arr[j + 1] = key;
    }

    // Display the sorted array
    printf("\nSorted Array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}