# FOCP Lab 04

## Task 1

Write a C program that takes exactly 5 integers from the user and store them in an array called inputArray. Print them on the screen. Sample output is as follows:

```txt
Enter 5 values separated by spaces> 0 2 3 4 6
Input array is: 0 2 3 4 6
```

**NOTE:** Good programmers use #define macros where possible.

**NOTE:** scanf can read multiple values in one line of code.

## Task 2

Extend your program from Task 1. Now, the program should take another integer input n from the user, create a second array called the outputArray, store the nth power of the integers from inputArray in the outputArray. Display the values of both arrays.

Power of a number can be calculated with the pow() function defined in <math.h>. Find out the syntax by [reading this](http://www.cplusplus.com/reference/cmath/pow/). Be careful about the input data types of the pow() function.

Sample output is as follows:

```txt
Enter 5 values separated by spaces> 0 2 3 6 4
Enter the value of n> 3
Input array is: 0 2 3 6 4
Output array is: 0 8 27 216 64
```

**NOTE:** Good programmers use #define macros where possible.

**NOTE:** scanf can read multiple values in one line of code.

## Task 3

Write a function that returns the maximum value in outputArray in Task 2.

## Task 4

Write a program that prompts the user to enter a word that has 3 letters. Store this as a character array (i.e. strings in C). Create a new character array that stores the reverse of the word and display on the screen.

Sample output is as follows:

```txt
Enter a word with 3 letters> bee
Word entered: bee
Reverse word: eeb
```

Remember all strings in C should be NULL terminated - applies to both entered word and reserve word. The format specifier to print/scan a string is %s.

## Task 5

Use the relevant functions in string.h to append the input string and the reversed string in Task 4 with 'X' in between. For instance, if the input was bee, newly generated char array should contain

```txt
beeXeeb
```

Hint: The string.h library gives access to a lot of useful functions for manipulating strings. Read about strlen, strcpy, strcat on cplusplus.com. Some of those functions maybe helpful in this task.

## Task 6

A palindrome is a word, phrase, number, or other sequence of characters which reads the same backward as forward. For more information read the first paragraph in [this article](https://en.wikipedia.org/wiki/Palindrome).

Write a function that checks if a string is a palindrome.

- return 1: if the string input to the function is a palindrome
- return 0: otherwise

Use your function to check if the string created in Task 5 is a palindrome.
