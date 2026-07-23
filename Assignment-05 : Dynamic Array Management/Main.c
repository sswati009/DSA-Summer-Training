#include <stdio.h>
#include <stdlib.h>

void display(int *marks, int n);
void statistics(int *marks, int n);

int main()
{
    int *marks;
    int n;

    printf("Enter Number of Students: ");
    scanf("%d", &n);

    // Dynamic Memory Allocation
    marks = (int *)malloc(n * sizeof(int));

    if(marks == NULL)
    {
        printf("Memory Allocation Failed!\n");
        return 0;
    }

    printf("Enter Student Marks:\n");

    for(int i = 0; i < n; i++)
    {
        printf("Student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }

    display(marks, n);

    statistics(marks, n);

    // Free Memory
    free(marks);

    printf("\nMemory Released Successfully.\n");

    return 0;
}

void display(int *marks, int n)
{
    printf("\nStudent Marks:\n");

    for(int i = 0; i < n; i++)
        printf("%d ", marks[i]);

    printf("\n");
}

void statistics(int *marks, int n)
{
    int highest = marks[0];
    int lowest = marks[0];
    int total = 0;

    for(int i = 0; i < n; i++)
    {
        if(marks[i] > highest)
            highest = marks[i];

        if(marks[i] < lowest)
            lowest = marks[i];

        total += marks[i];
    }

    printf("\nHighest Marks : %d\n", highest);
    printf("Lowest Marks  : %d\n", lowest);
    printf("Total Marks   : %d\n", total);
    printf("Average Marks : %.2f\n", (float)total / n);
}