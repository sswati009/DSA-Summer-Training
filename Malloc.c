#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;

    ptr = (int *)malloc(sizeof(int));

    printf("Enter a number: ");
    scanf("%d", ptr);

    printf("You entered: %d", *ptr);

    free(ptr);

    return 0;
}