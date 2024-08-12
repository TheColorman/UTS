/*
WRITE YOUR ANSWER IN THIS FILE.

Write the main().
*/
#include <stdio.h>

int main(void)
{
    /*
     * This question makes no sense. First, is the input in celcius or
     * fahrenheit? Based on the sample runs. I'd assume Fahrenheit cause no way
     * in hell 72 is "Normal range". But the question says celcius, so should
     * we assume that the sample is wrong? Cause 72 C converted to F is a lot
     * more than that 125 max, which chould print "Check the input again", but
     * it doesn't in the sample. In addition to this, "Below 32:  "Freezing""
     * and "Below 32 to -22 F: "Extreme cold"" have overlapping conditions, so
     * which one are we supposed to print??? Did no one read through this
     * question twice??
     */
    int c;
    float f;
    while (1)
    {
        printf("Enter temperature in Celcius> ");
        if (scanf("%d", &c) == 0)
        {
            printf("Check the input again.\n");
            continue;
        };

        f = c * 1.8 + 32;

        if (f > 125)
        {
            printf("Check the input again.\n");
            continue;
        }

        if (f < -22)
        {
            return 0;
        }

        if (f > 86)
            printf("Extreme temperature\n"); /* Over 86 up to 125: "Extreme temperature" */
        else if (f > 31)
            printf("Normal range\n"); /* 32 to 86: "Normal range" */
        else
            printf("Freezing\n"); /* Below 32:  "Freezing" */
        /* else if (f > 22) printf("Extreme cold\n"); Below 32 to -22 F: "Extreme cold" */
        /* The last one will never be executed, but that's how the question is phrased so idk */
    }
}
