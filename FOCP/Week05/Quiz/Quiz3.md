# Quiz 03 Part II

## Description

Develop a C program to a read a word as input from the keyboard and output whether the word contains duplicate letters.

Your program must display any duplicate letters and their number of occurrences in the same order as they appear in the input.

Hint: You may reuse the C function you developed in Lab 4 Task 6, that checks if a string is a palindrome, with modifications.

Hint: You might need to maintain a counter variable and a char array for the already checked duplicate characters in the word.

Hint: You may assume that one word cannot have more than 15 characters.

## Sample run

A sample run of the program if the user input was "programme" is as follows:

```txt
Enter a word>
programme
Duplicate letter: r, Occurrences: 2
Duplicate letter: m, Occurrences: 2
```

Another sample run of the program if the user input was "abracadabra" is as follows:

```txt
Enter a word>
abracadabra
Duplicate letter: a, Occurrences: 5
Duplicate letter: b, Occurrences: 2
Duplicate letter: r, Occurrences: 2
```

If the word has no duplicate characters the output should be as follows.

```txt
Enter the word>
phone
No duplicates found
```

## Submission

**You should complete the code provided in quiz3.c file** to the right of quiz description. (If you cannot see quiz1.c file, click on the drop down list and select 'Reset to Scaffold' option. Note that doing so would any code you may have typed and you might want to save a backup before doing so.)

Your can submit your code by clicking 'Mark' button at the right bottom corner. By clicking Mark you agree that this is your own work, and followed all instructions in the specification.

## Sample executable

Sample executable is attached in the Scaffold. Develop your own source code. Behaviour of your program **MUST BE IDENTICAL** to the sample executable provided - every single character including spaces.

## Testing process

Your program should compile with **NO errors** and **NO warnings**. Ed will automatically compare your source code to the sample executable. Feedback is provided immediately. You are allowed **unlimited** number of attempts before the deadline. No late submissions are accepted - no exceptions to this rule. The submission page will show the total number of tests and the marks granted to your submission. The marks for this part of the quiz done on Ed will NOT show in UTSOnline Grade Book immediately.

**ALL** tests are mandatory. When you pass one test, the next test will be revealed. Ed will also show the marks for each test case progressively. If your program does not compile due to filename error, syntax error or any other error, you will receive 0 marks for the attempt.

**Do NOT hardcode your answers. Tutors will randomly check the submissions. If you hardcode your solution, tutors may change your marks to 0.**
