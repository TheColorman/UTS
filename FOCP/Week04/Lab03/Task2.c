/**
 * @file
 * @brief FOCP Lab03 Task 2 submission.
 * @author Alexander - uts_submission@colorman.me
 * @date 26-08-2024
 */

#include <stdio.h>   /* prinf, scanf*/
#include <stdbool.h> /* bool */

void printQuadrant(float x, float y);

int main()
{
    float x, y;
    while (1)
    {
        printf("Enter coordinates (\"0 0\" to quit)> ");
        if (!scanf("%f %f", &x, &y))
        {
            printf("Invalid coordinates, quitting\n");
            return 1;
        }
        printQuadrant(x, y);
        if (x == 0 && y == 0)
        {
            return 0;
        }
    }
}

/**
 * Prints the quadrant a given coordinate is in.
 * @param[in] x x coordinate
 * @param[in] y y coordinate
 * @return void, but prints the quadrant to stdout.
 */
void printQuadrant(float x, float y)
{
    bool top = y > 0, right = x > 0;
    bool xAxis = y == 0, yAxis = x == 0;

    printf("(%.2f, %.2f) is ", x, y);

    if (xAxis && yAxis)
    {
        printf("at the origin\n");
    }
    else if (xAxis)
    {
        printf("on the X-axis\n");
    }
    else if (yAxis)
    {
        printf("on the Y-axis\n");
    }
    else if (top && right)
    {
        printf("in Quadrant I\n");
    }
    else if (top && !right)
    {
        printf("in Quadrant IV\n");
    }
    else if (!top && right)
    {
        printf("in Quadrant II\n");
    }
    else if (!top && !right)
    {
        printf("in Quadrant III\n");
    }
}