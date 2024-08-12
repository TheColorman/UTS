/**
 * @file
 * @brief FOCP Lab03 Task 1 submission.
 * @author Alexander - uts_submission@colorman.me
 * @date 26-08-2024
 */

#include <stdio.h> /* printf, scanf */

int main()
{
    int mark;

    printf("Enter your mark> ");
    if (!scanf("%d", &mark))
    {
        printf("Invalid input!\n");
        return 1;
    };

    if (mark < 0)
    {
        printf("below 0 : Impossible, check the input again.\n");
        return 1;
    }
    if (mark < 50)
    {
        printf("0-49    : Z - Pity you failed, try harder next time.\n");
    }
    else if (mark <= 100)
    {
        printf("50-100  : P - Congratulations, way to go.\n");
    }
    else
    {
        printf("over 100: Too awesome for the class, check the input again.\n");
        return 1;
    }

    return 0;
}