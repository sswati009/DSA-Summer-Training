#include <stdio.h>

int main()
{
    int n, i, j, temp;

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

    // Bubble Sort starts
    for(i = 0; i < n - 1; i++)
    {
        // Compare adjacent elements
        for(j = 0; j < n - i - 1; j++)
        {
            // Swap if the current element is greater than the next element
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Display the sorted array
    printf("\nSorted Array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}