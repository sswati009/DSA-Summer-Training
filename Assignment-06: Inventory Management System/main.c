#include <stdio.h>

#define MAX 100

struct Product
{
    int id;
    char name[50];
    float price;
    int quantity;
};

void addProduct(struct Product p[], int *n);
void displayProducts(struct Product p[], int n);
void searchProduct(struct Product p[], int n);
void updateProduct(struct Product p[], int n);
void deleteProduct(struct Product p[], int *n);
void totalValue(struct Product p[], int n);

int main()
{
    struct Product p[MAX];
    int n = 0, choice;

    do
    {
        printf("\n===== INVENTORY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Search Product\n");
        printf("4. Update Product\n");
        printf("5. Delete Product\n");
        printf("6. Total Inventory Value\n");
        printf("7. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addProduct(p, &n);
                break;

            case 2:
                displayProducts(p, n);
                break;

            case 3:
                searchProduct(p, n);
                break;

            case 4:
                updateProduct(p, n);
                break;

            case 5:
                deleteProduct(p, &n);
                break;

            case 6:
                totalValue(p, n);
                break;

            case 7:
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 7);

    return 0;
}

void addProduct(struct Product p[], int *n)
{
    printf("Enter Product ID: ");
    scanf("%d", &p[*n].id);

    printf("Enter Product Name: ");
    scanf(" %[^\n]", p[*n].name);

    printf("Enter Product Price: ");
    scanf("%f", &p[*n].price);

    printf("Enter Quantity: ");
    scanf("%d", &p[*n].quantity);

    (*n)++;

    printf("Product Added Successfully.\n");
}

void displayProducts(struct Product p[], int n)
{
    if(n == 0)
    {
        printf("No Products Available.\n");
        return;
    }

    printf("\n-------------------------------------------------------------\n");
    printf("ID\tName\t\tPrice\t\tQuantity\n");
    printf("-------------------------------------------------------------\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d\t%s\t\t%.2f\t\t%d\n",
               p[i].id,
               p[i].name,
               p[i].price,
               p[i].quantity);
    }
}

void searchProduct(struct Product p[], int n)
{
    int id;

    printf("Enter Product ID: ");
    scanf("%d", &id);

    for(int i = 0; i < n; i++)
    {
        if(p[i].id == id)
        {
            printf("\nProduct Found\n");
            printf("ID       : %d\n", p[i].id);
            printf("Name     : %s\n", p[i].name);
            printf("Price    : %.2f\n", p[i].price);
            printf("Quantity : %d\n", p[i].quantity);
            return;
        }
    }

    printf("Product Not Found.\n");
}

void updateProduct(struct Product p[], int n)
{
    int id;

    printf("Enter Product ID to Update: ");
    scanf("%d", &id);

    for(int i = 0; i < n; i++)
    {
        if(p[i].id == id)
        {
            printf("Enter New Price: ");
            scanf("%f", &p[i].price);

            printf("Enter New Quantity: ");
            scanf("%d", &p[i].quantity);

            printf("Record Updated Successfully.\n");
            return;
        }
    }

    printf("Product Not Found.\n");
}

void deleteProduct(struct Product p[], int *n)
{
    int id;

    printf("Enter Product ID to Delete: ");
    scanf("%d", &id);

    for(int i = 0; i < *n; i++)
    {
        if(p[i].id == id)
        {
            for(int j = i; j < *n - 1; j++)
                p[j] = p[j + 1];

            (*n)--;

            printf("Product Deleted Successfully.\n");
            return;
        }
    }

    printf("Product Not Found.\n");
}

void totalValue(struct Product p[], int n)
{
    float total = 0;

    for(int i = 0; i < n; i++)
        total += p[i].price * p[i].quantity;

    printf("\nTotal Inventory Value = %.2f\n", total);
}