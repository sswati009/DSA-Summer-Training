/*
=========================================
LINEAR DATA STRUCTURE - ARRAY OPERATIONS
=========================================

Operations

1. Display Array
2. Insert Element
3. Delete Element
4. Update Element
5. Search Element
6. Sort Array
7. Exit

=========================================
*/

#include <iostream>
using namespace std;

#define MAX 100

// Function Prototypes
void display(int arr[], int size);
void insert(int arr[], int &size);
void deleteElement(int arr[], int &size);
void update(int arr[], int size);
void search(int arr[], int size);
void sortArray(int arr[], int size);

int main()
{
    int arr[MAX];
    int size;
    int choice;

    // Step 1 : Create Array
    cout << "Enter Number of Elements : ";
    cin >> size;

    cout << "Enter Array Elements\n";

    for(int i = 0; i < size; i++)
        cin >> arr[i];

    do
    {
        cout << "\n==============================\n";
        cout << " ARRAY OPERATIONS MENU\n";
        cout << "==============================\n";

        cout << "1. Display\n";
        cout << "2. Insert\n";
        cout << "3. Delete\n";
        cout << "4. Update\n";
        cout << "5. Search\n";
        cout << "6. Sort\n";
        cout << "7. Exit\n";

        cout << "Enter Choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                display(arr, size);
                break;

            case 2:
                insert(arr, size);
                break;

            case 3:
                deleteElement(arr, size);
                break;

            case 4:
                update(arr, size);
                break;

            case 5:
                search(arr, size);
                break;

            case 6:
                sortArray(arr, size);
                cout << "Array Sorted Successfully\n";
                break;

            case 7:
                cout << "Program Ended\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }

    } while(choice != 7);

    return 0;
}

//-----------------------------------------
// Display Array
//-----------------------------------------
void display(int arr[], int size)
{
    cout << "\nArray Elements\n";

    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << "\n";
    cout << "Time Complexity : O(n)\n";
}

//-----------------------------------------
// Insert Element
//-----------------------------------------
void insert(int arr[], int &size)
{
    int pos, value;

    cout << "Enter Position : ";
    cin >> pos;

    cout << "Enter Value : ";
    cin >> value;

    // Shift elements right
    for(int i = size; i > pos; i--)
        arr[i] = arr[i - 1];

    arr[pos] = value;
    size++;

    cout << "Element Inserted\n";
    cout << "Time Complexity : O(n)\n";
}

//-----------------------------------------
// Delete Element
//-----------------------------------------
void deleteElement(int arr[], int &size)
{
    int pos;

    cout << "Enter Position : ";
    cin >> pos;

    // Shift elements left
    for(int i = pos; i < size - 1; i++)
        arr[i] = arr[i + 1];

    size--;

    cout << "Element Deleted\n";
    cout << "Time Complexity : O(n)\n";
}

//-----------------------------------------
// Update Element
//-----------------------------------------
void update(int arr[], int size)
{
    int pos, value;

    cout << "Enter Position : ";
    cin >> pos;

    cout << "Enter New Value : ";
    cin >> value;

    arr[pos] = value;

    cout << "Updated Successfully\n";
    cout << "Time Complexity : O(1)\n";
}

//-----------------------------------------
// Search Element
//-----------------------------------------
void search(int arr[], int size)
{
    int key;

    cout << "Enter Number to Search : ";
    cin >> key;

    for(int i = 0; i < size; i++)
    {
        if(arr[i] == key)
        {
            cout << "Element Found at Position " << i << endl;
            cout << "Time Complexity : O(n)\n";
            return;
        }
    }

    cout << "Element Not Found\n";
    cout << "Time Complexity : O(n)\n";
}

//-----------------------------------------
// Bubble Sort
//-----------------------------------------
void sortArray(int arr[], int size)
{
    int temp;

    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Time Complexity : O(n²)\n";
}
