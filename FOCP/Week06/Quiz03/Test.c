#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ipaddr
{
  int octet1;
  int octet2;
  int octet3;
  int octet4;
};
typedef struct ipaddr ipaddr_t;

/*
This function prints a ipaddr_t variable on the terminal in the following format
octet1.octet2.octet3.octet4
No spaces, no new line in the end, octets are separated by a dot.
Inputs:
  ip - ipaddr_t variable that needs to be printed
*/
void print_ipaddr(ipaddr_t ip)
{
  printf("%d.%d.%d.%d", ip.octet1, ip.octet2, ip.octet3, ip.octet4);
}

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
{
  int octets[] = {ip.octet1, ip.octet2, ip.octet3, ip.octet4};
  unsigned char i;
  for (i = 0; i < 4; i++)
  {
    if (octets[i] < 0 || octets[i] > 255)
      return 0;
  }
  return 1;
}

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
{
  int A[] = {ip1.octet1, ip1.octet2, ip1.octet3, ip1.octet4};
  int B[] = {ip2.octet1, ip2.octet2, ip2.octet3, ip2.octet4};
  int i;
  for (i = 0; i < 4; i++)
  {
    if (A[i] != B[i])
      return 0;
  }
  return 1;
}

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
{
  int A[] = {ip1.octet1, ip1.octet2, ip1.octet3};
  int B[] = {ip2.octet1, ip2.octet2, ip2.octet3};
  int i;
  for (i = 0; i < 3; i++)
  {
    if (A[i] != B[i])
      return 0;
  }
  return 1;
}

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
{
  ipaddr_t curr_addr;
  int validcount = 0;
  while (validcount < addr_array_len)
  {
    printf(">\n");
    if (!scanf("%d.%d.%d.%d", &curr_addr.octet1, &curr_addr.octet2,
               &curr_addr.octet3, &curr_addr.octet4))
    {
      printf("Input error!\n");
      continue;
    }
    if (curr_addr.octet1 == -1 && curr_addr.octet2 == -1 && curr_addr.octet3 == -1 && curr_addr.octet4 == -1)
      return validcount;

    if (is_valid(curr_addr) == 0)
    {
      printf("Invalid input\n");
      continue;
    }

    addr_array[validcount] = curr_addr;
    validcount++;
  }

  return validcount;
}

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
{
  ipaddr_t *inpu_addrs = (ipaddr_t *)malloc(sizeof(ipaddr_t) * addr_array_len);
  memcpy(inpu_addrs, addr_array, sizeof(ipaddr_t) * addr_array_len);
  ipaddr_t *uniq_subnets = (ipaddr_t *)malloc(sizeof(ipaddr_t) * addr_array_len);

  ipaddr_t *inpu_end = inpu_addrs + addr_array_len;
  ipaddr_t *uniq_end = uniq_subnets + addr_array_len;

  ipaddr_t *inpu_start = inpu_addrs;
  ipaddr_t *uniq_start = uniq_subnets;

  /* set uniq_subnets to negative */
  while (uniq_subnets < uniq_end)
  {
    uniq_subnets->octet1 = -1;
    uniq_subnets++;
  }
  uniq_subnets = uniq_start;

  /* I'm starting the iterators earlier so I can increment at the start of loops */
  uniq_subnets--;

  /* Iterate over the unique subnets*/
  while (uniq_subnets + 1 < uniq_end)
  {
    uniq_subnets++;
    inpu_addrs = inpu_start - 1;
    /* Iterate over the input addresses */
    while (inpu_addrs + 1 < inpu_end)
    {
      inpu_addrs++;
      /* An adress is to to NULL when it has been used. */
      if (inpu_addrs->octet1 == -1)
        continue;
      if (uniq_subnets->octet1 == -1)
      {
        *uniq_subnets = *inpu_addrs;
        print_ipaddr(*inpu_addrs);
        inpu_addrs->octet1 = -1;
        continue;
      }
      if (is_same_subnet(*uniq_subnets, *inpu_addrs) == 1)
      {
        printf(" ");
        print_ipaddr(*inpu_addrs);
        inpu_addrs->octet1 = -1;
        continue;
      }
    }
    if (uniq_subnets->octet1 != -1)
      printf("\n");
  }
}

int main()
{
  int len = 4;

  ipaddr_t addr[4];
  int v = get_valid_ipaddrs(addr, len);

  printf("%d", v);

  print_same_subnet(addr, len);

  return 0;
}