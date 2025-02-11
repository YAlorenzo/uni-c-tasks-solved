#include <stdio.h>
#include <string.h>

/*
 * Function replace_asterisk() prompts the user to enter a string (max 20 characters).
 * It performs the following tasks:
 * 1. Reads a string from the user.
 * 2. Searches for occurrences of '*' in the string.
 * 3. Replaces each '*' with the sequence '>*<'.
 * 4. Ensures that the modified string does not exceed its allocated size.
 * 5. Prints the modified string.
 *
 * Example:
 * Input: "*Hello*World*"
 * Output: "<*>Hello>*<World<*>"
 */


void replace_asterisk() {
    char str[50];
    printf("Enter a string (max 20 characters): ");
    fgets(str, sizeof(str), stdin);

    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        if (str[i] == '*') {
            if (length + 2 >= 50) {
                printf("String size limit exceeded!\n");
                break;
            }

            for (int j = length; j > i; j--) {
                str[j + 2] = str[j];
            }

            str[i] = '>';
            str[i + 1] = '*';
            str[i + 2] = '<';

            length += 2;
            i += 2;
        }
    }

    printf("Modified string: %s\n", str);
}

int main() {
    replace_asterisk();
    return 0;
}
