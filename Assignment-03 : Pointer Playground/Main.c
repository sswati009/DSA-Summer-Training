#include <stdio.h>

void displayAddress();
void dereferencePointer();
void swapNumbers();
void arrayTraversal();
void pointerArithmetic();

int main()
{
    int choice;

    do
    {
        printf("\n===== POINTER PLAYGROUND =====\n");
        printf("1. Display Memory Address\n");
        printf("2. Dereference Pointer\n");
        printf("3. Swap Two Numbers\n");
        printf("4. Traverse Array Using Pointer\n");
        printf("5. Pointer Arithmetic\n");
        printf("6. Exit\n");

        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                displayAddress();
                break;

            case 2:
                dereferencePointer();
                break;

            case 3:
                swapNumbers();
                break;

            case 4:
                arrayTraversal();
                break;

            case 5:
                pointerArithmetic();
                break;

            case 6:
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    }while(choice!=6);

    return 0;
}

void displayAddress()
{
    int a;

    printf("Enter a number: ");
    scanf("%d",&a);

    printf("Value = %d\n",a);
    printf("Address = %p\n",&a);
}

void dereferencePointer()
{
    int a;
    int *ptr;

    printf("Enter a number: ");
    scanf("%d",&a);

    ptr=&a;

    printf("Pointer Address = %p\n",ptr);
    printf("Value using Pointer = %d\n",*ptr);
}

void swapNumbers()
{
    int a,b,temp;
    int *p1,*p2;

    printf("Enter Two Numbers: ");
    scanf("%d%d",&a,&b);

    p1=&a;
    p2=&b;

    temp=*p1;
    *p1=*p2;
    *p2=temp;

    printf("After Swapping:\n");
    printf("A = %d\n",a);
    printf("B = %d\n",b);
}

void arrayTraversal()
{
    int arr[5],i;
    int *ptr;

    printf("Enter 5 Elements:\n");

    for(i=0;i<5;i++)
        scanf("%d",&arr[i]);

    ptr=arr;

    printf("Array Elements:\n");

    for(i=0;i<5;i++)
        printf("%d ",*(ptr+i));

    printf("\n");
}

void pointerArithmetic()
{
    int arr[5]={10,20,30,40,50};
    int *ptr=arr;

    printf("Pointer Arithmetic:\n");

    for(int i=0;i<5;i++)
    {
        printf("Address = %p  Value = %d\n",ptr+i,*(ptr+i));
    }
}