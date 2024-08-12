#include <stdio.h> /* printf, scanf */
#define OZ_PER_ML 0.033814
#define ML_PER_OZ 1 / OZ_PER_ML

int main()
{
    printf("This program converts from ounces to milliliters. \n");

    float oz;

    printf("Enter the volume in ounces>");
    scanf("%f", &oz);

    float ml = ML_PER_OZ * oz;
    printf("%.2f ounces = %.2f milliliters\n", oz, ml);
    return 0;
}