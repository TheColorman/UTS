#include <stdio.h>
#include <stdlib.h>

void sumAndProduct(int *arr, size_t size, int *out);

int main(void)
{
    int arr[] = {1, 2, 3, -4, 5};
    int out[2];

    sumAndProduct(arr, sizeof(arr) / sizeof(int), out);

    printf("Sum: %d\n", out[0]);
    printf("Product: %d\n", out[1]);

    return 0;
}

void sumAndProduct(int *arr, size_t size, int *out)
{
    out[0] = 0;
    out[1] = 1;
    int i;
    for (i = 0; i < size; i++)
    {
        out[0] += arr[i];
        out[1] = out[1] * arr[i];
    }
}
