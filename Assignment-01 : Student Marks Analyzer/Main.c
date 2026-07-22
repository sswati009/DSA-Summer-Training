#include <stdio.h>

#define MAX 100

void display(int marks[], int n);
void highest(int marks[], int n);
void lowest(int marks[], int n);
void totalAverage(int marks[], int n);
void search(int marks[], int n);
void sort(int marks[], int n);

int main()
{
    int marks[MAX];
    int n, choice;

    printf("Enter Number of Students: ");
    scanf("%d",&n);

    printf("Enter Marks:\n");

    for(int i=0;i<n;i++)
    {
        printf("Student %d: ",i+1);
        scanf("%d",&marks[i]);
    }

    do
    {
        printf("\n===== STUDENT MARKS ANALYZER =====\n");
        printf("1. Display Marks\n");
        printf("2. Highest Marks\n");
        printf("3. Lowest Marks\n");
        printf("4. Total & Average\n");
        printf("5. Search Marks\n");
        printf("6. Sort Marks\n");
        printf("7. Exit\n");

        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                display(marks,n);
                break;

            case 2:
                highest(marks,n);
                break;

            case 3:
                lowest(marks,n);
                break;

            case 4:
                totalAverage(marks,n);
                break;

            case 5:
                search(marks,n);
                break;

            case 6:
                sort(marks,n);
                printf("Marks Sorted Successfully.\n");
                display(marks,n);
                break;

            case 7:
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    }while(choice!=7);

    return 0;
}

void display(int marks[], int n)
{
    printf("\nStudent Marks:\n");

    for(int i=0;i<n;i++)
    {
        printf("%d ",marks[i]);
    }

    printf("\n");
}

void highest(int marks[], int n)
{
    int max=marks[0];

    for(int i=1;i<n;i++)
    {
        if(marks[i]>max)
            max=marks[i];
    }

    printf("Highest Marks = %d\n",max);
}

void lowest(int marks[], int n)
{
    int min=marks[0];

    for(int i=1;i<n;i++)
    {
        if(marks[i]<min)
            min=marks[i];
    }

    printf("Lowest Marks = %d\n",min);
}

void totalAverage(int marks[], int n)
{
    int sum=0;

    for(int i=0;i<n;i++)
        sum+=marks[i];

    printf("Total Marks = %d\n",sum);
    printf("Average = %.2f\n",(float)sum/n);
}

void search(int marks[], int n)
{
    int key, found=0;

    printf("Enter Marks to Search: ");
    scanf("%d",&key);

    for(int i=0;i<n;i++)
    {
        if(marks[i]==key)
        {
            printf("Marks Found at Student %d\n",i+1);
            found=1;
        }
    }

    if(found==0)
        printf("Marks Not Found\n");
}

void sort(int marks[], int n)
{
    int temp;

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(marks[j]>marks[j+1])
            {
                temp=marks[j];
                marks[j]=marks[j+1];
                marks[j+1]=temp;
            }
        }
    }
}