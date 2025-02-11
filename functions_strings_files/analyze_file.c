#include <stdio.h>

/*
 * Function analyze_file() analyzes a given file and counts the number of lines,
 * spaces, and digits in the file.
 * It performs the following tasks:
 * 1. Opens the file in read mode.
 * 2. Reads each character in the file.
 * 3. Counts the number of digits, spaces, and newlines.
 * 4. If the file is not empty, it increments the line count for the last line.
 *
 * Input:
 * - file_path: The file path to be analyzed.
 * - lines: A pointer to an integer to store the count of lines.
 * - spaces: A pointer to an integer to store the count of spaces.
 * - digits: A pointer to an integer to store the count of digits.
 *
 * Output:
 * - Returns the total number of characters read from the file.
 * - Updates the values of lines, spaces, and digits to the respective counts.
 *
 * Example:
 * Input: "sample.txt"
 * Output:
 * - Number of lines: 5
 * - Number of spaces: 20
 * - Number of digits: 10
 */


int analyze_file(char *file_path, int *lines, int *spaces, int *digits) {
    char ch;
    int i = 0;
    FILE *fr = fopen(file_path, "r");

    if (fr == NULL) {
        return -1; // Return -1 if the file cannot be opened
    }

    // Read each character from the file
    while ((ch = fgetc(fr)) != EOF) {
        if (ch >= '0' && ch <= '9') {
            (*digits)++; // Count digits
        }
        else if (ch == ' ') {
            (*spaces)++; // Count spaces
        }
        else if (ch == '\n') {
            (*lines)++; // Count newlines (lines)
        }
        i++; // Increment character count
    }

    // If the file is not empty, add the last line (if missing)
    if (i > 0 && ch != '\n') {
        (*lines)++;
    }

    fclose(fr); // Close the file

    return i; // Return the total number of characters read
}

/*
 * Main function to test the analyze_file() function.
 * It prompts the user to enter a file path,
 * then prints the number of lines, spaces, digits, and the total number of characters.
 */
int main() {
    char file_path[100];
    int lines = 0, spaces = 0, digits = 0, total_chars;

    printf("Enter the file path to analyze: ");
    scanf("%s", file_path);

    // Call the analyze_file() function
    total_chars = analyze_file(file_path, &lines, &spaces, &digits);

    // Check if the file was successfully analyzed
    if (total_chars == -1) {
        printf("Error opening the file.\n");
    } else {
        // Print the results
        printf("Total characters: %d\n", total_chars);
        printf("Lines: %d\n", lines);
        printf("Spaces: %d\n", spaces);
        printf("Digits: %d\n", digits);
    }

    return 0;
}
