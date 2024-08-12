#include <stdio.h>
#include <string.h>

int checkPalindrome(char word[], int size);

int main()
{
    char word[8];

    printf("Enter a word (max 7 characters)> ");
    if (!scanf("%9s", word))
    {
        printf("Invalid input.\n");
        return 1;
    }

    int size;
    for (size = 0; size < 8; size++)
    {
        if (word[size] == '\0')
            break;
    }

    if (checkPalindrome(word, size) == 1)
    {
        printf("%s is a palindrome\n", word);
    }
    else
    {
        printf("%s is not a palindrome\n", word);
    }

    return 0;
}

int checkPalindrome(char word[], int size)
{
    int half = (int)size / 2;
    int midpoint = (int)size / 2;
    int isOdd = half % 2 == 0 ? 0 : 1;

    char firstHalf[half];
    char firstHalfReversed[half];
    char secondHalf[half];
    strncpy(firstHalf, word, half);
    strncpy(secondHalf, word + midpoint + isOdd, half);

    int i;
    for (i = 0; i < half; i++)
    {
        firstHalfReversed[half - i - 1] = firstHalf[i];
    }

    return strcmp(firstHalfReversed, secondHalf) == 0 ? 1 : 0;
}
