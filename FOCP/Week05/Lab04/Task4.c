#include <stdio.h>

int main()
{
    char word[4];

    printf("Enter a word with 3 letters> ");
    if (!scanf("%3s", word))
    {
        printf("Invalid input");
        return 1;
    }

    printf("Reverse word: ");
    int i;
    for (i = 3; i >= 0; i--)
    {
        printf("%c", word[i]);
    }

    printf("\n");

    return 0;
}