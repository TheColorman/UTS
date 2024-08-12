# FOCP Lab 06

## Task 1

Extend the following program to show the value and the location at which each variable is stored. (remember we discussed about this in lectures?)

```c
# include <stdio.h>

int main (void)
{
  int a = 1, b = 2;
  int* ptr = &b;

  /*your code goes here*/

  return 0;
}
```

Find out the correct [format specifier to print a pointer](http://www.cplusplus.com/reference/cstdio/printf/).

Observe the values and locations, and answer the following questions.

1. What are the values of - a, b, ptr ?
2. What are the locations of - a, b, ptr (yes, the location of the pointer ptr) ?
3. Any of the locations are the same?
4. Any of the values are the same?
5. Explain the relationship between the **value of ptr** and the **location of b**.

First **try to code yourself**. Just in case you fail, [LAB06a.c](https://canvas.uts.edu.au/courses/33345/files/7520419?wrap=1) is the answer for this task.

## Task 2

Consider your solution (or the given answer) in Task 1. Increment the value of `ptr` by 1. Print the value of ptr before and after incrementing.

What conclusions can you draw from the before and after values? When you add 1, by how much did the pointer increment by? Could you relate that to the sizeof some data type? How does the program know by how much to increment a pointer value by when you do `ptr++`?

Define a new pointer `char* ptr2` and increment it by one `ptr2++`. What are the before and after values of `ptr2`?

## Task 3

Consider the following struct definition:

```c
struct player {
    char letter;
    int age;
}
typedef struct player player_t;
```

Write a program to do the following:

- Declare a pointer to a player_t variable
- Allocate memory using malloc
- Initialise each field of the struct
- Print the struct inside the main
- Pass the struct to a function which increments the age by one using a pointer to the struct
- Print the struct inside the main after the function was called
- Free the memory allocated to structs, and exit the program

NOTE: if you are looking for a challenge, extend this program to a linked list, prompt the user to enter player details, dynamically allocate/deallocate memory for the linked list.

## Task 4

Write a function that accepts an array of integers as an input, and output the sum of all values and the multiplication of all values. e.g. Suppose that the array contained the following values: 1 2 3 -4 5. The function should calculate and output the sum of values (i.e. 1+2+3+(-4)+5=7) and the multiplication of all values (i.e. 1*2*3*-4*5=-120).

Start by carefully writing the function prototype - put some thought into this. Think about the good programming habits, and keep in mind that a function can return only one value in C. After writing the prototype, complete the function definition and test it.

NOTE: Functions can output only one value from a function using the return keyword. In this task, your function is expected to output 2 values.
