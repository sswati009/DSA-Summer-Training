#include <stdio.h>

int main()
{
    int n, target;
    int found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    printf("Enter target: ");
    scanf("%d", &target);

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                printf("\nIndices: [%d, %d]\n", i, j);
                printf("Values : %d + %d = %d\n",
                       nums[i], nums[j], target);
                found = 1;
                break;
            }
        }

        if(found)
            break;
    }

    if(!found)
        printf("No valid pair found.\n");

    return 0;
}