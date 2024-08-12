# Lab 03 tasks

## Task 1

Write a program to display a message based on the student mark entered through the terminal. Your program should print the pass/fail status based on the input as follows:

```txt
below 0 : Impossible, check the input again.
0-49    : Z - Pity you failed, try harder next time.
50-100  : P - Congratulations, way to go.
over 100: Too awesome for the class, check the input again.
```

Marks can only be integers.

## Task 2

Write a program that takes the x-y coordinates of a point in the Cartesian plane and display the quadrant that the point belongs to.

If the input was x1 and y1, you should print one of the following messages:

```txt
(x1, y1) is in Quadrant I
(x1, y1) is in Quadrant II
(x1, y1) is in Quadrant III
(x1, y1) is in Quadrant IV
(x1, y1) is on the X-axis
(x1, y1) is on the Y-axis
(x1, y1) is at the origin
```

You program should run only once - take the input, print the message and exit (no iteration).

### Task 2 optional extension

Extend the program, so that it iterates until the input is (0,0) - this part can be attempted in the end of the tutorial if you still have time.

## Task 3

Factorial n (denoted by n!) is the multiplication of all positive numbers below n. It is defined as follows,

> n! = (n) x (n-1) x (n-2) x ... x 2 x 1

Write a simple for loop that counts down from any integer value n to 1. Build on this to calculate the factorial of a user input n.

## Task 4

Use two nested for loops to print a rectangle of +. Your display should print 5 rows and 10 columns exactly as the Sample Executable [LAB03a.out](https://canvas.uts.edu.au/courses/33345/files/7520349?wrap=1). You can follow the procedure in LAB01 Task 3 to get the identical output - EVERY SINGLE CHARACTER matters (including spaces and new lines).

## Task 5

Building on Task 4 solution, use for loops to print the following shape:

```txt
*
* *
* * *
* * * *
* * * * 
* * * *
* * * *
* * *
* *
*
```
