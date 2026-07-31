#include <stdio.h>

// Tail recursive helper function
// 'accumulator' holds the running multiplication result
long long tailFactorial(int n, long long accumulator) {
    if (n == 0 || n == 1) {
        return accumulator; // Base case: returns the final computed answer directly
    }
    
    // Tail call: The recursive call is the absolute last step.
    // We update the accumulator inline (accumulator * n) and decrement n.
    return tailFactorial(n - 1, accumulator * n);
}

int main() {
    int num;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Error: Factorial of a negative number does not exist.\n");
    } else {
        long long fact = tailFactorial(num, 1);
        printf("Factorial of %d is %lld\n", num, fact);
    }

    return 0;
}
