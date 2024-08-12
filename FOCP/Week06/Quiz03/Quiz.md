# Quiz 04 Part II

## Description

Each computer connected to the UTS network has a unique identification number called the "IP address". An IP address has the following form: octet1.octet2.octet3.octet4, where octet1, octet2, octet3 and octet4 are integer numbers between 0 and 255 (inclusive).

Consider the following struct definition to store an IP address:

```c
struct ipaddr {
    int octet1;
    int octet2;
    int octet3;
    int octet4;
};
typedef struct ipaddr ipaddr_t;
```

In this task you are only required to implement the functions given below by following the function descriptions.

```c
/*
This function prints a ipaddr_t variable on the terminal in the following format
octet1.octet2.octet3.octet4
No spaces, no new line in the end, octets are separated by a dot.
Inputs:
  ip - ipaddr_t variable that needs to be printed
*/
void print_ipaddr(ipaddr_t ip)

/*
An IP address is valid if all 4 octets have values between 0 and 255(inclusive).
The function checks if the input ip address is valid.
Inputs:
  ip - ipaddr_t input IP address variable
Return:
  1 - if input ip is valid
  0 - otherwise

PASS/FAIL in the feedback means you have passed/failed the test case.
*/
int is_valid(ipaddr_t ip)

/*
Two IP addresses are equal if all 4 octets of both addresses have identical
values. The function checks if two IP addresses are equal.
Inputs:
  ip1 - ipaddr_t input IP address 1
  ip2 - ipaddr_t input IP address 2
Return:
  1 - if ip1 and ip2 are equal
  0 - otherwise
  
*/
int is_equal(ipaddr_t ip1, ipaddr_t ip2)

/*
Two IP addresses are said to be in the same subnet if octet1, octet2 and octet3
have identical values. The function checks if two ip addresses are in the same
subnet.
Note for students with a networking background: we are considering a simplified
definition of a subnet. Use the above definition given for this question.
Inputs:
  ip1 - ipaddr_t input IP address 1
  ip2 - ipaddr_t input IP address 2
Return:
  1 - if ip1 and ip2 are in the same subnet
  0 - otherwise
*/
int is_same_subnet(ipaddr_t ip1, ipaddr_t ip2)

/*
The function prompts the user to enter IP addresses in the following format:
  octet1.octet2.octet3.octet4
in separate lines. If an input IP address is invalid, the function prints the
following error message:
  Invalid input
and prompt the user again to give a valid input. The function may scan up to
addr_array_len valid IP addresses, or until the user enters -1.-1.-1.-1 as the
input, whichever occurs first.

Sample run 1 with addr_array_len=5, the function returns 2:
>
192.168.1.1
>
-192.168.1.1
Invalid input
>
192.168.1.2
>
-1.-1.-1.-1

Sample run 2 with addr_array_len=2, the function returns 2:
>
192.168.1.1
>
192.168.1.2

Inputs:
  addr_array_len - maximum possible number of inputs, this is the size of the
    addr_array array.
  addr_array - valid addresses from the user are saved to this array.
Return:
  the number of valid IP addresses given by the user
Post:
  After the function has been called, addr_array contains the valid IP
  addresses entered by the user.
*/
int get_valid_ipaddrs(ipaddr_t addr_array[], int addr_array_len)

/*
Display IP addresses in the same subnet in addr_array. All addresses in the one
subnet should be displayed in the same line, in the same order the addresses
were entered. Each address is separated by one space, and each line has a
trailing space in the end of the line prior to the new line character.

Sample run 1 where addr_array contains the following IP addresses {192.168.1.1,
192.168.2.1, 192.168.1.2, 192.168.1.3} and addr_array_len=4:
192.168.1.1 192.168.1.2 192.168.1.3
192.168.2.1

Input:
  addr_array - contains IP addresses
  addr_array_len - the number of IP addresses in the addr_array
*/
void print_same_subnet(const ipaddr_t addr_array[], int addr_array_len)
```

## **Submission**

**You should complete the code provided in quiz4.c file** by **completing the function implementations only** to the right of quiz description. (If you cannot see quiz4.c file, click on the drop down list and select 'Reset to Scaffold' option. Note that doing so would delete any code you may have typed and you might want to save a backup before doing so.) **No need to write/change the main. No need to add function prototypes. No need to add struct definitions.**

Your can submit your code by clicking 'Mark' button at the right bottom corner. By clicking Mark you agree that this is your own work, and followed all instructions in the specification.

## Testing process

Your program should compile with **NO errors** and **NO warnings**. Ed will automatically compare your source code to the sample executable. Feedback is provided immediately. You are allowed **unlimited** number of attempts before the deadline. No late submissions are accepted - no exceptions to this rule. The submission page will show the total number of tests and the marks granted to your submission. The marks for this part of the quiz done on Ed will NOT show in UTSOnline Grade Book immediately.

**ALL** tests are mandatory. When you pass one test, the next test will be revealed. Ed will also show the marks for each test case progressively. If your program does not compile due to filename error, syntax error or any other error, you will receive 0 marks for the attempt.

Do NOT hardcode your answers. Tutors will randomly check the submissions. If you hardcode your solution, tutors may change your marks to 0.
