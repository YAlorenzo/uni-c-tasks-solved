#include <stdio.h>
#include <string.h>

/*
 * Function reverse_lines_in_file() reverses each line in the input file
 * and writes the reversed lines to the output file.
 * It performs the following tasks:
 * 1. Opens the input file ("nacitat.txt") for reading.
 * 2. Opens the output file ("precitat.txt") for writing.
 * 3. Reads each line from the input file.
 * 4. Reverses the characters in the line.
 * 5. Writes the reversed line to the output file.
 *
 * Input:
 * - The input file "nacitat.txt" containing lines of text.
 *
 * Output:
 * - The output file "precitat.txt" containing the reversed lines.
 */
int reverse_lines_in_file() {
    FILE *fr = fopen("nacitat.txt", "r");
    FILE *fw = fopen("precitat.txt", "w");
    char str[50];

    // Check if files opened successfully
    if (fr == NULL || fw == NULL) {
        printf("Error opening file(s).\n");
        return -1;
    }

    // Process each line in the input file
    while (fgets(str, sizeof(str), fr)) {
        // Reverse the characters in the string
        for (int i = 0; i < strlen(str) / 2; i++) {
            char temp = str[i];
            str[i] = str[strlen(str) - i - 1];
            str[strlen(str) - i - 1] = temp;
        }

        // Write the reversed string to the output file
        fprintf(fw, "%s", str);
    }

    // Close the files
    fclose(fr);
    fclose(fw);

    return 0;
}


int main() {
    reverse_lines_in_file();
    return 0;
}
