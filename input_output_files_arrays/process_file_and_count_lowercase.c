#include <stdio.h>

/*
 * Function process_file_and_count_lowercase() processes the input file "vstup.txt" and performs the following tasks:
 * 1. Reads the content of the file line by line.
 * 2. For each line, it counts the number of lowercase letters.
 * 3. It writes the line to the output file "cisla.txt" and appends the count of lowercase letters at the end of each line.
 * 4. The function handles multiple lines in the file and resets the count of lowercase letters for each new line.
 *
 * Example:
 * Input: vstup.txt contains:
 * "Hello World"
 * "This is a test"
 *
 * Output: cisla.txt contains:
 * "Hello World\n"
 * "3\n"
 * "This is a test\n"
 * "4\n"
 */

void process_file_and_count_lowercase() {
    int i = 0;
    int lowercase_count = 0; // count of lowercase letters in the line
    char ch;
    char f_row[1000]; // store the line

    FILE *fr = fopen("vstup.txt", "r");
    FILE *fw = fopen("cisla.txt", "a");

    if (fr == NULL || fw == NULL) {
        printf("Error opening files!");
        return;
    }

    // Read file line by line
    while ((ch = fgetc(fr)) != EOF) {
        if (ch != '\n') {  // if the character is not a newline
            f_row[i] = ch;
            i++;
            if (ch >= 'a' && ch <= 'z') {  // if the character is a lowercase letter
                lowercase_count++;
            }
        } else {
            // Write the line to the output file
            for (int j = 0; j < i; j++) {
                fprintf(fw, "%c", f_row[j]);
                f_row[j] = 0; // clear the line array
            }
            fprintf(fw, "\n");

            // Write the count of lowercase letters
            fprintf(fw, "%d\n", lowercase_count);

            // Reset for the next line
            i = 0;
            lowercase_count = 0;
        }
    }

    fclose(fr);
    fclose(fw);
}

int main() {
    process_file_and_count_lowercase();
    return 0;
}
