#include <limits.h>
#include <stdio.h>
#include <math.h>
#define INPUT_LENGTH 5

int max(int arr[], size_t arrSize);

int main()
{
    int inputArray[INPUT_LENGTH];
    int outputArray[INPUT_LENGTH];
    int n;

    printf("Enter 5 values separated by spaces> ");
    if (!scanf("%d %d %d %d %d", &inputArray[0], &inputArray[1],
               &inputArray[2], &inputArray[3], &inputArray[4]))
    {
        printf("Invalid input.\n");
        return 1;
    }
    printf("Enter the value of n> ");
    if (!scanf("%d", &n))
    {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Input array is:");
    int i;
    for (i = 0; i < INPUT_LENGTH; i++)
    {
        outputArray[i] = pow(inputArray[i], n);
        printf(" %d", inputArray[i]);
    }
    printf("\nOutput array is:");
    for (i = 0; i < INPUT_LENGTH; i++)
    {
        printf(" %d", outputArray[i]);
    }
    printf("\nMax value: %d\n", max(outputArray, sizeof(outputArray) / sizeof(int)));

    return 0;
}

int max(int arr[], size_t arrSize)
{
    int max = INT_MIN;
    int i;
    for (i = 0; i < arrSize; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}
