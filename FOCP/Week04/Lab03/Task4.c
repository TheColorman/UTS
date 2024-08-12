/**
 * @file
 * @brief FOCP Lab03 Task 4 submission.
 * @author Alexander - uts_submission@colorman.me
 * @date 26-08-2024
 */

#include <stdio.h> /* printf */

int main()
{
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("+");
            if (j < 9)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}