#include <stdio.h> /* scanf, printf */

int main()
{
    char word[16];

    printf("Enter a word>\n");
    if (!scanf("%s", word))
    {
        printf("Invalid input");
        return 1;
    }

    /* There are 128 characters in ASCII. Since we can have at most 15
       characters in the word, we only need 4 bits to represent the count of
       each character (e.g. 0b1111 = 15). Since a char is 8 bits, I'm only
       using 64 of them to store the counts to save space. Each int holds the
       count for 2 chars. The int at index 0 holds the count for char 0 and
       char 1, in its 4 high bits and 4 low bits respectively. (I could have
       saved even more space if I had limited myself to printable ASCII, but
       I'm sure there's a better solution that keeping the counts in an array
       so I couldn't be bothered to over-optimize this.) */
    /* Took me a while to find out that the array is not initialized to zeros,
       thank you https://stackoverflow.com/a/2589751 */
    char counts[64] = {0};
    char c;
    int i, c_index;
    for (i = 0; i < 16; i++)
    {
        c = word[i];
        if (c == '\0')
            break;

        c_index = c / 2;

        if (c % 2 == 0)
        {
            /* Even, so we only use the 4 high bits */
            counts[c_index] += 0b00010000;
        }
        else
        {
            /* Odd, so use the 4 low bits */
            counts[c_index] += 0b00000001;
        }
    }

    /* Now that we have te counts of each characters, lets print each one with
       count > 1 in order. */
    int count, hasDuplicates = 0;
    for (i = 0; i < 16; i++)
    {
        c = word[i];
        if (c == '\0')
            break;

        c_index = c / 2;
        if (c % 2 == 0)
        {
            count = counts[c_index] >> 4;
            /* Reset the count so it doesn't get printed multiple times. */
            counts[c_index] = counts[c_index] & 0b00001111;
        }
        else
        {
            count = counts[c_index] & 0b00001111;
            /* Reset the count so it doesn't get printed multiple times. */
            counts[c_index] = counts[c_index] & 0b11110000;
        }
        if (count > 1)
        {
            printf("Duplicate letter: %c, Occurrences: %d\n", c, count);
            hasDuplicates = 1;
        }
    }

    if (hasDuplicates == 0)
    {
        printf("No duplicates found\n");
    }

    return 0;
}