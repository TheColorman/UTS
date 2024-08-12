#include <stdio.h>
#define INPUT_LENGTH 5

int main()
{
    int inputArray[INPUT_LENGTH];

    printf("Enter 5 values separated by spaces> ");
    if (!scanf("%d %d %d %d %d", &inputArray[0], &inputArray[1],
               &inputArray[2], &inputArray[3], &inputArray[4]))
    {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Input array is:");
    int i;
    for (i = 0; i < INPUT_LENGTH; i++)
    {
        printf(" %d", inputArray[i]);
    }
    printf("\n");

    return 0;
}