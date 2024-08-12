#include <stdio.h>
#include <stdlib.h>

struct player
{
    char letter;
    int age;
};
typedef struct player player_t;

void incr(player_t *ptr);

int main(void)
{
    player_t *ptr = malloc(sizeof(player_t));
    ptr->age = 50;
    ptr->letter = 'g';

    printf("Before: %d\n", ptr->age);
    incr(ptr);
    printf("After:  %d\n", ptr->age);

    free(ptr);
    return 0;
}

void incr(player_t *ptr)
{
    ptr->age++;
}
