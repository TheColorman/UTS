/*
WRITE YOUR ANSWER IN THIS FILE.

Write a complete program - functions and main().
*/
#include <limits.h> /* INT_MAX, INT_MIN */
#include <stdio.h>  /* printf, scanf */

void findMaxMinAvg(int arr[], int size);

int main()
{
    int nums[10];

    printf("Enter 10 integers: ");
    scanf("%d %d %d %d %d %d %d %d %d %d",
          &nums[0],
          &nums[1],
          &nums[2],
          &nums[3],
          &nums[4],
          &nums[5],
          &nums[6],
          &nums[7],
          &nums[8],
          &nums[9]);

    findMaxMinAvg(nums, 10);

    return 0;
}

/**
 * Finds and prints the max, min and average value up to two decimals of an
 * integer array with a given size.
 */
void findMaxMinAvg(int arr[], int size)
{
    int
        min = INT_MAX,
        max = INT_MIN,
        sum = 0,
        i;

    for (i = 0; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
        sum += arr[i];
    }

    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
    printf("Average: %.2f\n", sum / (float)size);
}