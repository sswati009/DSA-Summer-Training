 #include <stdio.h>

int main() {
    int num;
    long long fact = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Error: Factorial of a negative number does not exist.\n");
    } else {
    
        for (int i = 1; i <= num; i++) {
            fact = fact * i;
        }

        printf("Factorial of %d is %lld\n", num, fact);
    }

    return 0;
}
