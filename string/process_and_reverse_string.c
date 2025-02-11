#include <stdio.h>
#include <string.h>
#include "reverse_string.c"
/*
 * Function remove_all() removes all occurrences of a given character from a string.
 * It iterates through the string and shifts characters to the left,
 * overwriting any occurrence of the specified character.
 * The function modifies the string in-place.
 *
 * Parameters:
 * - str: A pointer to the string from which characters will be removed.
 * - elem: The character to be removed from the string.
 *
 * The function returns the modified string with all occurrences of the specified character removed.
 *
 * Example:
 * Input: "hello world", 'o'
 * Output: "hell wrld"
 */

char *remove_all(char *str, char elem) {
    int i = 0; // Index for reading characters from the original string
    int j = 0; // Index for writing characters to the modified string

    // Iterate through the string and remove occurrences of 'elem'
    while (str[i] != '\0') {
        if (str[i] != elem) {
            str[j++] = str[i]; // Copy the character to the new position
        }
        i++;
    }
    str[j] = '\0'; // Null-terminate the modified string
    return str; // Return the modified string
}

/*
 * Function cv6_2() takes an input string, removes all spaces,
 * and replaces any digits with '**'. It then reverses the modified string
 * and prints the result.
 *
 * Example:
 * Input: "hello 123 world"
 * Output: "dlrw**321 olleh"
 */

int process_and_reverse_string() {
    char str[500];
    int i = 0;
    int j = 0;
    char elem;
    int count = 0;

    gets(str); // Read input string (deprecated; use fgets in production code)
    remove_all(str, ' '); // Remove all spaces from the string

    // Replace digits with '**'
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            // Shift characters to the right to make space for '**'
            for (j = strlen(str); j > i; j--) {
                str[j + 1] = str[j];
            }
            str[i] = '*'; // Replace digit with '*'
            str[i + 1] = '*'; // Insert second '*'
        }
        i++;
    }

    printf("%s\n", reverse_string(str)); // Reverse the string and print it
}

int main() {
    process_and_reverse_string(); // Call the function to execute the operations
    return 0;
}
