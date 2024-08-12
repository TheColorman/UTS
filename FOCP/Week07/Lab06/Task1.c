#include <stdio.h>

int main(void)
{
    int a = 1, b = 2;
    int *ptr = &b;

    printf("a:   %d at %p\n", a, &a);
    printf("b:   %d at %p\n", b, &b);
    printf("ptr: %p at %p\n", ptr, &ptr);

    return 0;
}

/**
 * 1. The values are 1, 2 and 0x7ffd25919708. The value of the pointer is the
 *    location of b.
 * 2. The location of a is 0x7ffd408a9f84, the location of b is 0x7ffd25919708
 *    and the location of ptr is 0x7ffd25919700.
 * 3. None of the locations are the same.
 * 4. None of the values are the same, but the value of ptr is the location of b.
 * 5. I already did.
 */