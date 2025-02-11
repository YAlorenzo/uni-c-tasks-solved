#include <stdio.h>

/*
 * Function process_and_write_input() prompts the user to enter a line of text.
 * It performs the following tasks:
 * 1. Reads characters from user input until a '.' is encountered.
 * 2. Converts uppercase letters to lowercase.
 * 3. Replaces lowercase letters with '.'.
 * 4. Replaces digits with '-'.
 * 5. Keeps newline characters unchanged.
 * 6. Replaces all other characters with '*'.
 * 7. Writes the modified text to a file named "output.txt".
 *
 * Output:
 * A file named "output.txt" containing the modified input text.
 *
 * Example:
 * Input: "ab=/4/C.fffff"
 * Output in file: "..**-*c"
 * Input: "abc4DEF"
 * Output in file: "...-def"
 */

void process_and_write_input() {
    int ch;
    FILE *fw = fopen("output.txt", "w");

    if (fw == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter a line (ends with '.'): ");

    while ((ch = getchar()) != '.') {
        if (ch >= 'A' && ch <= 'Z') {
            ch += 32;  // Convert to lowercase
            fprintf(fw, "%c", ch);
        }
        else if (ch >= 'a' && ch <= 'z') {
            fprintf(fw, ".");
        }
        else if (ch >= '0' && ch <= '9') {
            fprintf(fw, "-");
        }
        else if (ch == '\n') {
            fprintf(fw, "\n");
        }
        else {
            fprintf(fw, "*");
        }
    }

    fclose(fw);
}

int main() {
    process_and_write_input();
    return 0;
}
