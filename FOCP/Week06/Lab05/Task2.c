#include <stdio.h>

struct player
{
    char letter;
    int age;
    double avg;
};
typedef struct player player_t;

player_t scanPlayer();

int main()
{
    player_t p = scanPlayer();

    printf("%c %d %.2lf\n", p.letter, p.age, p.avg);

    return 0;
}

player_t scanPlayer()
{
    player_t p;
    printf("Enter the first letter of the player name> ");
    scanf("%c", &p.letter);

    printf("Enter the age> ");
    scanf("%d", &p.age);

    printf("Enter the batting average> ");
    scanf("%lf", &p.avg);

    return p;
}
