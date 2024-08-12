# Quiz 05 Part II

## Description

Consider the following struct definition,

```c
struct player {
    int age;
    int wickets;
};
typedef struct player player_t;
```

In this task you are required to implement the functions given below by following the function descriptions.

```c
/*
This function allocates memory for a player_t pointer variable.
Inputs:
  player_p_p - memory location of a player_t pointer variable
  nplayers - number of players that memory needs to be allocated for
Return:
  0 - success
  1 - failed to allocate memory
Post:
  After the function has been called,*player_p_p will point to freshly
  allocated memory if malloc was successful. Otherwise *player_p_p will point to
  NULL.
*/
int allocate_memory(player_t** player_p_p, long int nplayers)

/*
This function initialises each field of one playet_t struct.
Inputs:
  player_p - memory location of the player_t variable. player_p must have been
    allocated memory using allocate_memory before calling this function.
  age - age of the player
  wickets - number of wickets of the player
Post:
  After the function has been called, the age field of*player_p will be the
  input age, and wickets field of *player_p will be the input wickets.
*/
void init_player(player_t* player_p, int age, int wickets)

/*
This function prints a player_t variable in the following format:
player - age:AA wickets:WWW
Inputs:
  player_p - variable to be printed
*/
void print_player(player_t player)

/*
This function compares two players. If*player1_p is older than the *player2_p,
swap them. In all other cases, do not swap them.
Inputs:
  player1_p - memory location of the first player
  player2_p - memory location of the second player
Post:
  After the function has been called, the age of*player1_p is always less than
  or equal to *player2_p age.
*/
void order_two_players(player_t* player1_p, player_t* player2_p)

/*
Sort an array of players in non-decreasing order of the age by implementing the
following algorithm:

1. Compare two adjacent players, if the first player is older than the second,
   swap the first and second players.
2. Keep comparing the next two adjacent players in the array, until the end of
   the array is reached.
3. Repeat the above steps for players_len times.
This simple algorithm is also known as bubble sort.
Inputs:
  players - player_t array (memory location of 0th element in the array)
  players_len - number of players in the array
*/
void order_all_players(player_t* players, int players_len)
```

Below is an example on how you can check if memory allocation has been successful. You can use a similar approach to test **allocate_memory()** function in a separate workspace.

```c
player_t* bowler_p = NULL;
int allocresult = allocate_memory(&bowler_p, num);
if ((allocresult==0 && bowler_p!=NULL) || (allocresult==1 && bowler_p==NULL)){
    printf("allocate_memory: function allocates memory for %d player/s\n", num);
    printf("allocate_memory: PASS\n");
}
else {
    printf("allocate_memory: FAIL\n");
}
```

## Submission

**You should complete the code provided in quiz5.c file** to the right of quiz description. (If you cannot see quiz5.c file, click on the drop down list and select 'Reset to Scaffold' option. Note that doing so would delete any code you may have typed and you might want to save a backup before doing so.)  **No need to write/change the main. No need to add function prototypes. No need to add struct definitions.**

Your can submit your code by clicking 'Mark' button at the right bottom corner. By clicking Mark you agree that this is your own work, and followed all instructions in the specification.

## Testing process

You should make your own main file in a separate workspace to test your quiz5.c and do NOT use the main file we provided in the scaffold for testing your code. "no output" in the feedback might mean your code has a compilation error.

Your program should compile with **NO errors** and **NO warnings**. Ed will automatically compare your source code to the sample executable. Feedback is provided immediately. You are allowed **unlimited** number of attempts before the deadline. No late submissions are accepted - no exceptions to this rule. The submission page will show the total number of tests and the marks granted to your submission. The marks for this part of the quiz done on Ed will NOT show in UTSOnline Grade Book immediately.

**ALL** tests are mandatory. When you pass one test, the next test will be revealed. Ed will also show the marks for each test case progressively. If your program does not compile due to filename error, syntax error or any other error, you will receive 0 marks for the attempt.

Do NOT hardcode your answers. Tutors will randomly check the submissions. If you hardcode your solution, tutors may change your marks to 0.
