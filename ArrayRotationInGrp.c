
#include <stdio.h>

// Helper function to reverse a specific section of the array
void reverse(int arr[], int left, int right) {
    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
    
}

// Main logic function to process the array in groups of size k
void rotateInGroups(int arr[], int n, int k) {
    for (int i = 0; i < n; i += k) {
        int left = i;
        
        // Find the end index of the current group.
        // Use (i + k - 1) but make sure it doesn't overshoot the last index (n - 1)
        int right = (i + k - 1 < n - 1) ? (i + k - 1) : (n - 1);
        
        // Reverse the current group
        reverse(arr, left, right);
    }
}

// Function to print the array elements
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    printf("Original Array: ");
    printArray(arr, n);

    rotateInGroups(arr, n, k);

    printf("Rotated in Groups of %d: ", k);
    printArray(arr, n);

    return 0;
}
