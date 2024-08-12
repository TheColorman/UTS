/*
WRITE YOUR ANSWER IN THIS FILE.

*/

#define SRC_LEN 7
#define FILTER_LEN 3

#include <stdio.h>
#include <string.h> /* strlen */
/* Function Prototype */
void filterString(char src[], char dest[], char filter[]);
int includes(char str[], char c);

int main(void)
{
    char filter[FILTER_LEN] = {'$', '%', '\0'};
    char src[SRC_LEN] = {'$', '1', '%', '2', '\0'};
    char dest[SRC_LEN];
    /* call the function */
    filterString(src, dest, filter);

    int i;
    for (i = 0; i < SRC_LEN && dest[i] != '\0'; i++)
        printf("%c ", dest[i]);
    printf("\n");
    return 0;
}

/* Function definition */

/**
 * Copies elements from src to dest if they do not appear in filter.
 */
void filterString(char src[], char dest[], char filter[])
{
    int i;
    for (i = 0; i < SRC_LEN && src[i] != '\0'; i++)
    {
        if (includes(filter, src[i]) == 0)
        {
            *dest = src[i];
            dest++;
        }
    }
    *dest = '\0';
}

/**
 * Checks whether str includes c. Returns 1 if true, 0 otherwise.
 */
int includes(char str[], char c)
{
    int i;
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == c)
            return 1;
    }
    return 0;
}