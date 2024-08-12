# LAB05 - Structures and file processing

## Task 1 [struct]

Write a program that use a structure type player_t to store information about a Cricket player. You should store the following fields (no more, no less).

- `letter` - a char representing the first letter of the player's name
- `age` - an int field to store the age of the player
- `avg` - a double field to store the batting average of the player

At this stage the program should only define the structure type player_t and declare a player_t type variable called player. **Understand the distinct differences/similarities** between `struct player`, `player_t` and `player`.

**NOTE:** Be careful, pay attention to where in the program you should define player_t and player. You should avoid using global variables.

## Task 2 [struct]

**Write function that reads** the corresponding fields from the user and return a the player's information in structure form. Use the prototype:

```c
player_t scanPlayer (void);
```

Sample output when running this function would be:

```txt
Enter the first letter of the player name> B
Enter the age> 40
Enter the batting average> 99.941908
```

Also **write a function that prints** the content of a structure type player_t. Use the prototype:

```c
void printPlayer (player_t p);
```

Sample output when running this function would be (notice the rounding of batting average when printing):

```txt
B 40 99.94
```

Use these two functions in your main program to scan, store and print the variable `player`.

## Task 3 [struct]

Write a function that compares two players to decide if player A is better than player B. Use the following function prototype:

```c
int compAB (player_t playerA, player_t playerB);
```

If the batting average of player A is at least 10 runs more than player B, the player A is better (and vice versa). If the difference in batting average is 10 or less, and player A is at least 15 years younger than player B, the player A is better (and vice versa). If the difference in batting average is 10 or less and the difference in age is 15 or less, both players are indifferent.

The function should return an integer depending on the outcome of the comparison as follows:

1 : player A is better than player B

0 : both players are indifferent

-1: player B is better than player A

## Task 4 [file]

**Write function that prints** the first letter of the player name to a text file. Use the prototype:

```c
int savePlayerName (player_t p, char filename []);
```

The function should return

0 - if the letter was written successfully to the filename specified

1 - otherwise

Open the file you created, manually using Gedit. Do you see that the first letter of the player name has been saved in that file?

## Task 5 [file]

Write function that reads the first letter of the player name from a text file. Use the prototype:

```c
char readPlayerName (char filename []);
```

The function should return

> the letter (a-z, A-Z) read from the file - if the letter was read successfully from the filename specified  
> 1 - otherwise

Test if your function works - you might want to think about how you could test the function.

**NOTE:** Assume the file always has only one valid character - no need to read until the end of file (EOF).

## Task 6 [file]

Change the functions in Task 4 and 5 to print/read the entire structure, not only the first letter of the name.
