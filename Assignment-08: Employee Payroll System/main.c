#include <stdio.h>

#define MAX 100

struct Employee
{
    int id;
    char name[50];
    float basicSalary;
    float hra;
    float da;
    float grossSalary;
};

void addEmployee(struct Employee e[], int *n);
void displayEmployees(struct Employee e[], int n);
void searchEmployee(struct Employee e[], int n);
void updateEmployee(struct Employee e[], int n);
void deleteEmployee(struct Employee e[], int *n);

int main()
{
    struct Employee e[MAX];
    int n = 0, choice;

    do
    {
        printf("\n===== EMPLOYEE PAYROLL SYSTEM =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addEmployee(e, &n);
                break;

            case 2:
                displayEmployees(e, n);
                break;

            case 3:
                searchEmployee(e, n);
                break;

            case 4:
                updateEmployee(e, n);
                break;

            case 5:
                deleteEmployee(e, &n);
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

void addEmployee(struct Employee e[], int *n)
{
    printf("Enter Employee ID: ");
    scanf("%d", &e[*n].id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", e[*n].name);

    printf("Enter Basic Salary: ");
    scanf("%f", &e[*n].basicSalary);

    e[*n].hra = e[*n].basicSalary * 0.20;
    e[*n].da = e[*n].basicSalary * 0.10;
    e[*n].grossSalary = e[*n].basicSalary + e[*n].hra + e[*n].da;

    (*n)++;

    printf("Employee Added Successfully.\n");
}

void displayEmployees(struct Employee e[], int n)
{
    if(n == 0)
    {
        printf("No Employee Records Found.\n");
        return;
    }

    printf("\n-------------------------------------------------------------------------------\n");
    printf("ID\tName\t\tBasic\t\tHRA\t\tDA\t\tGross\n");
    printf("-------------------------------------------------------------------------------\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d\t%s\t\t%.2f\t%.2f\t%.2f\t%.2f\n",
               e[i].id,
               e[i].name,
               e[i].basicSalary,
               e[i].hra,
               e[i].da,
               e[i].grossSalary);
    }
}

void searchEmployee(struct Employee e[], int n)
{
    int id;

    printf("Enter Employee ID: ");
    scanf("%d", &id);

    for(int i = 0; i < n; i++)
    {
        if(e[i].id == id)
        {
            printf("\nEmployee Found\n");
            printf("ID            : %d\n", e[i].id);
            printf("Name          : %s\n", e[i].name);
            printf("Basic Salary  : %.2f\n", e[i].basicSalary);
            printf("HRA           : %.2f\n", e[i].hra);
            printf("DA            : %.2f\n", e[i].da);
            printf("Gross Salary  : %.2f\n", e[i].grossSalary);
            return;
        }
    }

    printf("Employee Not Found.\n");
}

void updateEmployee(struct Employee e[], int n)
{
    int id;

    printf("Enter Employee ID to Update: ");
    scanf("%d", &id);

    for(int i = 0; i < n; i++)
    {
        if(e[i].id == id)
        {
            printf("Enter New Basic Salary: ");
            scanf("%f", &e[i].basicSalary);

            e[i].hra = e[i].basicSalary * 0.20;
            e[i].da = e[i].basicSalary * 0.10;
            e[i].grossSalary = e[i].basicSalary + e[i].hra + e[i].da;

            printf("Employee Record Updated Successfully.\n");
            return;
        }
    }

    printf("Employee Not Found.\n");
}

void deleteEmployee(struct Employee e[], int *n)
{
    int id;

    printf("Enter Employee ID to Delete: ");
    scanf("%d", &id);

    for(int i = 0; i < *n; i++)
    {
        if(e[i].id == id)
        {
            for(int j = i; j < *n - 1; j++)
            {
                e[j] = e[j + 1];
            }

            (*n)--;

            printf("Employee Deleted Successfully.\n");
            return;
        }
    }

    printf("Employee Not Found.\n");
}