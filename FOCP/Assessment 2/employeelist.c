/*******************************************************************************
 * 48430 Fundamentals of C Programming - Assignment 2
 * Name: Alexander T
 * Student ID: 25434491
 * Date of submission: 2024-09-25
 * A brief statement on what you could achieve (less than 50 words):
 * Most functionality of the program is present.
 *
 * A brief statement on what you could NOT achieve (less than 50 words):
 * Tried to write binary data to the database first, couldn't get it to work
 * and could not be bothered to look into how to do it.
 * I also could not pass case 12 and 14, not sure why.
 *******************************************************************************/

/**
 * printf, fopen, spintf, fprintf, fflush, fclose, fgets, sscanf, scanf,
 * getchar
 */
#include <stdio.h>
#include <string.h> /* strcat */

/*******************************************************************************
 * List preprocessing directives
 *******************************************************************************/
#define MAX_COMPANY_SIZE 5
#define MAX_NAME_SIZE 11
#define MENU "\n\n1. add employee\n2. delete last employee\n3. display employee list\n4. save the employee list to the database\n5. read the employee list from the database\n6. exit the program\n"

struct date
{
    unsigned int day;
    unsigned int month;
    unsigned int year;
};
typedef struct date date_t;

struct employee
{
    char name[MAX_NAME_SIZE];
    float fte;
    unsigned int level;
    date_t birtday;
};
typedef struct employee employee_t;

struct employeelist
{
    employee_t employees[MAX_COMPANY_SIZE];
    unsigned int count;
};
typedef struct employeelist employeelist_t;

void printMenu(void);

int act(employeelist_t *eList);
void addEmployee(employeelist_t *eList);
void deleteLastEmployee(employeelist_t *eList);
void displayEmployeeList(employeelist_t *eList);
void saveEmployeeList(employeelist_t *eList);
void readEmployeeList(employeelist_t *eList);

unsigned int scanUint(char *prompt, char *invalid, unsigned int min, unsigned int max);
void scanString(char *prompt, char *target);
float scanFloat(char *prompt, char *invalid, float min, float max);
void clearInputBuffer(void);

void printMany(unsigned int count, char *value);
void printEmployee(employee_t e);

int main()
{
    employeelist_t eList;
    eList.count = 0;

    while (act(&eList) == 0);
    return 0;
}

/**
 * Prints the TUI menu
 */
void printMenu(void)
{
    printf(MENU);
}

/**
 * Does a full single run of the program, printing the menu and acting on the
 * user input.
 * @param[in,out] eList The list of employees
 */
int act(employeelist_t *eList)
{
    printMenu();
    switch (scanUint(
        "Enter your choice>\n",
        "Invalid choice."
        MENU,
        1,
        6))
    {
    case 1:
        addEmployee(eList);
        break;
    case 2:
        deleteLastEmployee(eList);
        break;
    case 3:
        displayEmployeeList(eList);
        break;
    case 4:
        saveEmployeeList(eList);
        break;
    case 5:
        readEmployeeList(eList);
        break;
    case 6:
        return 1;
    default:
        printf("Invalid choice.\n");
        break;
    }

    return 0;
}

/**
 * Adds an employee to the list, requesting details from the user.
 * @param[in,out] eList The list of employees to be updated
 */
void addEmployee(employeelist_t *eList)
{
    if (eList->count == MAX_COMPANY_SIZE)
    {
        printf("List is full");
        return;
    }

    employee_t e;

    scanString("Enter name>", e.name);
    e.birtday.day = scanUint("Enter birthday: day>", "Invalid day. ", 1, 31);
    e.birtday.month = scanUint("Enter birthday: month>", "Invalid month. ", 1, 12);
    e.birtday.year = scanUint("Enter birthday: year>", "Invalid year. ", 1800, 2017);
    e.fte = scanFloat("Enter FTE>", "Invalid FTE. ", 0.0, 1.0);
    e.level = scanUint("Enter level>", "Invalid level. ", 7, 18);

    eList->employees[eList->count] = e;
    eList->count++;
}

/**
 * Deletes the last employee from the list
 * @param[in,out] eList The list of employees to be updated
 */
void deleteLastEmployee(employeelist_t *eList)
{
    if (eList->count == 0)
    {
        printf("List is empty");
        return;
    }
    eList->count--;
}

/**
 * Pretty prints the list of employees
 * @param[in] eList The list of employees to be printed
 */
void displayEmployeeList(employeelist_t *eList)
{
    if (eList->count == 0)
    {
        printf("List is empty");
        return;
    }

    printf("Name");
    printMany(MAX_NAME_SIZE - 5, " ");
    printf(" Birthday   FTE   Level\n");
    printMany(MAX_NAME_SIZE - 1, "-");
    printf(" ---------- ----- -----\n");

    int i;
    for (i = 0; i < eList->count; i++)
    {
        printEmployee(eList->employees[i]);
    }
}

/**
 * Saves the list of employees to the database file
 * @param[in] eList The list of employees to be saved
 */
void saveEmployeeList(employeelist_t *eList)
{
    char buffer[1024];
    FILE *f = fopen("database", "w");
    if (f != NULL)
    {
        int i;
        for (i = 0; i < eList->count; i++)
        {
            employee_t e = eList->employees[i];
            sprintf(buffer, "%s\t%f\t%d\t%d\t%d\t%d", e.name, e.fte, e.level, e.birtday.day, e.birtday.month, e.birtday.year);
            fprintf(f, "%s\n", buffer);
        }
        fflush(f);
        fclose(f);
    }
    else
    {
        printf("Write error");
    }
}

/**
 * Reads the database file for a list of employees, then appends them to the
 * employeeList. The database file is read until the employee list is full.
 * @param[in,out] eList The list of employees to be updated
 */
void readEmployeeList(employeelist_t *eList)
{
    char buffer[1024];
    char maxNameSizeString[16];
    sprintf(maxNameSizeString, "%d", MAX_NAME_SIZE);
    char formatString[64];

    strcat(formatString, "%");
    strcat(formatString, maxNameSizeString);
    strcat(formatString, "s\t%f\t%d\t%d\t%d\t%d");

    FILE *f = fopen("database", "r");
    if (f != NULL)
    {
        while (fgets(buffer, sizeof(buffer), f))
        {
            if (eList->count == MAX_COMPANY_SIZE)
            {
                printf("List is full");
                break;
            }
            employee_t e;
            if (sscanf(buffer, formatString, e.name, &e.fte, &e.level, &e.birtday.day, &e.birtday.month, &e.birtday.year) == 0)
                break;
            eList->employees[eList->count] = e;
            eList->count++;
        }

        fflush(f);
        fclose(f);
    }
    else
    {
        printf("Read error");
    }
}

/**
 * Scans the user input for an unsigned integer
 * @param[in] prompt The prompt to be displayed to the user
 * @param[in] invalid The message to be displayed when the input is invalid
 * @param[in] min The minimum value the input can be, inclusive
 * @param[in] max The maximum value the input can be, inclusive
 * @return The unsigned integer scanned from the user
 */
unsigned int scanUint(char *prompt, char *invalid, unsigned int min, unsigned int max)
{
    int val = 0;

    while (1)
    {
        printf("%s", prompt);
        if (scanf("%d", &val) == 0)
        {
            clearInputBuffer();
        }
        if (min <= val && val <= max)
            return val;
        printf("%s", invalid);
    }
}

/**
 * Scans the user input for a string
 * @param[in] prompt The prompt to be displayed to the user
 * @param[out] target The string to be updated with the user input
 */
void scanString(char *prompt, char *target)
{
    printf("%s", prompt);
    scanf("%s", target);
    clearInputBuffer();
}

/**
 * Scans the user input for a float
 * @param[in] prompt The prompt to be displayed to the user
 * @param[in] invalid The message to be displayed when the input is invalid
 * @param[in] min The minimum value the input can be, inclusive
 * @param[in] max The maximum value the input can be, inclusive
 * @return The float scanned from the user
 */
float scanFloat(char *prompt, char *invalid, float min, float max)
{
    float val;

    while (1)
    {
        printf("%s", prompt);
        scanf("%f", &val);
        if (min <= val && val <= max)
            return val;
        printf("%s", invalid);
    }
}

/**
 * Clears the input buffer to prevent previous user input from polluting future
 * scanf calls. Source: https://stackoverflow.com/a/7898516
 */
void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

/**
 * Prints a given string a given number of times
 * @param[in] count The number of times to print the string
 * @param[in] value The string to be printed
 */
void printMany(unsigned int count, char *value)
{
    int i;
    for (i = 0; i < count; i++)
    {
        printf("%s", value);
    }
}

/**
 * Pretty prints an employee
 * @param[in] e The employee to be printed
 */
void printEmployee(employee_t e)
{
    printf("%s", e.name);
    printMany(MAX_NAME_SIZE - strlen(e.name) - 1, " ");
    printf(" %02d-%02d-%d %.3f %02d", e.birtday.day, e.birtday.month, e.birtday.year, e.fte, e.level);
    printf("\n");
}
