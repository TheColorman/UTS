/*
WRITE YOUR ANSWER IN THIS FILE.

Write the function definition. Do NOT write the main().
*/

#include <stdio.h>  /* printf */
#include <string.h> /* strlen */
#define TEXTLEN 15
#define SUBLEN 4

/* Function Prototype */
int countOccurrences(char text[], char substring[]);

int main(void)
{
    char text[TEXTLEN] = {'n', 'o', ' ', 'n', 'o', 'w', ' ', 'n', 'o', '\0'};
    char substring[SUBLEN] = {'n', 'o', '\0'};
    printf("%d\n", countOccurrences(text, substring));

    return 0;
}

/** Function Definition for countOccurrences
 * Calculates the number of occurrences of the substring in the text.
 */
int countOccurrences(char text[], char substring[])
{
    int i, j = 0, occurrences = 0;
    int sublength = strlen(substring);
    /* Loop throug the text */
    for (i = 0; i < strlen(text); i++)
    {
        /* If the current text index matches the substring index, then continue counting */
        if (text[i] == substring[j])
            j++;
        else
            /* If not, reset the substring index and start over */
            j = 0;

        /* Increase occurence count if we've gone through the entire substring */
        if (j == sublength)
        {
            occurrences++;
            j = 0;
        }
    }

    return occurrences;
}