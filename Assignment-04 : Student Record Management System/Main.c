#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student
{
    int roll;
    char name[50];
    float marks;
};

void addStudent(struct Student s[], int *n);
void displayStudents(struct Student s[], int n);
void searchStudent(struct Student s[], int n);
void updateStudent(struct Student s[], int n);
void deleteStudent(struct Student s[], int *n);

int main()
{
    struct Student s[MAX];
    int n = 0;
    int choice;

    do
    {
        printf("\n===== STUDENT RECORD MANAGEMENT =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addStudent(s, &n);
                break;

            case 2:
                displayStudents(s, n);
                break;

            case 3:
                searchStudent(s, n);
                break;

            case 4:
                updateStudent(s, n);
                break;

            case 5:
                deleteStudent(s, &n);
                break;

            case 6:
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}

void addStudent(struct Student s[], int *n)
{
    printf("Enter Roll No: ");
    scanf("%d", &s[*n].roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", s[*n].name);

    printf("Enter Marks: ");
    scanf("%f", &s[*n].marks);

    (*n)++;

    printf("Student Added Successfully.\n");
}

void displayStudents(struct Student s[], int n)
{
    if(n == 0)
    {
        printf("No Records Found.\n");
        return;
    }

    printf("\n-------------------------------------------------\n");
    printf("Roll No\tName\t\tMarks\n");
    printf("-------------------------------------------------\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d\t%s\t\t%.2f\n",
               s[i].roll,
               s[i].name,
               s[i].marks);
    }
}

void searchStudent(struct Student s[], int n)
{
    int roll, found = 0;

    printf("Enter Roll Number: ");
    scanf("%d", &roll);

    for(int i = 0; i < n; i++)
    {
        if(s[i].roll == roll)
        {
            printf("\nStudent Found\n");
            printf("Roll No : %d\n", s[i].roll);
            printf("Name    : %s\n", s[i].name);
            printf("Marks   : %.2f\n", s[i].marks);

            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("Student Not Found.\n");
}

void updateStudent(struct Student s[], int n)
{
    int roll;

    printf("Enter Roll Number to Update: ");
    scanf("%d", &roll);

    for(int i = 0; i < n; i++)
    {
        if(s[i].roll == roll)
        {
            printf("Enter New Name: ");
            scanf(" %[^\n]", s[i].name);

            printf("Enter New Marks: ");
            scanf("%f", &s[i].marks);

            printf("Record Updated Successfully.\n");
            return;
        }
    }

    printf("Student Not Found.\n");
}

void deleteStudent(struct Student s[], int *n)
{
    int roll;

    printf("Enter Roll Number to Delete: ");
    scanf("%d", &roll);

    for(int i = 0; i < *n; i++)
    {
        if(s[i].roll == roll)
        {
            for(int j = i; j < *n - 1; j++)
                s[j] = s[j + 1];

            (*n)--;

            printf("Record Deleted Successfully.\n");
            return;
        }
    }

    printf("Student Not Found.\n");
}