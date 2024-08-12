/**
 * @file
 * @brief Calculates the height of a projectile.
 * @author Alexander - uts_submission@colorman.me
 * @date 21-08-2024
 * Calculates the height of a projectile given it's horizontal displacement and
 * initial velocity and angle.
 */

#include <stdio.h> /* printf, scanf */
#include <math.h>  /* sin, cos, pow */
#define G 9.8      /* G, 9.8 m/s^2, the gravitiy of the earth */

double getFlightDuration(double horizontalDisplacement, double velocity, double angle);
double getHeight(double velocity, double angle, double time);
int readDouble(char prompt[], double *pointer);

int main()
{
    double horizontalDisplacement, velocity, angle;
    int returnValue = 0;

    returnValue += readDouble("Enter horizontal desplacement> ", &horizontalDisplacement);
    returnValue += readDouble("Enter magnitude of initial velocity> ", &velocity);
    returnValue += readDouble("Enter angle of elevation> ", &angle);
    if (returnValue > 0)
    {
        printf("One or more invalid values were given, quitting.");
        return 1;
    }

    double duration = getFlightDuration(horizontalDisplacement, velocity, angle);
    double height = getHeight(velocity, angle, duration);

    printf("The projectile flew for %.2lf and reached a height of %.2lf.\n", duration, height);
    return 0;
}

/**
 * Calculates the flight duration of a projectile with a given horizontal
 * displacement and initial velocity and angle.
 * @param[in] horizontalDisplacement The horizontal displacement of the projectile.
 * @param[in] velocity Initial projectile velocity.
 * @param[in] angle Initial projectile angle.
 * @return The duration of the flight.
 */
double getFlightDuration(double horizontalDisplacement, double velocity, double angle)
{
    return horizontalDisplacement / (velocity * cos(angle));
}

/**
 * Calculates the elevation of a projectile with an initial velocity and angle,
 * after a given time.
 * @param[in] velocity Initial velocity.
 * @param[in] angle Initial angle in radians.
 * @param[in] time Flight time.
 * @return The height at the given time.
 */
double getHeight(double velocity, double angle, double time)
{
    return velocity * sin(angle) * time - 0.5 * G * pow(time, 2);
}

/**
 * Takes a string and a double pointer, then prints the string and reads user
 * input into the double.
 * @param[in] prompt String printed to stdout, prompt for the user.
 * @param[in ,out] pointer pointer to the double variable. Populated with user input.
 * @return 1 if user inputs a non-number, else 0.
 */
int readDouble(char prompt[], double *pointer)
{
    printf("%s", prompt);
    if (!scanf("%lf", pointer))
    {
        return 1;
    }
    return 0;
}
