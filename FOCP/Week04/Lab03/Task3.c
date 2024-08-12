/**
 * @file
 * @brief FOCP Lab03 Task 3 submission.
 * @author Alexander - uts_submission@colorman.me
 * @date 26-08-2024
 */

#include <stdio.h> /* printf, scanf */

int main()
{
    int n;

    printf("Input a number> ");
    if (!scanf("%d", &n))
    {
        printf("Invalid input.");
        return 1;
    }

    int sum = n, i;
    for (i = n - 1; i > 0; i--)
    {
        sum *= i;
    }
    printf("%d! = %d\n", n, sum);
    return 0;
}