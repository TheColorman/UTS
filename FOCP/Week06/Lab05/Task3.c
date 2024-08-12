#include <math.h>

struct player
{
    char letter;
    int age;
    double avg;
};
typedef struct player player_t;

int compAB(player_t playerA, player_t playerB);

int compAB(player_t playerA, player_t playerB)
{
    int avgDiff = playerA.age - playerB.age;
    int ageDiff = playerA.age - playerB.age;

    if (abs(avgDiff) >= 10)
    {
        if (avgDiff > 0)
            return 1;
        else
            return -1;
    }

    if (abs(ageDiff) >= 15)
    {
        if (ageDiff > 0)
            return -1;
        else
            return 1;
    }

    return 0;
}
