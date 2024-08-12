/*******************************************************************************
Author: Beeshanga
Date: 28/06/2016
Purpose: This program calculates the duration and the height of an object that
follows projectile motion. This is ONLY a reasonably good sample solution (NOT
perfect).
*******************************************************************************/

/*******************************************************************************
Include header files and function prototypes
*******************************************************************************/
#include <stdio.h> /* printf, scanf */
#include <math.h>  /* pow */

#define G 9.8 /* constant - acceleration of gravity */

void printMenu(void);
double flightTime(double displacement, double velocity, double angle);
double flightHeight(double velocity, double angle, double time);

/*******************************************************************************
main
*******************************************************************************/
int main(void)
{
    double hdisplacement, velocity, angle; /* to store program inputs */
    double time, height;                   /* to store program outputs */

    printMenu();
    scanf("%lf%lf%lf", &hdisplacement, &velocity, &angle);

    time = flightTime(hdisplacement, velocity, angle);
    height = flightHeight(velocity, angle, time);

    printf("The flight time is %.2f seconds.\n", time);
    printf("The flight height is %.2f meters.\n", height);

    return 0;
}

/*******************************************************************************
printMenu
This function prints the initial menu with all instructions on how to use this
program.
inputs:
- none
outputs:
- none
*******************************************************************************/
void printMenu(void)
{
    printf("Enter the following in one line seperated by spaces.\n");
    printf("\t1. horizontal displacement in meters (m) \n");
    printf("\t2. magnitude of the velocity in meters per second (m/s)\n");
    printf("\t3. the angle of elevation in radians\n");
    printf(">");
}

/*******************************************************************************
flightTime
This function calculate and return the flight duration.
inputs:
- displacement: the horizontal displacement of the projectile in m
- velocity: the initial velocity of the projectile in m/s
- angle: the initial projectile angle in radians
outputs:
- flight duration in seconds returned as a double
*******************************************************************************/
double flightTime(double displacement, double velocity, double angle)
{
    return displacement / (velocity * cos(angle));
}

/*******************************************************************************
flightHeight
This function calculate and return the flight height with reference to the
initial point of the motion.
inputs:
- velocity: the initial velocity of the projectile in m/s
- angle: the initial projectile angle in radians
- time: the flight time in seconds, this can be calculated with flightTime
  prior to calling this function
outputs:
- flight height in meters returned as a double
*******************************************************************************/
double flightHeight(double velocity, double angle, double time)
{
    return (velocity * sin(angle) * time) - (0.5 * G * pow(time, 2.0));
}
