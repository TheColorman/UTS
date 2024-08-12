#include <stdio.h>

struct player
{
    char letter;
    int age;
    double avg;
};
typedef struct player player_t;

player_t scanPlayer();
int savePlayer(player_t p, char filename[]);
player_t readPlayer(char filename[]);

int main()
{
    player_t p = scanPlayer();

    savePlayer(p, "player.txt");
    player_t p2 = readPlayer("player.txt");

    printf("%c %d %.2lf\n", p2.letter, p2.age, p2.avg);

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

int savePlayer(player_t p, char filename[])
{
    int ret;
    FILE *f = fopen(filename, "w");
    fprintf(f, "%c %d %lf", p.letter, p.age, p.avg);

    if (ferror(f))
        ret = 1;
    else
        ret = 0;

    fclose(f);
    return ret;
}

player_t readPlayer(char filename[])
{
    FILE *f = fopen(filename, "r");
    player_t p;
    fscanf(f, "%c %d %lf", &p.letter, &p.age, &p.avg);

    fclose(f);
    return p;
}
