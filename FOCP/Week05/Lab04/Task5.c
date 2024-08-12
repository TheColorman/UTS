#include <stdio.h>
#include <string.h>

int main()
{
    char word[4];
    char revr[4];

    printf("Enter a word with 3 letters> ");
    if (!scanf("%3s", word))
    {
        printf("Invalid input");
        return 1;
    }

    int i;
    for (i = 0; i < 3; i++)
    {
        revr[2 - i] = word[i];
    }
    revr[3] = '\0';

    char result[8];

    strcpy(result, word);
    strcat(result, "X");
    strcat(result, revr);

    printf("%s\n", result);

    return 0;
}