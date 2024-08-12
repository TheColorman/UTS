# Tasks for Lab03

## Task1

A rational number is any number that can be expressed as a fraction of two integers. Write a program that reads a rational number from the user and display it as a mixed numeral.

Example run 1:

```log
Enter the numerator and denominator separated by a space> 22 7
22/7 = 3 1/7
```

Example run 2:

```log
Enter the numerator and denominator separated by a space> 3 4
3/4 = 0 3/4
```

In run 2, when the numerator is smaller than the denominator, showing 0 3/4 is not perfect. If you are keen on how to get rid of the 0 when this happens, read about if statements.

## Task2

Relevant Formula: flight time = (horizontal displacement) / ( velocity * cos(angle of elevation) )

Relevant Formula: height = velocity \* sin(angle of elevation) \* time - 0.5 \* G \* time^2

Relevant Formula: G is the acceleration of gravity, which is 9.8 ms^-2

Write a program that computes the duration of a projectile's flight and the elevation when the target is reached. Your program should read,

1. the horizontal displacement
2. the magnitude of the initial velocity
3. the angle of elevation

Pick appropriate data types of the inputs. Display the duration and height of the projectile.

The purpose of this exercise is to understand how to break down a problem to functions. Therefore,

1. Analyse the problem and workout how to break the program into functions before implementation
   1. What should be the function name?
   2. What should be inputs (if any)?
   3. What should be the output (if any)?
2. Write the function prototype and function definition in appropriate places of your program.
3. Compile and run your program - refer to LAB01 if you forgot how to
4. Compare the output with others in the class
