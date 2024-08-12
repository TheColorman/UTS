/**
 * @file
 * @brief Prints a triangle in n lines.
 * @author Alexander - uts_submission@colorman.me
 * @date 28-08-2024
 * This program takes an integer as input, and prints out a triangle of stars.
 */

#include <stdio.h>

int main()
{
    int n;
    printf("Enter an integer>\n");
    if (!scanf("%d", &n))
    {
        printf("Invalid input!\n");
        return 1;
    }

    if (n < 1)
    {
        printf("Input must be greater or equal to 1\n");
        return 1;
    }

    int i, j;
    for (i = 0; i < n; i++)
    {
        /* A line*/
        for (j = 0; j < n - i; j++)
        {
            /* Print spaces */
            printf(" ");
        }
        /* The number of stars printed in each row is equal to the row number
           multiplied by 2, minus 1. Since i is 0-indexed, need to add 1 to it
           first.*/
        for (j = 0; j < (i + 1) * 2 - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}