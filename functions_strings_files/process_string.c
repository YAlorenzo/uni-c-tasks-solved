#include <stdio.h>
#include <string.h>

/*
 * Function remove_all_chars() removes all occurrences of a specified character (elem)
 * from the input string (str).
 * It performs the following tasks:
 * 1. Iterates through the string.
 * 2. If the character is not equal to the specified element (elem), it copies it to the new position.
 * 3. At the end, it appends a null terminator to mark the end of the string.
 *
 * Input:
 * - str: The input string to be processed.
 * - elem: The character to be removed from the string.
 *
 * Output:
 * - The modified string with all occurrences of the specified character removed.
 */
char *remove_all_chars(char *str, char elem) {
    int i = 0; // Index for the original string
    int j = 0; // Index for the modified string
    while (str[i] != '\0') {
        if (str[i] != elem) {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0'; // Null terminate the modified string
    return str;
}

/*
 * Function process_string() processes a given string by removing all periods and
 * duplicating every '*' character in the string.
 * It performs the following tasks:
 * 1. Removes all periods ('.') from the string using remove_all_chars().
 * 2. Iterates through the string and doubles every '*' character by shifting the rest of the string to the right.
 * 3. The string is then printed after processing.
 *
 * Input:
 * - str: The string entered by the user.
 *
 * Output:
 * - The modified string with all periods removed and each '*' doubled.
 */
int process_string() {
    char str[100];
    int i, len;

    printf("Enter a string: ");
    scanf("%s", str);

    // Remove all periods from the string
    remove_all_chars(str, '.');

    // Length of the string before processing
    len = strlen(str);

    // Iterate through the string and duplicate the '*' characters
    for (i = 0; i < len; i++) {
        if (str[i] == '*') {
            // Shift all characters to the right starting from the end
            for (int j = len; j > i; j--) {
                str[j + 1] = str[j];
            }

            // Add the second '*' character
            str[i + 1] = '*';

            // Skip the next '*' character and increase the length
            i++;
            len++;
        }
    }

    // Terminate the string with a null character
    str[len] = '\0';

    printf("Output: %s\n", str);

    return 0;
}


int main() {
    process_string();
    return 0;
}
