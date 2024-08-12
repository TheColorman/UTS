#include <stdio.h>

char readPlayerName(char filename[]);

int main()
{
    printf("Player first letter: %c\n", readPlayerName("playerName.txt"));
    return 0;
}

char readPlayerName(char filename[])
{
    FILE *f = fopen(filename, "r");
    char l = fgetc(f);

    int err = ferror(f);

    fclose(f);
    return err ? 1 : l;
}
