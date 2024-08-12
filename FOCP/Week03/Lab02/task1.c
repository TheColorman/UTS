#include <stdio.h>
#include <ctype.h>

int throw();

int main()
{
    int numerator, denomenator;

    printf("Enter the numerator and denominator separated by a space> ");
    if (!scanf("%d %d", &numerator, &denomenator))
    {
        printf("Invalid input\n");
        return 1;
    }

    int remainder = numerator / denomenator;
    int rest = numerator - (denomenator * remainder);

    printf("%d/%d = %d %d/%d\n", numerator, denomenator, remainder, rest, denomenator);

    return 0;
}