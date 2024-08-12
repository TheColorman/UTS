/**
 * Group X, Lab Y
 * This programs encrypts and stores encrypted text, as well as allowing a
 * user to later retrieve the original text.
 * Compilation instructions:
 * Simply use a valid C compiler such as gcc and run
 * `gcc integrated.c -o integrated.out`
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DATABASE_FILE "database.txt"
#define MAX_LINE_SIZE 256
#define MAX_PASSWORD_SIZE 50
#define MIN_PASSWORD_SIZE 6
#define PAD "HEY"

/* === Prototypes === */
void apply_xor(char *text, size_t text_length, char *key, size_t key_length, char *out);
int create_record(char *text, size_t text_length, char *password, size_t password_length);
int read_record(int id, char *password, size_t password_length, char *out);
void trim_newline(char *str);
void ui_create_record();
void ui_read_record();

/**
 * Takes as input some text and a key, then applies bitwise XOR between them.
 * Loops the key if it is shorter than the text. This effectively encrypts a
 * plaintext using a pre-shared key. Passing in an encrypted text in the `text`
 * parameters will decrypt it.
 * @param[in] text char pointer to the text array to apply XOR to.
 * @param[in] text_length length of the text.
 * @param[in] key char pointer to the key array used for XOR.
 * @param[in] key_length length of the key.
 * @param[out] out char pointer to text array that is the result of the XOR operation.
 */
void apply_xor(char *text, size_t text_length, char *key, size_t key_length, char *out)
{
    int i;
    for (i = 0; i < text_length; i++)
    {
        /* XOR the text and key at current position */
        *out = *text ^ *key;
        /* Move to next position */
        out++, text++, key++;
        /* Reset key position if we'we reached the end */
        if ((i + 1) % key_length == 0)
            key -= key_length;
    }
    /* Set last character of output to 0x00 to terminate string */
    *out = 0x00;

    /* == Reset all positions == */
    /**
     * note we may not have reached the end of the key, so we don't want to go
     * key_length steps back.
     */
    key -= i % key_length;
    out -= text_length;
    text -= text_length;
}

/**
 * Creates a new record in the database by encrypting input text with an input password.
 * @param[in] text the text to encrypt and store
 * @param[in] text_length the length of the input text
 * @param[in] password the password to use for encryption
 * @param[in] password_length the length of the password
 * @returns the line number of the newly saved record. Used as an ID, or -1 if
 *          an error ocurred.
 */
int create_record(char *text, size_t text_length, char *password, size_t password_length)
{
    /* Put HEY in front of every line so if it comes back out when decrypted
       you know it's correct */
    char padded_text[text_length + 4];
    strcpy(padded_text, PAD);
    strcat(padded_text, text);

    char *encrypted = malloc(sizeof(char) * (text_length + 4));
    apply_xor(padded_text, text_length + 3, password, password_length, encrypted);

    /* Open file for writing */
    FILE *file = fopen(DATABASE_FILE, "a");

    if (!file)
    {
        perror("Failed to open the database");
        free(encrypted);
        return -1;
    }

    /* Write bytes as space-separated integers. This is because the encryption
       step may convert some of the chars into newlines or even null bytes. */
    int i;
    for (i = 0; i < text_length + 3; i++)
        fprintf(file, "%d ", encrypted[i]);
    fprintf(file, "\n");
    fclose(file);
    free(encrypted);

    int line_number = 0;

    file = fopen(DATABASE_FILE, "r");
    if (!file)
    {
        perror("Failed to open the database");
        return -1;
    }

    char ch = getc(file);
    for (; ch != EOF; ch = getc(file))
        if (ch == '\n')
            line_number++;
    fclose(file);

    return line_number;
}

/**
 * Reads and decrypts a record from the database into out.
 * @param[in] id id/line number of the target record
 * @param[in] password password used for decryption
 * @param[in] password_length length of the given password
 * @param[out] out resulting decrypted text
 * @returns 0 if decryption went well, -1 if the database file could not be
 *          opened, -2 if the password was incorrect.
 */
int read_record(int id, char *password, size_t password_length, char *out)
{
    FILE *file = fopen(DATABASE_FILE, "r");

    if (!file)
    {
        perror("Failed to open the database");
        return -1;
    }

    char line[MAX_LINE_SIZE];

    int current_line = 0;
    while (fgets(line, sizeof(line), file))
    {
        if (current_line+1 == id)
            break;
        current_line++;
    }

    const char *ptr = line;
    int curr;
    int count = 0;
    /* The line is a sequence of numbers, separated by spaces. We parse each
       number in the line and save the char representation to out */
    while (*ptr != '\n' && *ptr != '\0')
    {
        if (sscanf(ptr, "%d", &curr) == 1)
        {
            out[count++] = (char)curr;

            /* Pointer is still at the current number. Move forward until we
               reach the next number (denoted by space) */
            while (*ptr != ' ' && *ptr != '\n' && *ptr != '\0')
            {
                ptr++;
            }
        }
        if (*ptr == ' ')
        {
            ptr++; // Skip the space
        }
    }

    fclose(file);
    apply_xor(out, count, password, password_length, out);

    /* Check whether the first 3 characters match our pad */
    if (strncmp(out, PAD, strlen(PAD)) == 0)
    {
        /* Remove PAD from start of string. Note that this doesn't actually
           check whether the string is long enough, but we assume it is because
           we assume it was generated by this program. */
        int outlen = strlen(out);
        int padlen = strlen(PAD);
        memmove(out, out + padlen, outlen - padlen + 1);
        return 0;
    }
    else
        return -2;
}

/**
 * Removes the final newline, and all succeeding characters, by replacing it
 * with a null byte.
 * @param[in,out] str the string to change
 */
void trim_newline(char *str)
{
    str[strcspn(str, "\n")] = 0x00;
}

/**
 * Displays the UI for creating a new record.
 */
void ui_create_record()
{
    char text[MAX_LINE_SIZE];
    char password[MAX_PASSWORD_SIZE];

    printf("Enter text to store: ");
    fgets(text, MAX_LINE_SIZE, stdin);

    trim_newline(text);

    while (1)
    {
        printf("Enter password for encryption: ");
        fgets(password, MAX_PASSWORD_SIZE, stdin);
        if (strlen(password) < MIN_PASSWORD_SIZE)
            printf("Password not long enough. Please try again.\n");
        else
            break;
    }

    trim_newline(password);

    int id = create_record(text, strlen(text), password, strlen(password));
    if (id >= 0) /* Negative numbers are returned on errors. */
        printf("Record created with ID: %d\n", id);
    else
        printf("Failed to create record.\n");
}

/**
 * Displays the UI for reading a record.
 */
void ui_read_record()
{
    int id;
    char password[MAX_PASSWORD_SIZE];
    char decrypted[MAX_LINE_SIZE];

    printf("Enter the ID of the record you would like to read: ");
    scanf("%d", &id);
    getchar(); /* =Don't know what it does but it makes it work v2 */
    printf("Enter password for decryption: ");

    fgets(password, 50, stdin);

    trim_newline(password);
    int result = read_record(id, password, strlen(password), decrypted);
    if (result == 0)
        printf("Decrypted Record: %s\n", decrypted);
    else if (result == -1)
        printf("Failed to open database for reading. Please try again.");
    else if (result == -2)
        printf("Incorrect password, please try again.\n");
    else {
        printf("uh oh, this isn't supposed to happen. "
               "something has gone very wrong indeed!\n");
        printf("%d\n", result);
    }
}

int main()
{
    while (1)
    {
        printf("Welcome, Please select an Option from below. \n");
        printf("1. Create record\n");
        printf("2. Read record\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);
        getchar(); /* Not entirely sure what this is for, but i found it on github and it made it work */

        switch (choice)
        {
        case 1:
            ui_create_record();
            break;
        case 2:
            ui_read_record();
            break;
        case 3:
            printf("Program Terminating\n");
            exit(0);
        default:
            printf("Invalid option. Please try again.\n"); /* make sure they actually pick on of the options */
            break;
        }
    }
    return 0;
}
