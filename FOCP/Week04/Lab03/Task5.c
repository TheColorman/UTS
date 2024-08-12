/**
 * @file
 * @brief FOCP Lab03 Task 5 submission.
 * @author Alexander - uts_submission@colorman.me
 * @date 26-08-2024
 */

#include <stdio.h> /* printf */

int main()
{
    int i, j; /* iterators */

    /* Top part */
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < i + 1; j++)
        {
            printf("*");
            if (j < i)
                printf(" ");
        }
        printf("\n");
    }

    /* Middle part */
    for (i = 0; i < 2; i++)
    {
        printf("* * * *\n");
    }

    /* Bottom part */
    for (i = 4; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            printf("*");
            if (j < i)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}