#include <stdio.h>

#define MAX 100

struct Patient
{
    int id;
    char name[50];
    int age;
    char disease[50];
};

void addPatient(struct Patient p[], int *n);
void displayPatients(struct Patient p[], int n);
void searchPatient(struct Patient p[], int n);
void updatePatient(struct Patient p[], int n);
void deletePatient(struct Patient p[], int *n);

int main()
{
    struct Patient p[MAX];
    int n = 0, choice;

    do
    {
        printf("\n===== HOSPITAL PATIENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Patient\n");
        printf("2. Display Patients\n");
        printf("3. Search Patient\n");
        printf("4. Update Patient\n");
        printf("5. Delete Patient\n");
        printf("6. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addPatient(p, &n);
                break;

            case 2:
                displayPatients(p, n);
                break;

            case 3:
                searchPatient(p, n);
                break;

            case 4:
                updatePatient(p, n);
                break;

            case 5:
                deletePatient(p, &n);
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

void addPatient(struct Patient p[], int *n)
{
    printf("Enter Patient ID: ");
    scanf("%d", &p[*n].id);

    printf("Enter Patient Name: ");
    scanf(" %[^\n]", p[*n].name);

    printf("Enter Age: ");
    scanf("%d", &p[*n].age);

    printf("Enter Disease: ");
    scanf(" %[^\n]", p[*n].disease);

    (*n)++;

    printf("Patient Added Successfully.\n");
}

void displayPatients(struct Patient p[], int n)
{
    if(n == 0)
    {
        printf("No Patient Records Found.\n");
        return;
    }

    printf("\n-----------------------------------------------------------------\n");
    printf("ID\tName\t\tAge\tDisease\n");
    printf("-----------------------------------------------------------------\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d\t%s\t\t%d\t%s\n",
               p[i].id,
               p[i].name,
               p[i].age,
               p[i].disease);
    }
}

void searchPatient(struct Patient p[], int n)
{
    int id;

    printf("Enter Patient ID: ");
    scanf("%d", &id);

    for(int i = 0; i < n; i++)
    {
        if(p[i].id == id)
        {
            printf("\nPatient Found\n");
            printf("ID      : %d\n", p[i].id);
            printf("Name    : %s\n", p[i].name);
            printf("Age     : %d\n", p[i].age);
            printf("Disease : %s\n", p[i].disease);
            return;
        }
    }

    printf("Patient Not Found.\n");
}

void updatePatient(struct Patient p[], int n)
{
    int id;

    printf("Enter Patient ID to Update: ");
    scanf("%d", &id);

    for(int i = 0; i < n; i++)
    {
        if(p[i].id == id)
        {
            printf("Enter New Age: ");
            scanf("%d", &p[i].age);

            printf("Enter New Disease: ");
            scanf(" %[^\n]", p[i].disease);

            printf("Patient Record Updated Successfully.\n");
            return;
        }
    }

    printf("Patient Not Found.\n");
}

void deletePatient(struct Patient p[], int *n)
{
    int id;

    printf("Enter Patient ID to Delete: ");
    scanf("%d", &id);

    for(int i = 0; i < *n; i++)
    {
        if(p[i].id == id)
        {
            for(int j = i; j < *n - 1; j++)
            {
                p[j] = p[j + 1];
            }

            (*n)--;

            printf("Patient Record Deleted Successfully.\n");
            return;
        }
    }

    printf("Patient Not Found.\n");
}