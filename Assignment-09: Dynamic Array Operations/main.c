#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = NULL;
    int size = 0, choice, value, position;

    do
    {
        printf("\n===== DYNAMIC ARRAY OPERATIONS =====\n");
        printf("1. Create Array\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Display Array\n");
        printf("5. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                printf("Enter Size of Array: ");
                scanf("%d", &size);

                arr = (int *)malloc(size * sizeof(int));

                if(arr == NULL)
                {
                    printf("Memory Allocation Failed!\n");
                    return 0;
                }

                printf("Enter %d Elements:\n", size);

                for(int i = 0; i < size; i++)
                    scanf("%d", &arr[i]);

                printf("Array Created Successfully.\n");
                break;
            }

            case 2:
            {
                printf("Enter Position (1-%d): ", size + 1);
                scanf("%d", &position);

                if(position < 1 || position > size + 1)
                {
                    printf("Invalid Position!\n");
                    break;
                }

                printf("Enter Value: ");
                scanf("%d", &value);

                arr = (int *)realloc(arr, (size + 1) * sizeof(int));

                for(int i = size; i >= position; i--)
                    arr[i] = arr[i - 1];

                arr[position - 1] = value;
                size++;

                printf("Element Inserted Successfully.\n");
                break;
            }

            case 3:
            {
                if(size == 0)
                {
                    printf("Array is Empty.\n");
                    break;
                }

                printf("Enter Position (1-%d): ", size);
                scanf("%d", &position);

                if(position < 1 || position > size)
                {
                    printf("Invalid Position!\n");
                    break;
                }

                for(int i = position - 1; i < size - 1; i++)
                    arr[i] = arr[i + 1];

                size--;

                arr = (int *)realloc(arr, size * sizeof(int));

                printf("Element Deleted Successfully.\n");
                break;
            }

            case 4:
            {
                if(size == 0)
                {
                    printf("Array is Empty.\n");
                    break;
                }

                printf("Array Elements: ");

                for(int i = 0; i < size; i++)
                    printf("%d ", arr[i]);

                printf("\n");
                break;
            }

            case 5:
                free(arr);
                printf("Memory Released Successfully.\n");
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 5);

    return 0;
}