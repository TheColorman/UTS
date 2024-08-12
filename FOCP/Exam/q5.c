/*
WRITE YOUR ANSWER IN THIS FILE.

Write a complete program - functions and main().
*/
#define MAX_LEN 10
#define NAME_LEN 24
#define DEP_LEN 24
#define MAX_LINE_SIZE 256
#include <stddef.h> /* size_t, NULL */
#include <stdio.h>  /* FILE, fopen, printf, sscanf */
#include <string.h> /* strcpy */
#include <stdlib.h> /* exit */

struct employee
{
  char name[NAME_LEN];
  int id;
  char department[DEP_LEN];
  double salary;
};
typedef struct employee employee_t;

int readEmployeeList(employee_t dest[]);
void sortEmployees(employee_t employees[], int count);
void printEmployeeDetails(employee_t employees[], int count);
void trimNewline(char str[]);

int main()
{
  employee_t *employees = malloc(sizeof(employee_t) * MAX_LEN);

  int employeeCount = readEmployeeList(employees);
  sortEmployees(employees, employeeCount);
  printEmployeeDetails(employees, employeeCount);

  return 0;
}

/**
 * Reads employees from employeeRecords.txt into the dest array
 */
int readEmployeeList(employee_t dest[])
{
  char line[MAX_LINE_SIZE];
  int i = 0;
  int count = 0;
  FILE *f = fopen("employeeRecords.txt", "r");

  if (!f)
  {
    printf("Failed to open record file.\n");
    exit(1);
  }

  while (fgets(line, MAX_LINE_SIZE, f))
  {
    if (i == 0)
    {
      count++;
      employee_t e;
      trimNewline(line);
      strcpy(e.name, line);
      *dest = e;
    }
    else if (i == 1)
    {
      sscanf(line, "%d", &dest->id);
    }
    else if (i == 2)
    {
      trimNewline(line);
      strcpy(dest->department, line);
    }
    else if (i == 3)
    {
      sscanf(line, "%lf", &dest->salary);
    }

    if ((i + 1) % 4 == 0)
    {
      i = 0;
      dest++;
    }
    else
      i++;
  }

  dest -= count;
  return count;
}

/**
 * Sorts a list of employees by salary
 */
void sortEmployees(employee_t employees[], int count)
{
  int i, j;
  for (i = 0; i < count; i++)
  {
    for (j = 0; j < count - 1; j++)
    {
      employee_t *emp1_p = employees + j;
      employee_t *emp2_p = employees + j + 1;

      if (emp2_p->salary > emp1_p->salary)
      {
        employee_t *temp = emp1_p;
        emp1_p = emp2_p;
        emp2_p = temp;
        temp = NULL;
      }
    }
  }
}

/**
 * Print a list of employees to the console, along with the total and average salary.
 */
void printEmployeeDetails(employee_t employees[], int count)
{
  int i;
  double sum = 0.0;

  printf("Name       ID      Department   Salary\n");

  for (i = 0; i < count; i++)
  {
    printf("%s ", employees[i].name);
    printf("%d ", employees[i].id);
    printf("%s ", employees[i].department);
    printf("$%.2lf \n", employees[i].salary);

    sum += employees[i].salary;
  }

  printf("\nTotal Salary: $%.2lf\n", sum);
  printf("Average Salary: $%.2lf\n", sum / count);
}

/**
 * Remove a trailing newline from a string
 */
void trimNewline(char str[])
{
  str[strcspn(str, "\n")] = 0;
}