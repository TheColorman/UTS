#include <stdio.h>

int main(void)
{
    int a = 1, b = 2;
    int *ptr = &b;
    char *ptr2 = "hello";

    printf("a:    %d at %p\n", a, &a);
    printf("b:    %d at %p\n", b, &b);
    printf("ptr:  %p at %p\n", ptr, &ptr);
    printf("ptr2: %p at %p\n", ptr2, &ptr2);

    printf("Incrementing ptr and ptr2...\n");
    ptr++;
    ptr2++;

    printf("ptr:  %p at %p\n", ptr, &ptr);
    printf("ptr2: %p at %p\n", ptr2, &ptr2);

    return 0;
}

/**
 * We can see that incrementing the int pointer by 1 increases its value by 4
 * bytes, equal to the size of the int datatype on my system. Incrementing the
 * char pointer increments it by 1 byte, equal to the size of a char.
 */